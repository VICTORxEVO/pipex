#include "pipex_bonus.h"

void	check_fin_fout(t_pipex *core)
{
	if (!core->i)
	{
		if (access(core->f_in, F_OK) || access(core->f_in, R_OK))
			(destroy(core), peexit(ft_strjoin("pipex: ", core->f_in, 'N', core),
					1, 'P', true));
        core->in_fd = open(core->f_in, O_RDONLY);
        if (core->in_fd < 0)
            (destroy(core), peexit(ft_strjoin("pipex: ", core->f_in, 'N', core),
					1, 'P', true));
	}
    else if (core->i == core->n_pipes)
	{
        core->out_fd = open(core->f_out, O_WRONLY | O_CREAT | O_TRUNC, 0666);
        if (core->out_fd < 0)
            (destroy(core), peexit(ft_strjoin("pipex: ", core->f_out, 'N', core),
					1, 'P', true));
	}
}
