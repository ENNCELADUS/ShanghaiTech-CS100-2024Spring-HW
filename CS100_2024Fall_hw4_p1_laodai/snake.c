#include "snake.h"

/**
 * @brief Set the number of score, rows, columns and the initial direction.
 *
 * @param status The status of the game.
 * @param score The score of the game.
 * @param numRows The number of rows in the game.
 * @param numCols The number of columns in the game.
 * @param currentDirection The direction of snake at the current frame.
 * @return The created Game object.
 */
Game createGame(void)
{
    Game game = {
        .status = GS_Preparing,
        .score = 0,
        .numRows = NUM_ROWS,
        .numCols = NUM_COLS,
        .currentDirection = Up,
    };
    game.pSnakeHead = createSnake(&game);
    // initialize foods position
    for (int i = 0; i < MAX_FOODS; i++)
    {
        game.foods[i].pos.row = -1;
        game.foods[i].pos.col = -1;
    }
    // Create foods.
    for (int i = 0; i < MAX_FOODS; i++)
    {
        game.foods[i] = createFood(&game);
    }

    return game;
}

void printInitialGame(const Game *pGame)
{
    // Clear the screen first.
    clear_screen();

    // Draw the walls.
    for (int i = 0; i < pGame->numRows; i++)
    {
        for (int j = 0; j < pGame->numCols; j++)
        {
            if (i == 0 || i == pGame->numRows - 1 || j == 0 || j == pGame->numCols - 1)
            {
                wprintf(WALL_STR);
            }
            else
            {
                wprintf(AIR_STR);
            }
        }
        wprintf(L"\n");
    }

    // Draw the snake.
    SnakeNode *pcur = pGame->pSnakeHead;
    move_cursor(pcur->pos.row, 2 * pcur->pos.col);
    wprintf(HEAD_STR);
    pcur = pcur->next;
    while (pcur != NULL)
    {
        move_cursor(pcur->pos.row, 2 * pcur->pos.col);
        wprintf(BODY_STR);
        pcur = pcur->next;
    }

    // Draw the food
    for (int i = 0; i < MAX_FOODS; i++)
    {
        move_cursor(pGame->foods[i].pos.row, 2 * pGame->foods[i].pos.col);
        wprintf(FOOD_STR);
    }

    // Print the prompt
    move_cursor(pGame->numRows + 1, 0);
    wprintf(L"Snake needs food! (control by w/a/s/d)\n");

    // Print the score
    move_cursor(pGame->numRows + 2, 0);
    wprintf(L"Score: %d", pGame->score);
}

/**
 * @brief Create a snake with INIT_SNAKE_LENGTH length.
 * @param pGame The pointer that points to the object Game.
 * @return The head of the snake, which should be a pointer of type SnakeNode.
 */
SnakeNode *createSnake(const Game *pGame)
{
    // Done
    // Create "a snake" with INIT_SNAKE_LENGTH length. Every member
    // of the your "snake" should be correctly set. Your should pay
    // attention to the correctness of the connection between every snake nodes.

    SnakeNode *headNode = malloc(sizeof(SnakeNode));
    headNode->pos.row = pGame->numRows / 2;
    headNode->pos.col = pGame->numCols / 2;
    headNode->next = NULL;
    SnakeNode *pcur = headNode;
    for (int i = 1; i < INIT_SNAKE_LEN; i++)
    {
        SnakeNode *newNode = malloc(sizeof(SnakeNode));
        *newNode = (SnakeNode){.pos.row = headNode->pos.row + i,
                               .pos.col = headNode->pos.col,
                               .next = NULL};
        pcur->next = newNode;
        pcur = newNode;
    }
    // from "Draw the snake" in line 60

    return headNode;
}

Food createFood(const Game *pGame)
{
    Food food;
    do
    {
        food.pos.row = rand() % (NUM_ROWS - 2) + 1;
        food.pos.col = rand() % (NUM_COLS - 2) + 1;
    } while (isFoodOnSnake(pGame->pSnakeHead, food) || isFoodOnFoods(pGame->foods, food));
    return food;
}

/**
 * @brief Get the input from the keyboard; change the moving direction of
 * the snake.
 * @param pGame The pointer to the object Game.
 */
void getSnakeMovement(Game *pGame)
{
    // Done
    // The function will obtain an input char from keyboard, which
    // will be returned by getch(). According to defferent input, you
    // should do something to change the direction of the snake.
    // Ignore the case when the input is opposite from the current moving direction.

    if (kbhit())
    {
        switch (getch())
        {
        case 'w':
            pGame->currentDirection = Up;
            break;
        case 's':
            pGame->currentDirection = Down;
            break;
        case 'a':
            pGame->currentDirection = Left;
            break;
        case 'd':
            pGame->currentDirection = Right;
            break;
        default:
            break;
        }
    }
}

/**
 * @brief create a new invisible snakehead according to the current direction.
 * @return A pointer to SnakeNode that represents the new snake head.
 */
SnakeNode *createNewSnakeHead(const Game *pGame)
{
    // Done
    // Generate an invisible vitual snake head, which will be used
    // to do some collision detections.
    // Note: You can use malloc to allocate memory. Make sure to free
    // them AT THE RIGHT TIME.
    SnakeNode *newHead = malloc(sizeof(SnakeNode));
    newHead->pos = pGame->pSnakeHead->pos;
    newHead->next = NULL;
    switch (pGame->currentDirection)
    {
    case Up:
        newHead->pos.row -= 1;
        break;
    case Down:
        newHead->pos.row += 1;
        break;
    case Left:
        newHead->pos.col -= 1;
        break;
    case Right:
        newHead->pos.col += 1;
        break;
    default:
        break;
    }

    return newHead;
}

/**
 * @brief Check if the snake hits the wall.
 * @return True if the new head is out of the wall.
 */
bool snakeHitWall(const Game *pGame, SnakeNode *pNewHead)
{
    // Done.
    if (pNewHead->pos.row <= 0 ||
        pNewHead->pos.row >= pGame->numRows - 1 ||
        pNewHead->pos.col <= 0 ||
        pNewHead->pos.col >= pGame->numCols - 1)
        return true;

    return false;
}

/**
 * @brief Check if the snake hits itself.
 * @return True if the new head hit the snake itself.
 */
bool snakeHitSelf(const Game *pGame, SnakeNode *pNewHead)
{
    // traverse
    for (SnakeNode *cur = pGame->pSnakeHead; cur != NULL; cur = cur->next)
    {
        if (cur->pos.row == pNewHead->pos.row && cur->pos.col == pNewHead->pos.col)
        {
            return true;
        }
    }
    return false;
}

/**
 * @brief Check if the snake crushed on obstacles. If so, the status of the
 * game should be set to lose.
 * @return True if the new head crushed on obstables.
 */
bool snakeDie(const Game *pGame, SnakeNode *pNewHead)
{
    // Done: Implement this function. Your design should be simple, a single line will be enough.
    return snakeHitWall(pGame, pNewHead) || snakeHitSelf(pGame, pNewHead);
}

/**
 * @brief Check if the snake eats the food. If so, make a new food and make the head appear and append the new head,
 * then increase the score.
 * @return True if the snake eats the food.
 */
bool snakeEatFood(Game *pGame, SnakeNode *pNewHead)
{
    for (int i = 0; i < MAX_FOODS; i++)
    {
        if (pNewHead->pos.row == pGame->foods[i].pos.row &&
            pNewHead->pos.col == pGame->foods[i].pos.col)
        {

            move_cursor(pNewHead->pos.row, 2 * pNewHead->pos.col);
            wprintf(HEAD_STR);
            move_cursor(pGame->pSnakeHead->pos.row, 2 * pGame->pSnakeHead->pos.col);
            wprintf(BODY_STR); // Draw the snake.line 60

            pNewHead->next = pGame->pSnakeHead;
            pGame->pSnakeHead = pNewHead; // from linkedlist

            pGame->foods[i] = createFood(pGame);
            move_cursor(pGame->foods[i].pos.row, 2 * pGame->foods[i].pos.col);
            wprintf(FOOD_STR); // line 73

            pGame->score += 1;

            move_cursor(pGame->numRows + 2, 0); // line 84
            wprintf(L"Score: %d", pGame->score);

            return true;
        }
    }
    return false;
}

/**
 * @brief Check if the food is on the snake.
 * @return True if the food is on the snake, false otherwise.
 */
bool isFoodOnSnake(const SnakeNode *pSnakeHead, const Food food)
{
    // Done
    const SnakeNode *pcur = pSnakeHead;
    while (pcur != NULL)
    {
        if (pcur->pos.row == food.pos.row && pcur->pos.col == food.pos.col)
        {
            return true;
        }
        pcur = pcur->next;
    }
    return false;
}

/**
 * @brief Check if the food is on the foods.
 * @return True if the food is on the foods, false otherwise.
 */
bool isFoodOnFoods(const Food foods[], const Food food)
{
    // Done.
    for (int i = 0; i < MAX_FOODS; i++)
    {
        if (foods[i].pos.row == food.pos.row && foods[i].pos.col == food.pos.col)
        {
            return true;
        }
    }
    return false;
}

/**
 * @brief Move the snake by one step.
 *
 */
void snakeMoveNormal(Game *pGame, SnakeNode *pNewHead)
{
    // Hint: If the snake does not hit the wall or itself or eat the food, just append the new head and remove the tail
    // should work. Note that the check procedure have been done in the function runGame().
    move_cursor(pNewHead->pos.row, 2 * pNewHead->pos.col);
    wprintf(HEAD_STR);
    move_cursor(pGame->pSnakeHead->pos.row, 2 * pGame->pSnakeHead->pos.col);
    wprintf(BODY_STR); // Draw the snake.line 60

    pNewHead->next = pGame->pSnakeHead;
    pGame->pSnakeHead = pNewHead; // from linkedlist

    SnakeNode *node = pGame->pSnakeHead;
    while (node->next->next)
    {
        node = node->next;
    }
    move_cursor(node->next->pos.row, 2 * node->next->pos.col);
    wprintf(AIR_STR);

    free(node->next);
    if (node->next != NULL)
    {
        node->next = NULL;
    }
}

/**
 * @brief Destroy the snake, free all the nodes of the snake.
 */
void destroySnake(SnakeNode *pHead)
{
    // Done: Free one by one.
    SnakeNode *toDestroy = pHead;
    while (toDestroy != NULL)
    {
        SnakeNode *snake = toDestroy->next;
        free(toDestroy);
        toDestroy = snake;
    }
}

/**
 * @brief Destroy the game.
 */
void destroyGame(Game *pGame)
{
    // Done: free all dynamic allocation
    destroySnake(pGame->pSnakeHead);
}

bool gameEnds(Game *pGame)
{
    if (pGame->status == GS_Lose)
    {
        move_cursor(pGame->numRows + 2, 0);
        wprintf(L"Game Over! Your score is %d\n", pGame->score);
        return true;
    }
    if (pGame->score == WIN_SCORE)
    {
        pGame->status = GS_Win;
        move_cursor(pGame->numRows + 2, 0);
        wprintf(L"Congratulations! You win!\n");
        return true;
    }
    return false;
}

void runGame(Game *pGame)
{
    // Check if the terminal size is too small.
    if (is_terminal_size_small(NUM_ROWS, NUM_COLS))
    {
        return;
    }
    // Print the frame and initial snake and food.
    printInitialGame(pGame);
    pGame->status = GS_Running;
    clock_t lastSnakeMoveTime = clock();
    while (1)
    {
        exit_on_sigint();
        if (gameEnds(pGame))
            break;
        getSnakeMovement(pGame);
        clock_t currentTime = clock();
        if ((double)(currentTime - lastSnakeMoveTime) / CLOCKS_PER_SEC >=
            SEC_PER_SNAKE_MOVE)
        {
            lastSnakeMoveTime = currentTime;
            if (gameEnds(pGame))
                break;

            // Create a new invisible head which is the next one step
            // forward, and check if the snake hits the wall or itself,
            // but you should not make it appear if it hits the wall or itself.
            SnakeNode *pNewHead = createNewSnakeHead(pGame);

            if (snakeDie(pGame, pNewHead))
            {
                // If the snake hits the wall or itself,
                // free the new head and end the game.
                // The operations should be handled in related functions but not here.
                pGame->status = GS_Lose;
                free(pNewHead);
            }
            else if (!snakeEatFood(pGame, pNewHead))
            {
                // If the snake eats the food, make the head appear
                // and append the new head, meanwhile increase the score.
                // The operations should be handled in snakeEatFood() but not here.

                // If snake didn't eat a food, we should move the snake,
                // and the operations should be handled in snakeMoveNormal().
                snakeMoveNormal(pGame, pNewHead);
            }
        }
    }
}

int main(void)
{
    setlocale(LC_ALL, "");
    prepareGame();
    Game game = createGame();
    runGame(&game);
    destroyGame(&game);
    return 0;
}
