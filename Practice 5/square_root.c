#include <string.h>
#include <stdio.h>

int input_square() {   
    int sqr;
    
    printf("Enter the number to find the square root of:\n");
    scanf("%d", &sqr);
    if (sqr <= 0) {
        printf("Can not find square of %d\n", sqr);
        return -1;
    } else {
        return sqr;
    }
}

float input_convergence() {   
    float conv;
    printf("Enter the tolerance for convergence (numbers after 0.): \n");    
    scanf("%f", &conv);
     if (conv <= 0) {
        printf("Tolerance cant be %f\n", conv);
        return -1;
    } else {
        return conv;
    }
}
double square_calc(int sqr, int conv) {
    double x = 1.0; 
    int i = 0;
    for (i; i < conv; ++i) {
        x = x - (x * x - sqr) / (2 * x);                      
    }
    printf("Number of iterations: %d\n", i);  
    printf("Square of %d is: %.11f\n", sqr, x);   
    return 0;
}
int main() {
    int sqr = input_square();
    if (sqr == -1){
        return 0;
    }
    int conv = input_convergence();
    if (conv == -1){
        return 0;
    }
    square_calc(sqr, conv);
}
