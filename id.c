//
// Created by 20220848 on 18/04/2023.
//

#include "id.h"

extern unsigned int global_id = 0;
unsigned int get_next_id(){
    return ++global_id;
}


