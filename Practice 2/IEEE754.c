#include <stdio.h>
#include <float.h>
#include <math.h>



float input_handler()
{
    float inp = 0;
    printf("Write a float number: ");
    scanf("%f", &inp);
    return inp;
}


int signed_handler(int inp)
{
    if (inp > 0) {
        return 1;
    } else {
        return 0;
    }
}

int main()
{
    float input = input_handler();
    printf("hey %f\n\n", input);

    /* Signbit handler */
    if (signed_handler(input)) {
        printf("Signed bit: +\n");
    } else {
        printf("Signed bit: -\n");
    }

    /* Exponent handler */
    int exponent = ilogb(input);
    printf("Exponent: %i\n", exponent);

    /* Mantissa handler */
    float mantissa = input/scalbn(1.0, exponent) - 1;
    printf("Mantissa value: %f\n", mantissa);

    /* Return handler */
    printf("Reconstructed value: (%f + %f) + %i ** %i = %f\n",
    1.0, mantissa, 2, exponent, input);
    return 0;
}

