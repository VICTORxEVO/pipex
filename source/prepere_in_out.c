#include "../includes/pipex.h"

void	prepere_in_out(t_pipex *core)
{
	if (!core->i)
		dup2fd(STDIN_FILENO, core->f_in, core),
            dup2fd(STDOUT_FILENO,core->pipe[core->i][WRITE_SIDE], core);
	else if (core->i == core->n_pipes)
		(dup2fd(STDIN_FILENO, core->pipe[core->i - 1][READ_SIDE], core),
			dup2fd(STDOUT_FILENO, core->f_out));
	else
		(dup2fd(STDIN_FILENO, core->pipe[core->i - 1][READ_SIDE], core),
			dup2fd(STDOUT_FILENO, core->pipe[core->i][WRITE_SIDE], core));
}
