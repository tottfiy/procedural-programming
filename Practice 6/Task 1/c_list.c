#include "c_list.h"
#include <stdio.h>

int append_list_item(void* list[], list_data_type list_type[], int size, void* item, list_data_type type) {
    list[size] = item;
    list_type[size] = type;
    size += 1;
    return size;
}

void print_list(const void* list[], const list_data_type list_type[], int size) {

    printf("List size = %d\n\n", size);

    for (int i=0; i<size; ++i){
        switch (list_type[i])
    {
    case int_type:
        printf("%d ", *(int*)list[i]);
        break;
    case float_type:
        printf("%f ", *(float*)list[i]);
        break;
    case string_type:
        printf("%s ", (char*)list[i]);
        break;

    }
    
    }
    
}
