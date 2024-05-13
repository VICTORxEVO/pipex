#include "../includes/pipex.h"

static char *check_if_avail(t_pipex *core, char **path)
{
    int i;

    i = -1;
    while (path[++i] && core->cmd->str_cmd[0])
    {
        if (!access(path[i], F_OK))
            return (path[i]);
    }
    return (NULL);
}

static char *check_if_exec(char *path, int *msg)
{

    *msg = 0;
    if (!access(path, X_OK))
        return (path);
    *msg = 4011;
    return (NULL);
}

char	*get_valid_path(t_pipex *core, char **duptfull_paths)
{
	char	*f_ok;
	char	*x_ok;
    int     msg;

	f_ok = check_if_avail(core, duptfull_paths);
	x_ok = check_if_exec(f_ok, &msg);
	if (!x_ok && core->cmd->str_cmd[0] == 0)
		(destroy(core), peexit("pipex: '': command not found\n", 127, 'W',
				false));
    else if (!x_ok && msg)
    {
        (destroy(core), puterr("pipex: "));
		peexit(ft_strjoin(core->cmd->str_cmd, ": permission denied\n", 'N',
				core), 127, 'W', true);
    }
	else if (!x_ok)
	{
		(destroy(core), puterr("pipex: "));
		peexit(ft_strjoin(core->cmd->str_cmd, ": command not found\n", 'N',
				core), 127, 'W', true);
	}
    return (x_ok);
}
