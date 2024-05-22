#include "../includes/pipex_bonus.h"

void    parent_cmd2(t_pipex *core)
{
    core->out_fd = open(core->f_out, O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (core->out_fd < 0)
        (destroy(core), peexit(ft_strjoin("pipex: ", core->f_out, 'N', core), 1, 'P', true));
    if (dup2(core->pipe[1][READ_SIDE], STDIN_FILENO) < 0)
        (destroy(core), peexit("pipex", 1, 'P', false));
    if (dup2(core->out_fd, STDOUT_FILENO) < 0)
        (destroy(core), peexit("pipex", 1, 'P', false));
    exec_cmd(core);
}
