#include "../includes/pipex_bonus.h"

void    parent_action(t_pipex *core)
{
    // int i;
    int status;
    // i = -1;
    // while (core->pids[++i] != INT_MIN)
    waitpid(0, &status, 0);
    destroy(core);
    exit (status);
}
