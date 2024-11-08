#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

ssize_t custom_getline(char ** line, size_t * len, const char * inp) {
    if (inp == NULL) {
        return -1;
    }
    size_t len_line = strlen(inp);
    *line = malloc(sizeof(len_line+1));

    strcpy(*line, inp);
    return len_line;
}

int main() {
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;

    // Test case 1: Regular string input
    const char *test_str1 = "Hello, world!";
    nread = custom_getline(&line, &len, test_str1);
    assert(nread == strlen(test_str1));  // Check the number of characters read
    assert(strcmp(line, test_str1) == 0);  // Check if the string was copied correctly
    printf("Test 1 passed\n");

    // Test case 2: Empty string input
    const char *test_str2 = "";
    nread = custom_getline(&line, &len, test_str2);
    assert(nread == 0);  // Empty string should return 0
    assert(strcmp(line, test_str2) == 0);  // Check if the string was copied correctly
    printf("Test 2 passed\n");

    // Test case 3: NULL source
    nread = custom_getline(&line, &len, NULL);
    assert(nread == -1);  // NULL source should return -1
    printf("Test 3 passed\n");

    // Free allocated memory
    free(line);

    return 0;
}
