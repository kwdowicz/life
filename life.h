#ifndef LIFE_H
#define LIFE_H

#define GRID_SIZE 10
#define TOTAL_CELLS (GRID_SIZE * GRID_SIZE)
#define ROUNDS 10000
#define LIVE_CELL_SYMBOL "\U0001F7E9"
#define DEAD_CELL_SYMBOL "\U00002B1C"

void printFrame(int frame[]);
void calculateNextFrame(int initFrame[], int nextFrame[]);

#endif