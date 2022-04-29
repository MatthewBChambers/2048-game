//
// Created by matth on 4/29/2022.
//

#include "twentyfortyeight.h"
int grid[4][4];
int main(){


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

//returns first empty space
//if returns -1, game is over, there is no free space
int *getemptyloc () {

    for (int i = 0; i < 4; i++ ) {
        for (int z = 0; z < 4; z++ ) {
            if (grid[i][z] == 0)
                return {i,z};
        }
    }
    return {-1,-1}
}