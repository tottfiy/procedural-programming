#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

ssize_t custom_getline(char **line, size_t *len, const char *inp) {
    if (inp == NULL) {
        return -1; // Invalid input string
    }

    size_t temp_size = *len > 0 ? *len : 5; // Initial buffer size
    *line = malloc(temp_size);
    if (*line == NULL) {
        printf("Error while allocating memory.\n");
        return -1;
    }

    size_t pos = 0;

    while (*inp != '\0' && *inp != '\n') {
        if (pos + 1 >= temp_size) { // Resize buffer if needed
            temp_size *= 2;
            char *new_line = realloc(*line, temp_size);
            if (new_line == NULL) {
                printf("Error while reallocating memory.\n");
                free(*line);
                return -1;
            }
            *line = new_line;  // Don't free new_line here
        }

        (*line)[pos++] = *inp++;
    }

    if (*inp == '\n') { // Add newline character if present
        if (pos + 1 >= temp_size) {
            temp_size *= 2;
            char *new_line = realloc(*line, temp_size);
            if (new_line == NULL) {
                printf("Error while reallocating memory.\n");
                free(*line);
                return -1;
            }
            *line = new_line;  // Don't free new_line here
        }

        (*line)[pos++] = '\n';
    }

    (*line)[pos] = '\0'; // Null-terminate the string
    *len = temp_size;    // Update length
    return pos;          // Return number of characters read
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
    assert(line[0] == '\0');  // Check if the string was copied correctly
    printf("Test 2 passed\n");

    // Test case 3: NULL source
    nread = custom_getline(&line, &len, NULL);
    assert(nread == -1);  // NULL source should return -1
    printf("Test 3 passed\n");

    // Test case 4: custom len 
    len = 20;
    const char *test_str3 = "I am 24 characters long";
    nread = custom_getline(&line, &len, test_str3);
    assert(nread == strlen(test_str3));  
    assert(strcmp(line, test_str3) == 0);  // Check if the string was copied correctly
    printf("Test 4 passed\n");

    // Test case 5: 1 character string 
    const char *test_str4 = "O";
    nread = custom_getline(&line, &len, test_str4);
    assert(nread == strlen(test_str4));  
    assert(strcmp(line, test_str4) == 0);  // Check if the string was copied correctly
    printf("Test 5 passed\n");

    // Free allocated memory
    free(line);

    return 0;
}

