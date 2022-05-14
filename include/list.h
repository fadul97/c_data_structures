#ifndef LIST_H
#define LIST_H

#include "types.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct list_int
{
    int value;
    struct list_int *next;
} list_int;

int create_list(data_type type);

#endif
