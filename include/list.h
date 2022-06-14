#ifndef LIST_H
#define LIST_H

#include "types.h"

// FIXME: Look for a better name!
// SLListInt = Singly Linked List for Int
typedef struct no
{
    int value;
    struct no* next;
} SLListInt;

bool create_list(SLListInt** first, int value);
bool insert_int(SLListInt** first, int value);
bool remove_int(SLListInt** first, int value);
//bool remove_int2(SLListInt** first, int value);
void print_list(SLListInt** first);
void destroy_list(SLListInt** first);

#endif
