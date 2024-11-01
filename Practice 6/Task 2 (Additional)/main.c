#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "array.h"

int main() {
    printf("\n");  
    int arr[10][10];
    srand(time(NULL));
    for (int i = 0; i<10; ++i) {
        for (int j = 0; j<10; ++j) {
            *(*(arr + i) + j) = rand() % 11;
        }
    } 
    printf("Array before changes: \n\n");
    print_array(arr);
    change_array(arr);
    printf("Array after changes: \n\n");
    print_array(arr);
    return 0;
