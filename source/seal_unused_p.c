#include "../includes/pipex.h"

static void seal_p(int fd, t_pipex *core)
{
    if (close(fd) < 0)
        (destroy(core), peexit("pipex", 1, 'P', false));
}

void    seal_unused_p(t_pipex *core)
{
    int i;
    i = -1;
    while (core->pipe[++i])
    {
        if ((core->i - 1 == i || !core->i)  || core->i == core->n_pipes)
            continue;
        seal_p(core->pipe[i][READ_SIDE], core);
    }
    i = -1;
    while (core->pipe[++i])
    {
        if (core->i == i || !core->i)
            continue;
        seal_p(core->pipe[i][WRITE_SIDE], core);
    }
}