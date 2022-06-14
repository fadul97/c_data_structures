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

bool remove_int(SLListInt** first, int value)
{
    if((*first) == NULL)
        return false;
    
    SLListInt* aux = (*first);
    SLListInt* previous = NULL;
    while((aux != NULL) && (aux->value != value))
    {
        previous = aux;
        aux = aux->next;
    }

    if(previous == NULL)
    {
        (*first) = aux->next;
        free(aux);
        return true;
    }
    else
    {
        if(aux == NULL)
        {
            printf("%d nao tem na lista.\n", value);
            return false;
        }
        else
        {
            printf("Cheguei, previous = %d e aux = %d\n", previous->value, aux->value);
            if(aux->next == NULL)
            {
                previous->next = NULL;
                free(aux);
                return true;
            }
            else
            {
                previous = aux->next;
                free(aux);
                return true;
            }
        }
    }
}

/*
bool remove_int2(SLListInt** first, int value)
{
    if((*first) == NULL)
        return false;
    
    SLListInt* aux = (*first);
    SLListInt* previous = NULL;
    while((aux->next != NULL) && (aux->value != value))
    {
        previous = aux;
        aux = aux->next;
    }

    if(previous == NULL)
    {
        (*first) = aux->next;
        free(aux);
        return true;
    }
    else
    {
        if(aux->next == NULL)
        {
            previous->next = NULL;
            free(aux);
            return true;
        }
        else
        {
            printf("Cheguei, previous = %d e aux = %d\n", previous->value, aux->value);
            if(aux->next == NULL)
            {
                previous->next = NULL;
                free(aux);
                return true;
            }
            else
            {
                previous = aux->next;
                free(aux);
                return true;
            }
        }
    }
}
*/

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
