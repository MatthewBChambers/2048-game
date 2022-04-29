//
// Created by matth on 4/29/2022.
//
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <iostream>
#include <cstdio>
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include "twentyfortyeight.h"
using namespace std;
void printgrid();
void gameover();
void place();
int *getemptyloc();

int grid[4][4];

int main(){
while (1) {
place();
printgrid();
//Sleep(4);

}

}

void left

void printgrid() {
    printf("\n");
    for (int i = 0; i < 4; i++ ) {
        for (int z = 0; z < 4; z++) {
            printf("[ %d ] ",grid[i][z]);
        }
        printf("\n");
    }
}
void gameover(){
    printf("Game over!\n");
    exit(0);
}

void place(){
    int *r = getemptyloc();
    if (*r < 0)
        gameover();

    grid[*r][*(r+1)] = 2;

}

//returns a random empty space
//if returns -1, game is over, there is no free space
int *getemptyloc () {
srand (time(NULL));

  /* generate  number 0 to 15: */
  int offput = rand() % 16;
  for (int runtwlv = 0; runtwlv  < 16; runtwlv++) {
    for (int i = 0; i < 4; i++ ) {
        for (int z = 0; z < 4; z++ ) {
            if (grid[i][z] == 0) {
                if (offput == 0){
                int ar[2];
                ar[0] =i;
                ar[1] =z;
                int *r = ar;
                return r;
                } else offput--;
            }

        }
    }
    }
    int ar[2];
    ar[0] =-1;
    ar[1] =-1;
    int *r = ar;
    return r;
}