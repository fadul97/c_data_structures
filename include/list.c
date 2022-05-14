#include "list.h"


int create_list(data_type type)
{
    switch (type)
    {
    case INT_DATA:
        printf("Creating a list_int!\n");
        return 0;
        break;
    default:
        printf("Could not create unkown type.\n");
        return -1;
        break;
    }
}
