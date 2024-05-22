#include "../includes/pipex_bonus.h"

void    parent_action(t_pipex *core)
{
    int status;
    int pid;
    int i;

    i = 0;
    pid = waitpid(core->pids[i], &status, 0);
    while (pid > 0 && ++i)
        pid = waitpid(core->pids[i], &status, 0);
    destroy(core);
    exit(status >> 8);
}
