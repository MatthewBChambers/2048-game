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

void left();
void moveleft();
void right();
void moveright();

int grid[4][4];

int main(){
    srand (time(NULL));
    int k = 0;
while (1) {
place();
    printgrid();
//left();
right();
printgrid();


printf("\n%d\n",k);
k++;

 if (k > 1000)
     exit(0);
}

}
//when left/right arrow key is hit, this method is called
//whcih makes use of the move method to alter values.
// 3,-1 right.  0,1 left.
void left(){

    //movement
    moveleft();

    //addition
    for (int f = 0; f < 4; f++) {

        for (int i = 0; i < 3 ; i ++) {
            printf("t");
            if (grid[f][i] == grid[f][i + 1]) {
                grid[f][i] *= 2;
                grid[f][i + 1] = 0;
            }
        }
    }

    //movement
    moveleft();


}
void moveleft(){
    //addition
    for (int f = 0; f < 4; f++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 3; k++) {
                if (grid[j][k] == 0 && grid[j][k+1] > 0) {
                    grid[j][k] = grid[j][k + 1];
                    grid[j][k + 1] = 0;
                }
            }
        }
    }
}

void right(){

    //movement
    moveright();

    //addition
    for (int f = 0; f < 4; f++) {

        for (int i = 3; i > 0 ; i--) {
            printf("t");
            if (grid[f][i] == grid[f][i - 1]) {
                grid[f][i] *= 2;
                grid[f][i - 1] = 0;
            }
        }
    }

    //movement
    moveright();


}

void moveright(){
    //addition
    for (int f = 0; f < 4; f++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 3; k > 0; k--) {
                if (grid[j][k] == 0 && grid[j][k-1] > 0) {
                    grid[j][k] = grid[j][k - 1];
                    grid[j][k - 1] = 0;
                }
            }
        }
    }
}


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
//srand (time(NULL)); moved to main

  /* generate  number 0 to 15: */
  int offput = rand()  % 16;
  printf("%d",offput);
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