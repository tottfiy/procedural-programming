#include "c_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Creates a dynamic array and returns a pointer to it
// Returns NULL if memory allocation fails
list_data_type* type_array = NULL;

void** create() {
    void** array = (void**)malloc(sizeof(void*));
    type_array = (list_data_type*)malloc(sizeof(list_data_type));
    return array;
}

// Appends a new element (int, float, or string) to the array
// Automatically resizes the array (realloc) and updates size
// Returns pointer to the reallocated memory
void** append(void** ptr, int* size, void* item, list_data_type type) {
    (*size)++;
    ptr = realloc(ptr, (*size) * sizeof(void*));
    type_array = realloc(type_array,(*size) * sizeof(type));
    if (type==int_type) {
        int * int_ptr = malloc(sizeof(int));
        *int_ptr = *(int*)item;
        ptr[*size-1] = int_ptr;

    } else if (type==float_type) {
        float * flt_ptr = malloc(sizeof(float));
        *flt_ptr = *(float*)item;
        ptr[*size-1] = flt_ptr;

    } else if (type==string_type) {
        char * str_ptr = malloc(strlen((char*)item) + 1);
        strcpy(str_ptr, (char*)item);
        ptr[*size-1] = str_ptr;
    }
    type_array[*size - 1] = type;
    return ptr;
}

// Removes the last element from the array and frees its memory
// Updates the size of the array accordingly
// Returns pointer to the reallocated memory
void** pop(void** ptr, int* size){
    (*size)--;
    free(ptr[*size]);

    ptr = realloc(ptr, (*size) * sizeof(void*));
    type_array = realloc(type_array,(*size) * sizeof(list_data_type));
    return ptr;
}

// Prints all elements in the array based on their types (int, float, or string)
void print(const void** ptr, int size){
    for(int i = 0; i<size; ++i) {
        switch (type_array[i]) {
        case int_type: 
            printf("%d ", *(int*)ptr[i]);
            break;

        case float_type:
            printf("%f ", *(float*)ptr[i]);
            break;

        case string_type: 
            printf("%s ", (char*)ptr[i]);
            break;
        }


    }
    printf("\n");
}

// Frees all allocated memory for the array and its elements
void destroy(void** ptr, int size){
    for (int i = 0; i<size; ++i) {
        free(ptr[i]);
    }
    free(ptr);
    free(type_array);
}

