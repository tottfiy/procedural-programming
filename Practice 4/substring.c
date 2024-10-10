#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_INPUT_SIZE 500

char* input_handler() {
    char* letter = malloc(MAX_INPUT_SIZE + 1);

    if (letter == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    printf("Enter original string (max %d characters):\n", MAX_INPUT_SIZE);
    fgets(letter, MAX_INPUT_SIZE + 1, stdin);
    letter[strcspn(letter, "\n")] = '\0';
    return letter;
}

char* sub_handler() {
    char* sub = malloc(MAX_INPUT_SIZE + 1);

    if (sub == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    printf("Enter substring (max %d characters):\n", MAX_INPUT_SIZE-450);
    fgets(sub, MAX_INPUT_SIZE + 1, stdin);
    sub[strcspn(sub, "\n")] = '\0';
    return sub;
}

void finder(char* word, char* subword) {
    char* index = strstr(word, subword);
    if (index != NULL) {
        printf("Substring found at index: %ld", index-word);
    }
    else {
        printf("Substring was not found.");
    }
}

int main() {
    char* word = input_handler();
    char* subword = sub_handler();
    finder(word,subword);
    free(word);
    free(subword);
}
