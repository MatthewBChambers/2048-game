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
#include <cstdlib>
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include "twentyfortyeight.h"
#include <fstream>

using namespace std;
void printgrid();
void gameover();
void place();
int *getemptyloc();

void left();
void moveleft();
void right();
void moveright();
void up();
void moveup();
void down();
void movedown();
int grid[4][4];

int main(){
    srand (time(NULL));
    int k = 0;
/*
    while(1){
        if(GetAsyncKeyState(VK_UP)) {
            up();
            Sleep(2000);
            GetAsyncKeyState(VK_UP);
            break;
        }
    }*/
while (1) {
place();
    printf("\n\n\n\n\n\n\n\n\n\n\n\n");
    printgrid();

    while(1){
        if(GetAsyncKeyState(VK_UP)) {
            up();
            Sleep(500);
            GetAsyncKeyState(VK_UP);
            break;
        }
        if(GetAsyncKeyState(VK_DOWN)) {
            down();
            Sleep(500);
            GetAsyncKeyState(VK_DOWN);
            break;
        }
        if(GetAsyncKeyState(VK_RIGHT)) {
            right();
            Sleep(500);
            GetAsyncKeyState(VK_RIGHT);
            break;
        }
        if(GetAsyncKeyState(VK_LEFT)) {
            left();
            Sleep(500);
            GetAsyncKeyState(VK_LEFT);
            break;
        }
    }

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

void up(){

    //movement
    moveup();

    //addition
    for (int f = 0; f < 4; f++) {

        for (int i = 0; i < 3 ; i++) {
            printf("t");
            if (grid[i][f] == grid[i + 1][f]) {
                grid[i][f] *= 2;
                grid[i + 1][f] = 0;
            }
        }
    }

    //movement
    moveup();


}
void moveup(){
    for (int f = 0; f < 4; f++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 3; k++) {
                if (grid[k][j] == 0 && grid[k+1][j] > 0) {
                    grid[k][j] = grid[k + 1][j];
                    grid[k+1][j] = 0;
                }
            }
        }
    }
};

void down(){

    //movement
    movedown();

    //addition
    for (int f = 0; f < 4; f++) {

        for (int i = 3; i > 0 ; i--) {
            printf("t");
            if (grid[i][f] == grid[i - 1][f]) {
                grid[i][f] *= 2;
                grid[i - 1][f] = 0;
            }
        }
    }

    //movement
    movedown();


}
void movedown(){
    for (int f = 0; f < 4; f++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 3; k > 0; k--) {
                if (grid[k][j] == 0 && grid[k-1][j] > 0) {
                    grid[k][j] = grid[k - 1][j];
                    grid[k-1][j] = 0;
                }
            }
        }
    }
};

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