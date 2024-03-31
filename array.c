//
// Created by 20220848 on 23/05/2023.
//

#include <stdio.h>
#include "figures.h"
#include"point.h"
#include<stdlib.h>
#include "Shape.h"
#include "area.h"
#include "array.h"
#include<stdio.h>
#include<stdlib.h>

Array* array_create(){
    Array* array = (Array*) malloc (sizeof(Array));
    array->size = 0;
    array->max_size = MAX_SIZE;
    return array;
}
void array_delete(Array* array){
    free (array);
}
unsigned int array_get_size_max(Array* array){
    return array->max_size;
}
unsigned int array_get_size(Array* array){
    return array->size;
}
void* array_get_element_at (Array* array, int pos){
    if(pos < array_get_size(array))
        return array->tab[pos];
    return NULL;
}
int array_insert_element (Array* array, void* element){
    if(array_get_size(array)>= array_get_size_max(array)) return -1;
    array->tab[array_get_size(array)] = element;
    array->size = array->size + 1;
    return array->size - 1;
}