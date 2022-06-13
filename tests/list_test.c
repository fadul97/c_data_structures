#include "../include/list.h"

//#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv)
{
    srand(time(NULL));

    SLListInt* first = NULL;

    if(!create_list(&first, 10))
    {
        printf("Failed to create list.\n");
        return 1;
    }

    printf("Inserting random values.\n");
    int n;
    for(int i = 0; i < 15; i++)
    {
        n = rand() % 100;
        insert_int(&first, n);
    }

    print_list(&first);

    destroy_list(&first);

    return 0;
}
