#include <iostream>
#define LENGTH 2
#define WIDTH 4

using namespace std;

void transpose ( const int input [][ WIDTH ], int output [][ LENGTH ]){
    for (int i=0; i < WIDTH; ++i){
        for (int k = 0; k < LENGTH; ++k){
            output[k][i] = input[i][k];
        }
    }
}

int main(){
    int myArray[2][4] = { {1,2,3,4}, {5,6,7,8} };
    int output[4][2];
    transpose(myArray, output);
}