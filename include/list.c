#include "list.h"

#include <stdio.h>
#include <stdlib.h>


bool create_list(SLListInt** first, int value)
{
    if((*first) != NULL)
    {
        printf("First is not NULL.\n");
        return false;
    }

    SLListInt* aux = (SLListInt*)malloc(sizeof(SLListInt));
    aux->value = value;
    aux->next = NULL;

    if((*first) == NULL)
    {
        (*first) = aux;
        return true;
    }
    else
    {
        SLListInt* previous = (*first);
        while(previous != NULL)
        {
            previous = previous->next;
        }

        previous->next = aux;
    }

    return true;
}

bool insert_int(SLListInt** first, int value)
{
    if((*first) == NULL)
    {
        printf("First is NULL.\n");
        return false;
    }

    SLListInt* aux = (SLListInt*)malloc(sizeof(SLListInt));
    aux->value = value;
    aux->next = NULL;

    SLListInt* previous = (*first);
    while(previous->next != NULL)
    {
        previous = previous->next;
    }

    previous->next = aux;
}

void print_list(SLListInt** first)
{
    if((*first) == NULL)
        return;

    SLListInt* aux = (*first);
    while(aux->next != NULL)\
    {
        printf("[%d]->", aux->value);
        aux = aux->next;
    }
    printf("[%d]\n", aux->value);
}

void destroy_list(SLListInt** first)
{
    if((*first) == NULL)
        return;

    SLListInt* aux = (*first);
    SLListInt* delete = NULL;

    while(aux != NULL)
    {
        delete = aux;
        printf("Deleting value = %d\n", delete->value);
        aux = aux->next;
        free(delete);
    }       
}
