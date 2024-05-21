#include "../includes/pipex_bonus.h"

void    close_pipes(int **pipes, t_pipex *core, char flag)
{
    if (flag == 'P')
    {
        if (close(pipes[0][READ_SIDE]) < 0)
            (destroy(core), peexit("pipex", 1, 'P', false));
        if (close(pipes[1][WRITE_SIDE]) < 0)
            (destroy(core), peexit("pipex", 1, 'P', false));
        return;
    }
    if (close(pipes[1][READ_SIDE]) < 0)
        (destroy(core), peexit("pipex", 1, 'P', false));
}
