#include "../includes/pipex_bonus.h"


int main(int ac, char *av[], char *env[])
{
    t_pipex core;
    int pid;
    
    parser(ac, av, &core, env);
    core.i = -1;
    while (++core.i < core.n_cmd)
    {
        pid = fork();
        if (pid < 0)
            (destroy(&core), peexit("pipex: ", 1, 'P', false));
        if (!pid)
            child_action(&core);
        else
        {
            core.pids[core.i] = pid;
            delete_1cmd(&core.cmd);
        }
    }
    seal_all_p(core.pipe, &core);
    core.pids[core.i] = INT_MIN;
    parent_action(&core);
}
