/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_null_err.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysbai-jo <ysbai-jo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:29:59 by ysbai-jo          #+#    #+#             */
/*   Updated: 2024/06/02 16:36:25 by ysbai-jo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static char	*give_n_lines(t_pipex *core)
{
	char	*line;
	int		n_lines;
	int		fd;

	n_lines = 0;
	fd = open(core->f_in, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	while (line)
	{
		n_lines++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (ft_itoa(n_lines, core));
}

void	print_null_err(char *limiter, t_pipex *core)
{
	char	*n_lines;

	n_lines = give_n_lines(core);
	puterr("\npipex: warning: here-document at line ");
	(puterr(n_lines), free(n_lines));
	puterr(" delimited by end-of-file (wanted `");
	(puterr(limiter), puterr("')\n"));
}
