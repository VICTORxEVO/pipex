#include "../includes/pipex.h"

void    dup2fd(int newfd, int oldfd, t_pipex *core)
{
    if (dup2(oldfd, newfd) < 0)
        (destroy(core), peexit("pipex :", 1, 'P'));
}