#include <stdio.h>
#include "bisection.h"

float bisection(float a1,float b1,float a2,float b2, float *x, float *y) {
     if (a1 == a2) {
        if (b1 == b2) {
            printf("Lines have infinite intersections\n");
            return 0;
        } else {
            printf("Lines dont intersect\n");
            return -1;
        }
    } else {
    *x = (b2 - b1) / (a1 - a2);
    *y = a1 * (*x) + b1;  

    return 1;
    }
}


