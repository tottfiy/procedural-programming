#include <stdio.h>

int converter(int dec) {
    int bin = 0;
    int i = 1;
    int counter = 0;
    int remainder;

    while (dec != 0) {
        counter + 1;
        remainder = dec % 2;
        dec /= 2;
        bin += remainder * i;
        i *= 10;

    }



    return bin;
}

void xor(int value, int key, int verbose)
{
    int encr = value^key;
    int decr = encr^key;

    if (verbose)
    {
        int val_bin = converter(value);
        int encr_bin = converter(encr);
        printf("\n\nOriginal value (Decimal): %d\nBinary: %d\n\nEncrypted value (Decimal): %d\nBinary: %d\n\nDecrypted value (Decimal): %d\nBinary: %d\n",
        value, val_bin, encr, encr_bin, decr, val_bin);
    }
    else
    {
        printf("\n\nOriginal value: %d\n\nEncrypted value: %d\n\nDecrypted value: %d\n",
        value, encr, decr);
    }
}



int value_scan()
{
    int value;
    printf("Enter a value: ");
    scanf("%d", &value);
    return value;
}

int key_scan()
{
    int key;
    printf("Enter a key: ");
    scanf("%d", &key);
    return key;
}
int verbose_scan()
{
    int verbose;
    printf("Turn on verbose mode? (display bits)\nPrint \"1\" for Yes and \"0\" for No: ");
    scanf("%d", &verbose);
    return verbose;
}

int main(void)
{
    int value = value_scan();
    int key = key_scan();
    int verbose = verbose_scan();
    xor(value, key, verbose);

}