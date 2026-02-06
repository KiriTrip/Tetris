#ifndef TETRIS_H
#define TETRIS_H

#include <stdlib.h>
#include <stdbool.h>

#define TYPE_TO_CELL(x) ((x)+1)

#define TC_EMPTY_STR " "
#define TC_BLOCK_STR "\u2588"

#define TC_IS_EMPTY(x) ((x) == TC_EMPTY)
#define TC_IS_FILLED(x) (!TC_IS_EMPTY(x))

#define TETRIS 4
#define NUM_TETROMINOS 7
#define NUM_ORIENTATIONS 4

#define MAX_LEVEL 19
#define LINES_PER_LEVEL 10

typedef enum
{
    TC_EMPTY, TC_CELLI, TC_CELLJ, TC_CELLL, TC_CELLO, TC_CELLS, TC_CELLT, TC_CELLZ
} tetris_cell;

typedef enum 
{
    TET_I, TET_J, TET_L, TET_O, TET_S, TET_T, TET_Z
} tetris_type;

typedef struct
{
    int row;
    int col;
} tetris_location;

typedef struct
{
    int typ;
    int ori;
    tetris_location loc;
} tetris_block;

typedef enum
{
    TM_LEFT, TM_RIGHT, TM_CLOCK, TM_COUNTER, TM_DROP, TM_HOLD, TM_NONE
} tetris_move;

typedef struct 
{
    int rows;
    int cols;
    char *board;

    int points;
    int level;

    tetris_block falling;
    tetris_block next;
    tetris_block stored;

    int ticks_till_gravity;
    int lines_remaining;
} tetris_game;

extern tetris_location TETROMINOS[NUM_TETROMINOS][NUM_ORIENTATIONS][TETRIS];
extern int GRAVITY_LEVEL[MAX_LEVEL+1];

void tg_init(tetris_game *obj, int rows, int cols);
tetris_game *tg_create(int rows, int cols);
void tg_destroy(tetris_game *obj);
void tg_delete(tetris_game *obj);
tetris_game *tg_load(FILE *f);
void tg_save(tetris_game *obj, FILE *f);

char tg_get(tetris_game *obj, int row, int col);
bool tg_check(tetris_game *obj, int row, int col);
bool tg_tick(tetris_game *obj, tetris_move move);
void tg_print(tetris_game *obj, FILE *f);

#endif