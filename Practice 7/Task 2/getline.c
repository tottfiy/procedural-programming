#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#ifndef ssize_t
typedef long ssize_t;  // Define ssize_t if not available
#endif

ssize_t custom_getline(char **lineptr, size_t *n, const char *source) {
    if (!source) {
        return -1;  // Error if the source is NULL
    }

    size_t len = strlen(source);
    
    // If lineptr is NULL or *lineptr is NULL, allocate memory
    if (lineptr == NULL || (lineptr && *lineptr == NULL)) {
        *lineptr = malloc(len + 1);  // Allocate space for the string + null terminator
        if (*lineptr == NULL) {
            return -1;  // Memory allocation failed
        }
        *n = len + 1;  // Set size
    } else if (*n < len + 1) {  // If the existing buffer is too small
        char *temp = realloc(*lineptr, len + 1);
        if (temp == NULL) {
            return -1;  // Memory reallocation failed
        }
        *lineptr = temp;
        *n = len + 1;  // Update size
    }

    // Copy the source string to lineptr
    strcpy(*lineptr, source);

    return len;  // Return the number of characters read
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
