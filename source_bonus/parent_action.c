#include "../includes/pipex_bonus.h"

void    parent_action(t_pipex *core, int *status)
{
    int i;


    // seal_all_p(core->pipe, core);
    i = -1;
    while (core->pids[++i] != INT_MIN)
        waitpid(core->pids[i], status, 0);
    exit (*status << 8);
}
