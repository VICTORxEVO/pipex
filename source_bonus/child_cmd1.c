#include "../includes/pipex_bonus.h"

void    child_cmd1(t_pipex *core)
{
    close_pipes(core->pipe, core, 'C');
    if (dup2(core->pipe[0][READ_SIDE], STDIN_FILENO) < 0)
        (destroy(core), peexit("pipex", 1, 'P', false));
    if (dup2(core->pipe[1][WRITE_SIDE], STDOUT_FILENO) < 0)
        (destroy(core), peexit("pipex", 1, 'P', false));
    exec_cmd(core);
}
