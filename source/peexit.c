#include "../includes/pipex.h"

void    peexit(char *msg, int exit_code, char flag, bool free_or_not)
{
    if (flag == 'P')
        perror(msg);
    else
        puterr(msg);
    if (free_or_not == true)
        free(msg);
    exit(exit_code);
}
