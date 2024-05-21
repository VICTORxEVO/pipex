#include "../../includes/pipex_bonus.h"

void    free_2d(void **arr)
{
    int i;

    if (!arr)
        return ;
    i = -1;
    while (arr[++i])
        free(arr[i]);
    free(arr);
}