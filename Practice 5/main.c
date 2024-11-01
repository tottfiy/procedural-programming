#include "bisection.h"
#include <stdio.h>

int main() {
    float a1, b1, a2, b2, x, y;

    printf("Enter coefficients for the first equation (a1 b1): ");
    scanf("%f %f", &a1, &b1);
    
    printf("Enter coefficients for the second equation (a2 b2): ");
    scanf("%f %f", &a2, &b2);
    

    bisection(a1, b1, a2, b2, &x, &y);
    printf("Intersection at x, y: (%.3f %.3f)\n", x, y);
    return 0;
}