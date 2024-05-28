#include "pipex_bonus.h"

void	verify_cmd(char *path, char *cmd, t_pipex *core)
{
	if (access(path, F_OK))
		(destroy(core), peexit(ft_strjoin("pipex: ", cmd, 'N', core), 1, 'P',
				true));
	else if (access(path, X_OK))
		(destroy(core), peexit(ft_strjoin("pipex: ", cmd, 'N', core), 126, 'P',
				true));
	if (open(path, __O_DIRECTORY))
		(destroy(core), puterr("pipex: "), puterr(cmd),
			peexit(": Is a directory\n", 126, 'W', false));
}
