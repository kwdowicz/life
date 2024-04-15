#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "life.h"

int main() {
    int initFrame[GRID_SIZE * GRID_SIZE] = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 1, 1, 1, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    };
    int nextFrame[GRID_SIZE * GRID_SIZE] = {0};
    printFrame(initFrame);
    for(int i = 0; i < ROUNDS; i++) {
        calculateNextFrame(initFrame, nextFrame);
        memcpy(initFrame, nextFrame, TOTAL_CELLS * sizeof(int));
        system("clear");
        printFrame(nextFrame);
        sleep(1);
    }
    return 0;
}