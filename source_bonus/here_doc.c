#include "../includes/pipex_bonus.h"

static void init_here_doc(t_pipex *core, char *f_out, char *env[], char *av[])
{
    core->f_out = f_out;
    core->env = env;
    core->n_cmd = 2;
    core->path = get_paths(env, core);
    core->cmd = get_cmds(core->n_cmd, av, core);
    core->pipe = malloc_V1e2(sizeof(int *) * 3, core);
    core->pipe[0] = malloc_V1e2(sizeof(int) * 2, core);
    core->pipe[1] = malloc_V1e2(sizeof(int) * 2, core);
    core->pipe[2] = NULL;
    if (pipe(core->pipe[0]))
        (destroy(core), peexit("pipex", 1, 'P', false));
    if (pipe(core->pipe[1]))
        (destroy(core), peexit("pipex", 1, 'P', false));
    core->pids = NULL;
}

void    here_doc(char *av[], t_pipex *core, char *env[])
{
    int pid;

    init_here_doc(core, av[3], env, av + 1);
    read_line(core, av[0]);
    pid = fork();
    if (pid < 0)
        (destroy(core), peexit("pipex", 1, 'P', false));
    if (!pid)
        child_cmd1(core);
    delete_1cmd(&core->cmd);
    close_pipes(core->pipe, core, 'P');
    parent_cmd2(core);
}
