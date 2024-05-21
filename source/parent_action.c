#include "../includes/pipex.h"

void    parent_action(t_pipex *core)
{
    int status;
    waitpid(0, &status, 0);
    destroy(core);
    exit (status);
}
