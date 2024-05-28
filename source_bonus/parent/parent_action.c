#include "pipex_bonus.h"

void    parent_action(t_pipex *core)
{
    int status;
    int i;

    i = -1;
    while (core->pids[++i] != INT_MIN)
        waitpid(core->pids[i], &status, 0);
    destroy(core);
    exit(status >> 8);
}
