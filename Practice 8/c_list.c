// Creates a dynamic array and returns a pointer to it
// Returns NULL if memory allocation fails

c_list* create_list(size_t initial_capacity) {

}

// Appends a new element (int, float, or string) to the array
// Automatically resizes the array (realloc) and updates size
// Returns pointer to the reallocated memory
void (*append)(struct c_list* list, void* item, list_data_type type) {
\
}

// Removes the last element from the array and frees its memory
// Updates the size of the array accordingly
// Returns pointer to the reallocated memory
void (*pop)(struct c_list* list) {
    (*size)--;
    free(ptr[*size]);

    ptr = realloc(ptr, (*size) * sizeof(void*));
    type_array = realloc(type_array,(*size) * sizeof(list_data_type));
    return ptr;
}

// Prints all elements in the array based on their types (int, float, or string)
void (*print)(const struct c_list* list) {

}

void (*insert)(struct c_list* list, size_t pos, void* item, list_data_type type) {

}

int (*find_index)(const struct c_list* list, void* item, list_data_type type) {

}
// Frees all allocated memory for the array and its elements
void (*destroy)(struct c_list* list) {

}
