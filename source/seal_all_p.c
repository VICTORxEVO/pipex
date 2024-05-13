#include "../includes/pipex.h"

void    seal_all_p(int **pipes, t_pipex *core)
{
    int i;

    i = -1;
    while (pipes[++i])
    {
        if (close(pipes[i][READ_SIDE]) || close(pipes[i][WRITE_SIDE]))
            (destroy(core), peexit("pipex :", 1, 'P', false));
    }
}