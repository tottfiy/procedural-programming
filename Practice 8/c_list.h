#ifndef C_LIST_H
#define C_LIST_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Enum to identify the data type (int, float, or string)
typedef enum {
int_type, // For integer values
float_type, // For float values
string_type // For string (char*) values
} list_data_type;

// Define the c_list structure with a named struct
typedef struct c_list {
    void** items; // Dynamic array of pointers to elements
    list_data_type* types; // Array of data types for each element
    size_t size; // Number of elements in the list
    size_t capacity; // Current capacity of the list
// Function pointers for list operations

// Append an element
void (*append)(struct c_list* list, void* item, list_data_type
type);
// Pop last element
void (*pop)(struct c_list* list);
// Free all memory
void (*destroy)(struct c_list* list);
// Print the list
void (*print)(const struct c_list* list);
} c_list;
// Find index of item
int (*find_index)(const struct c_list* list, void* item, list_data_type type);
// Insert item at position
void (*insert)(struct c_list* list, size_t pos, void* item, list_data_type type);

// Function declarations to initialize and manage the list
c_list* create_list(size_t initial_capacity);
void append(c_list* list, void* item, list_data_type type);


#endif // C_LIST_H