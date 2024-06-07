/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_out.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysbai-jo <ysbai-jo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:29:02 by ysbai-jo          #+#    #+#             */
/*   Updated: 2024/06/07 09:54:58 by ysbai-jo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	check_fin_fout(t_pipex *core)
{
	char	*str;

	if (!core->i)
	{
		if (access(core->f_in, F_OK) || access(core->f_in, R_OK))
		{
			str = ft_strjoin("pipex: ", core->f_in, 'N', core);
			(destroy(core), peexit(str, 1, 'P', true));
		}
		core->in_fd = open(core->f_in, O_RDONLY);
		if (core->in_fd < 0)
		{
			str = ft_strjoin("pipex: ", core->f_in, 'N', core);
			(destroy(core), peexit(str, 1, 'P', true));
		}
	}
	else if (core->i == core->n_pipes)
	{
		core->out_fd = open(core->f_out, O_WRONLY | O_CREAT | O_TRUNC, 0666);
		if (core->out_fd < 0)
			(destroy(core), peexit(ft_strjoin("pipex: ", core->f_out, 'N',
						core), 1, 'P', true));
	}
}

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
