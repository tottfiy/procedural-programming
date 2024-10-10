#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 4

int fill(int matrix[N][N]){
    srand(time(0));

    for (int x = 0; x < N; ++x) {
        for (int y = 0; y < N; ++y) {
            matrix[x][y] = rand() % 100;
        }
    }
}

int rotate(int matrix[N][N]){
    for (int x = 0; x < N; ++x) {
        for (int y = 0; y < N; ++y) {
            matrix[x][y] = matrix[y][x];
        }
    }
}


void printout(int matrix[N][N]){
    for (int x = 0; x < N; ++x) {
        for (int y = 0; y < N; ++y) {
            printf("%d ", matrix[x][y]);
        }
        printf("\n");
    } printf("\n\n");

}

int main() {
    int matrix[N][N];
    fill(matrix);
    printf("Generated matrix(4x4): \n----------------------\n");
    printout(matrix);
    rotate(matrix);
    printf("Rotated matrix(4x4): \n--------------------\n");
    printout(matrix);
}