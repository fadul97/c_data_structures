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
SLListInt* get_first(SLListInt** first);
SLListInt* get_last(SLListInt** first);
void print_list(SLListInt** first);
void destroy_list(SLListInt** first);

#endif
