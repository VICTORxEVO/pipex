#include "pipex.h"

void	exec_cmd(t_pipex *core)
{
    char *valid_path;
    char *fail;

    if (!core->cmd->duptfull_paths)
    {
        verify_cmd(core->cmd->cmd_and_args[0], core->cmd->str_cmd, core);
        execve(core->cmd->cmd_and_args[0], core->cmd->cmd_and_args, core->env);
        if (open(core->cmd->cmd_and_args[0], __O_DIRECTORY))
		(puterr("pipex: "), puterr(core->cmd->str_cmd), destroy(core),
			peexit(": Is a directory\n", 126, 'W', false));
    }
    else
    {
        valid_path = get_valid_path(core, core->cmd->duptfull_paths);
        execve(valid_path, core->cmd->cmd_and_args, core->env);
    }
    fail = ft_strjoin("pipex: ", core->cmd->str_cmd, 'N', core);
    (destroy(core), peexit(fail, 1, 'P', true));
}

