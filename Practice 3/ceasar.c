#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

int input_handler() {
    char letter;
    printf("Please, enter the letter: \n");
    scanf(" %c", &letter);
    letter = tolower(letter);

    if (isalpha(letter)) {
        return letter;
    } else {
        printf("Invalid input: must be a valid alphabetic character\n\n");
        return 0;
    }
}


int encryption(){
    srand(time(0));
    int min = -255;
    int max = 255;
    int randint = (rand() % (max - min + 1)) + min;
    printf("Generated encryption key: %d\n\n---------------------------------\n\n", randint);
    return randint;
}


int amount_handler(){
    char amount[50];
    int checker;
    printf("Enter the number of characters to encrypt: \n");
    scanf("%s",&amount);
    checker = atoi(amount);

    if (checker==0)
        {
            printf("Invalid input entered\n\n");
            return 0;
        }
    else
        {
            return checker;
        }

}

char caesar(int amount, int salt)
{
    for (int i = 0; i < amount; ++i)
    {
        char inp_letter = input_handler();
        if (inp_letter != 0)
        {
            int asciiValue = (int)inp_letter;
                int coded_letter = asciiValue + salt;
                while (coded_letter > 122)
                {
                    coded_letter = 97 + (coded_letter - 123);
                }
                while (coded_letter < 97)
                {
                    coded_letter = 122 - (96 - coded_letter);
                }

                char output = (char)coded_letter;
                printf("Encrypted character: %c\n\n", output);
        }
        else
        {
            i -= 1;
        }
    }
}

int main()
{
    int amount = amount_handler();
    if (amount == 0)
        {
            return 0;
        }
    else

        {
            int key = encryption();
            caesar (amount, key);
            return 0;
        }

}
