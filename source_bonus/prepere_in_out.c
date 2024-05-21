#include "../includes/pipex_bonus.h"

void	prepere_in_out(t_pipex *core)
{
	if (core->i == 0)
	{
		(dup2fd(core->in_fd, STDIN_FILENO, core),
            dup2fd(core->pipe[core->i][WRITE_SIDE], STDOUT_FILENO, core));
	}	
	else if (core->i > 0 && core->i < core->n_pipes)
	{
		(dup2fd(core->pipe[core->i - 1][READ_SIDE], STDIN_FILENO, core),
			dup2fd(core->pipe[core->i][WRITE_SIDE], STDOUT_FILENO, core));
	}
	else
	{
		(dup2fd(core->pipe[core->i - 1][READ_SIDE], STDIN_FILENO, core),
			dup2fd(core->out_fd, STDOUT_FILENO, core));
	}
		
}
