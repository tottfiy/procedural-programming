#include "array.h"
#include <stdio.h>

void print_array(int arr[10][10]) {
        for (int i = 0; i<10; ++i) {
            for (int j = 0; j<10; ++j) {
                printf("%d ", *(*(arr + i) + j));
            } printf("\n");
        } printf("\n");      
}   

void change_array(int arr[10][10]) {
    for (int i = 0; i<10; ++i) {
        for (int j = 0; j<10; ++j) 
        {
            if (*(*(arr+i)+j)==0) 
            {
                for (int k = 0; k<10; ++k) 
                {
                    if (*(*(arr+i)+k) != 0 )
                    {
                            *(*(arr+i)+k) = -1;
                    
                    }
                
                }
                for (int f = 0; f<10; ++f) 
                {
                    if (*(*(arr+f)+j) != 0 )
                    {
                            *(*(arr+f)+j) = -1;
                    }

                    
                    
                }

            }
        }
    }
    for (int i = 0; i<10; ++i) {
        for (int j = 0; j<10; ++j) {
            if (*(*(arr+i)+j)==-1) {
                *(*(arr+i)+j) = 0;
            }
        }

    }
}




