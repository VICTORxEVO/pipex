#include "../includes/pipex.h"

char	*get_valid_path(t_pipex *core, char **duptfull_paths)
{
	char	*f_ok;
	char	*x_ok;
	char	*dup;

	f_ok = check_if_avail(core, duptfull_paths);
	x_ok = check_if_exec(core, f_ok);
	if (!x_ok && core->cmd->str_cmd[0] == 0)
		(destroy(core), peexit("pipex: '': command not found\n", 127, 'W',
				false));
	else if (!x_ok)
	{
		(destroy(core), puterr("pipex: "));
		peexit(ft_strjoin(core->cmd->str_cmd, ": command not found\n", 'L',
				core), 127, 'W', true);
	}
    return (x_ok);
}
