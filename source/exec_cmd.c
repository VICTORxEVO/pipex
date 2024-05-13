#include  "../includes/pipex.h"

void	exec_cmd(t_pipex *core)
{
    char *valid_path;

    if (!core->cmd->duptfull_paths)
    {
        verify_cmd(core->cmd->cmd_and_args[0], core);
        execve(core->cmd->cmd_and_args[0], core->cmd->cmd_and_args, core->env);
    }
    else
    {
        valid_path = get_valid_path(core, core->cmd->duptfull_paths);
        execve(valid_path, core->cmd->cmd_and_args, core->env);
    }
    destroy(core);
    exit(EXIT_FAILURE);
}

