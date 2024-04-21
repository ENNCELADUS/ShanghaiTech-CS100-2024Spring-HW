#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

#define MAX_LEVEL 4

// To enable more ghosts, we will need to update our map file format.
#define MAX_GHOSTS 10
#define MS_PER_GHOST_TICK 500
#define MS_PER_TICK 20

typedef struct {
  int row;
  int col;
} Coord;

// Remark: Each enum item corresponds to an integer, starting from 0.
typedef enum { Up, Left, Idle, Right, Down } Direction;

Direction oppositeDirection(Direction dir) { return (Direction)(4 - dir); }

Coord moveOneStep(Coord from, Direction dir) {
  // Understand the trick here.
  // associated with the enum Direction.
  // when involving "up" and "down", row changes, column doesn't change. Vice versa.
  static const int rowDelta[] = {-1, 0, 0, 0, 1};
  static const int colDelta[] = {0, -1, 0, 1, 0};
  return (Coord){from.row + rowDelta[dir], from.col + colDelta[dir]};
}

typedef struct {
  Coord pos;
  Direction direction;
  char itemBelow;
} Ghost;

typedef enum { GS_Preparing, GS_Running, GS_Win, GS_Lose } GameStatus;

typedef struct {
  GameStatus status;
  int level;
  int score;

  int numRows;
  int numCols;
  int ghostCnt;
  int foodsCnt;

  Coord pacmanPos;

  Ghost ghosts[MAX_GHOSTS];

  char **grid;
} Game;

bool isWall(char c) { return c == 'B' || c == 'Y' || c == 'R' || c == 'G'; }

bool isFood(char c) { return c == '.'; }

bool isPacman(char c) { return c == 'C'; }

bool isGhost(char c) { return c == '@'; }


/**
 * @brief Create a Game object. Level information including the map is read from
 * the file @c mapFileName. Return the Game object created.
 *
 * @param level Level ID.
 * @param mapFileName Path to the map file.
 * @return Game The created Game object.
 */
Game createGame(int level, const char *mapFileName) {
  // Create a Game object. 
  FILE *file = fopen(mapFileName, "r");
  if (file == NULL) {
    perror("Error opening file");
    exit(EXIT_FAILURE);
  }


  Game game = {
    .level = level,
    .status = GS_Preparing,
    .score = 0,
  };

  // Get the num of rows, columns, and ghostCnt from file line 1
  fscanf(file, " %d %d %d", &game.numRows, &game.numCols, &game.ghostCnt);
  to_next_line(file);

  // Allocate memory for game.grid
  game.grid = (char **)malloc(game.numRows * sizeof(char *));
    for (int i = 0; i < game.numRows; i++) {
      game.grid[i] = malloc(game.numCols * sizeof(char));
      read_line(file, game.grid[i]);
      for (int j = 0; j < game.numCols; j++) {
        char c = game.grid[i][j];

        // Initialize the game by the char c we just got.
        switch (c) {
          case '.': // food
            game.foodsCnt++;
            break;
          case 'C': // Pacman
            game.pacmanPos = (Coord){.row = i, .col = j};
            break;
        }

        if (isdigit(c)) { // judge if c represents ghost
          game.grid[i][j] = '@';
          int ghostIndex = c - '0';
          if (ghostIndex >= 0 && ghostIndex < game.ghostCnt) {
            game.ghosts[ghostIndex].pos = (Coord){.row = i, .col = j};
            game.ghosts[ghostIndex].itemBelow = ' ';
          }
        }
      }
    }

    // Set the direction of the ghost, according to the last several lines.
    for (int i = 0; i < game.ghostCnt; i++){
      char directionStr[10];

      read_line(file, directionStr);

      Direction dir;
      if (strcmp(directionStr, "up") == 0) {
        dir = Up;
      } else if (strcmp(directionStr, "left") == 0) {
        dir = Left;
      } else if (strcmp(directionStr, "right") == 0) {
        dir = Right;
      } else if (strcmp(directionStr, "down") == 0) {
        dir = Down;
      }
      game.ghosts[i].direction = dir;
    }
    fclose(file);
    return game;
}

/**
 * @brief Destroy a Game object. Resources are released.
 *
 * @param pGame
 */
void destroyGame(Game *pGame) {
  for (int i = pGame->numRows - 1; i >= 0; --i)
    free(pGame->grid[i]);
  free(pGame->grid);
  // If your Game has some other resources, they should also be released.
}

void printInitialGame(const Game *pGame) {
  // Called at the beginning of 'runGame'.
  // Your 'createGame' should set the contents of 'grid' correctly to make this function work.
  clear_screen();
  for (int i = 0; i != pGame->numRows; ++i) {
    for (int j = 0; j != pGame->numCols; ++j) {
      switch (pGame->grid[i][j]) {
      case 'C': printf(BRIGHT_YELLOW_TEXT("C")); break;
      case 'B': printf(BLUE_TEXT("#")); break;
      case 'Y': printf(YELLOW_TEXT("#")); break;
      case 'R': printf(RED_TEXT("#")); break;
      case 'G': printf(GREEN_TEXT("#")); break;
      default: putchar(pGame->grid[i][j]); break;
      }
    }
    putchar('\n');
  }
  putchar('\n');
  printf("Level %d\n", pGame->level);
  assert(pGame->score == 0);
  printf("Score: 0\n");
  printf("Food remaining: %d\n", pGame->foodsCnt);
  printf("Pacman wants food! (control by w/a/s/d)\n");
}

void printScoreUpdate(const Game *pGame) {
  move_cursor(pGame->numRows + 2, 7);
  printf("%d          ", pGame->score);
}

void printFoodUpdate(const Game *pGame) {
  move_cursor(pGame->numRows + 3, 16);
  printf("%d          ", pGame->foodsCnt);
}

/**
 * @brief Move all the ghosts by one step. Their @c pos should be updated, and
 * the contents in @c pGame->grid and things printed on the screen should also
 * be updated.
 *
 * @param pGame Pointer to the current Game object.
 */
void moveOneGhost(Game *pGame, int ghostIndex);

// use loop to move all the ghosts
void moveGhosts(Game *pGame) {
  // Step 1: Display the items below the ghosts (Remove all the ghosts in reverse order (big number first))
  for (int i = pGame->ghostCnt - 1; i >= 0; i--) {
    int row = pGame->ghosts[i].pos.row;
    int col = pGame->ghosts[i].pos.col;
    pGame->grid[row][col] = pGame->ghosts[i].itemBelow;
    move_cursor(row, col);
    putchar(pGame->grid[row][col]);
  }

  // Step 2: Place all ghosts in new positions in positive sequence (small number first)
  for (int i = 0; i < pGame->ghostCnt; i++) {
    moveOneGhost(pGame, i);
  }
}

void moveOneGhost(Game *pGame, int ghostIndex) {
  Ghost *ghost = &pGame->ghosts[ghostIndex];

  // Current position
  int currentRow = ghost->pos.row;
  int currentCol = ghost->pos.col;

  // Next position
  Coord nextPos = moveOneStep(ghost->pos, ghost->direction);
  int nextRow = nextPos.row;
  int nextCol = nextPos.col;

  // Judge whether the next direction is ok?
  if (nextRow < 0 || nextRow >= pGame->numRows || nextCol < 0 || nextCol >= pGame->numCols || 
    isWall(pGame->grid[nextRow][nextCol])) {
    // If not ok, not move. Won't change grid. 
    ghost->direction = oppositeDirection(ghost->direction);
    move_cursor(currentRow, currentCol);
    putchar('@');
  }
  else {
    // If ok, move, update the grid.
    pGame->grid[currentRow][currentCol] = ghost->itemBelow;

    // Change the item of the place where the ghost moves to.
    ghost->itemBelow = pGame->grid[nextRow][nextCol];
    ghost->pos.row = nextRow;
    ghost->pos.col = nextCol;
    pGame->grid[nextRow][nextCol] = '@';
    // Print the item of the place where the ghost moves to.
    move_cursor(nextRow, nextCol);
    putchar('@');
  }
}

Direction getPacmanMovement(void) {
  if (kbhit()) {
    switch (getch()) {
    case 'w': return Up;
    case 's': return Down;
    case 'a': return Left;
    case 'd': return Right;
    }
  }
  // Note that 'Idle' is also returned when no keyboard hit occurs.
  return Idle;
}

bool pacmanDies(const Game *pGame);

/**
 * @brief Move the Pacman by one step, following the user's control obtained by
 * @c getPacmanMovement(). Pacman's position should be updated, and the contents
 * in @c pGame->grid and things printed on the screen should also be updated. If
 * the Pacman eats a food through this step, the related information stored and
 * printed should also be updated.
 *
 * @param pGame Pointer to the current Game object.
 */

void movePacman(Game *pGame) {
  // DONE: Implement this function.
  // Note that Pacman may be moved to a position containing a food or a ghost.
  // These cases should be handled carefully.

  // Get the current position of Pacman
  Direction dir = getPacmanMovement();
  int currentRow = pGame->pacmanPos.row;
  int currentCol = pGame->pacmanPos.col;

  // Next position
  Coord nextPos = moveOneStep(pGame->pacmanPos, dir);
  int nextRow = nextPos.row;
  int nextCol = nextPos.col;

  // Determine whether the next position is invalid (a wall or beyond the boundary)
  if (nextRow < 0 || nextRow >= pGame->numRows || nextCol < 0 || nextCol >= pGame->numCols || 
    isWall(pGame->grid[nextRow][nextCol])) {
    // If invalid, do nothing.
    return;
  }

  // Check for ghost encounters before actually moving Pacman 
  // If true, then the only clear original location(remove Pacman)
  pGame->pacmanPos.row = nextRow;
  pGame->pacmanPos.col = nextCol;
  if (pacmanDies(pGame)) {
    // Clear original location
    pGame->grid[currentRow][currentCol] = ' '; 
    move_cursor(currentRow, currentCol);
    putchar(pGame->grid[currentRow][currentCol]);
    return; 
  }

  // If next position is food '.'
  if (pGame->grid[nextRow][nextCol] == '.') {
    pGame->score += 10;
    printScoreUpdate(pGame);
    pGame->foodsCnt--;
    printFoodUpdate(pGame);
  }

  // Move Pacman to the new position
  pGame->pacmanPos = nextPos;

  pGame->grid[currentRow][currentCol] = ' ';
  move_cursor(currentRow, currentCol);
  putchar(' '); 

  pGame->grid[nextRow][nextCol] = 'C';
  move_cursor(nextRow, nextCol);
  printf(BRIGHT_YELLOW_TEXT("C"));
}


/**
 * @brief Test if Pacman has died.
 */
bool pacmanDies(const Game *pGame) {
  // Done: Implement this function.
  return isGhost(pGame->grid[pGame->pacmanPos.row][pGame->pacmanPos.col]);
}

/**
 * @brief Test if the game has ended. If so, update the @c status and return
 * true; otherwise return false.
 *
 * @param pGame Pointer to the current Game object.
 */
bool gameEnds(Game *pGame) {
  if (pacmanDies(pGame)) {
    pGame->status = GS_Lose;
    return true;
  }
  if (pGame->foodsCnt == 0) {
    pGame->status = GS_Win;
    return true;
  }
  return false;
}

void runGame(Game *pGame) {
  printInitialGame(pGame);
  pGame->status = GS_Running;
  int ticks = 0;
  while (1) {
    sleep_ms(MS_PER_TICK);
    ++ticks;
    movePacman(pGame);
    if (gameEnds(pGame))
      break;
    if (ticks == MS_PER_GHOST_TICK / MS_PER_TICK) {
      ticks = 0;
      --pGame->score;
      printScoreUpdate(pGame);
      moveGhosts(pGame);
      if (gameEnds(pGame))
        break;
    }
  }
}

void runLevel(int level) {
  char path[100];
  sprintf(path, "maps/level%d.txt", level);
  Game game = createGame(level, path);
  runGame(&game);
  assert(game.status == GS_Lose || game.status == GS_Win);
  move_cursor(game.numRows + 4, 0);
  if (game.status == GS_Lose)
    printf("Pacman dies!");
  else
    printf("You win!");
  printf("                                       \n");
  destroyGame(&game);
}

int main(void) {
  prepare_game();
  // DONE: Run more levels?
  int currentLevel = 0;
  char choice = '\0';

  do {
    runLevel(currentLevel);
    printf("Press r to retry this level.\n");
    printf("Press p to play previous level.\n");
    printf("Press n to play next level.\n");
    printf("Feeling tired? Press q anytime to take a break.\n");

    do {
      if (kbhit()){
        choice = getch();
      }
    } while (choice != 'r' && choice != 'p' && choice != 'n' && choice != 'q');  

    switch (choice) {

      case 'r': // Just loop again without changing currentLevel
        choice = '\0';
        break;

      case 'p': // Proceed to the previous level
        if (currentLevel > 0) {
          currentLevel--;
        }
        else if (currentLevel == 0){
          printf("You are already at the first level. There's no previous level to go back to!\n");
          sleep_ms(2000);
        }
        choice = '\0';
        break;

      case 'n': // Proceed to the next level
        currentLevel++;
        if (currentLevel > MAX_LEVEL){
          printf("Congratulations! You have completed all levels.\n");
          sleep_ms(2000);
          exit(0);
        }
        choice = '\0';
        break;

      case 'q': // Quit the game
        printf("Thanks for playing!\n");
        sleep_ms(2000);
        exit(0);
        break;
    }
  } while (choice != 'q');
  return 0;
}