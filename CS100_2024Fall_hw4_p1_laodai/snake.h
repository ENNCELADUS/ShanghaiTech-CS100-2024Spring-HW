#ifndef SNAKE_H
#define SNAKE_H

#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <wchar.h>
#include <locale.h>
#include "utils.h"

#define MAX_FOODS 3
#define SEC_PER_SNAKE_MOVE 0.5
#define WIN_SCORE 10
#define NUM_ROWS 15
#define NUM_COLS 15
#define INIT_SNAKE_LEN 3
#define WALL_STR L"□ "
#define BODY_STR L"● "
#define FOOD_STR L"■ "
#define AIR_STR L"  "
#define HEAD_STR L"○ "

typedef struct
{
    int row;
    int col;
} Coord;

typedef enum
{
    Up,
    Left,
    Right,
    Down
} Direction;

typedef struct SnakeNode
{
    Coord pos;
    struct SnakeNode *next;
} SnakeNode;

typedef enum
{
    GS_Preparing,
    GS_Running,
    GS_Win,
    GS_Lose
} GameStatus;

typedef struct
{
    Coord pos;
} Food;

typedef struct
{
    GameStatus status;
    int score;
    int numRows;
    int numCols;
    SnakeNode *pSnakeHead;
    Food foods[MAX_FOODS];
    Direction currentDirection;
} Game;

Game createGame(void);
void printInitialGame(const Game *pGame);
void runGame(Game *pGame);
bool gameEnds(Game *pGame);
void destroyGame(Game *pGame);
SnakeNode *createSnake(const Game *pGame);
void destroySnake(SnakeNode *pHead);
Food createFood(const Game *pGame);
SnakeNode *createNewSnakeHead(const Game *pGame);
bool isFoodOnFoods(const Food foods[], const Food food);
bool isFoodOnSnake(const SnakeNode *pSnakeHead, const Food food);
bool snakeHitWall(const Game *pGame, SnakeNode *pNewHead);
bool snakeHitSelf(const Game *pGame, SnakeNode *pNewHead);
bool snakeDie(const Game *pGame, SnakeNode *pNewHead);
bool snakeEatFood(Game *pGame, SnakeNode *pNewHead);
void snakeMoveNormal(Game *pGame, SnakeNode *pNewHead);
void getSnakeMovement(Game *pGame);

#endif
