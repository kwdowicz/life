#include "life.h"
#include <stdio.h>


void calculateNextFrame(int initFrame[], int nextFrame[]) {
    for(int i = 0; i < TOTAL_CELLS; i++) {
        int row = (int)(i / GRID_SIZE);
        int col = i % GRID_SIZE;
        int n = (row > 0) ? initFrame[i-GRID_SIZE] : 0;
        int s = (row <= (GRID_SIZE - 2)) ? initFrame[i+GRID_SIZE] : 0;
        int w = (col > 0) ? initFrame[i-1] : 0;
        int e = (col <= (GRID_SIZE - 2)) ? initFrame[i+1] : 0;
        int ne = (row > 0 && col <= (GRID_SIZE - 2)) ? initFrame[i-(GRID_SIZE-1)] : 0;
        int nw = (row > 0 && col > 0) ? initFrame[i-(GRID_SIZE+1)] : 0;
        int se = (row <= (GRID_SIZE - 2) && col <= (GRID_SIZE - 2)) ? initFrame[i+GRID_SIZE+1] : 0;
        int sw = (row <= (GRID_SIZE - 2) && col > 0) ? initFrame[i+(GRID_SIZE-1)] : 0;
        int neighbours = n + s + w + e + ne + nw + se + sw;

        if(initFrame[i] == 1 && (neighbours < 2 || neighbours > 3)) nextFrame[i] = 0;
        if(initFrame[i] == 0 && (neighbours == 3)) nextFrame[i] = 1;
        if(initFrame[i] == 1 && (neighbours > 1 && neighbours < 4)) nextFrame[i] = 1;
        
        
        if((i % GRID_SIZE) == (GRID_SIZE - 1)) printf("\n");
    }
}

void printFrame(int frame[]) {
    for(int i = 0; i < TOTAL_CELLS; i++) {
        if(frame[i] == 0) {
            printf("%s", DEAD_CELL_SYMBOL);
        } else {
            printf("%s", LIVE_CELL_SYMBOL);
        }
        if((i % GRID_SIZE) == (GRID_SIZE - 1)) {
            printf("\n");
        }
    }
}