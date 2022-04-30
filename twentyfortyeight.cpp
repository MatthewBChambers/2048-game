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
int *move(int);
void left();

int grid[4][4];

int main(){
    int k = 0;
while (1) {
place();
    left();
printgrid();


printf("\n%d\n",k);
k++;

 if (k > 1000)
     exit(0);
}

}
//when left arrow key is hit, this method is called
//whcih makes use of the move method to alter values.
void left(){
    for (int i = 0; i < 4; i++ ) {
            /*int array[4];
            array[0] = grid[i][0];
            array[1] = grid[i][2];
            array[2] = grid[i][3];
            array[3] = grid[i][4];

            move(&array);
            printf("\n%d  %d  %d  %d",array[0],array[1],array[2],array[3]);*/
            int array[] = {grid[i][0], grid[i][1], grid[i][2], grid[i][3]};
            int *R = array;
            R = move(R);
            for (int f = 0; f < 4; f++) {
                grid[i][f] = *(R+f);
            }
    }
}
//computes combinations and moves things to the front of the array.
int *move(int *u){
    //add
    for (int f = 0; f < 3; f++) {
        if (*(u+f) == *(u+f+1)){
            *(u+f) *= 2;
            *(u+f+1) = 0;
        }
    }

    //move
    for (int j = 0; j < 4; j++) {
        for (int k = 0; k < 3; k++) {
            if (*(u+k)==0 && *(u+k+1)!=0) {
                *(u+k) = *(u+k+1);
                *(u+k+1) = 0;
            }
        }
    }
    return u;
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