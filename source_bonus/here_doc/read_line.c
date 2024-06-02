/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysbai-jo <ysbai-jo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:30:12 by ysbai-jo          #+#    #+#             */
/*   Updated: 2024/06/02 18:13:32 by ysbai-jo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	open_tmp_file(t_pipex *core)
{
	core->f_in = ft_strdup("/tmp/here_doc.tmp");
	core->in_fd = open(core->f_in, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (core->in_fd < 0)
	{
		free(core->f_in);
		core->f_in = ft_strdup(".here_doc.tmp");
		core->in_fd = open(core->f_in, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (core->in_fd < 0)
			(destroy(core),
				peexit("pipex: here_doc: unable to create temporary file\n", 1,
					'W', false));
	}
	core->is_her_doc = true;
}

static char	handle_line(t_pipex *core, char *line)
{
	if (!line)
		return (-1);
	if (ft_strlen(line) - 1 == ft_strlen(core->limiter))
	{
		if (!ft_strncmp(line, core->limiter, ft_strlen(core->limiter)))
		{
			free(line);
			return (0);
		}
	}
	if (write(core->in_fd, line, ft_strlen(line)) < 0)
		(destroy(core), peexit("pipex", 1, 'P', false));
	free(line);
	return (1);
}

void	read_line(t_pipex *core)
{
	char	*line;
	char	res;

	open_tmp_file(core);
	write(1, "> ", 2);
	line = get_next_line(0);
	while (true)
	{
		res = handle_line(core, line);
		if (res == -1)
			break ;
		else if (res == 0)
			return ;
		else
		{
			write(1, "> ", 2);
			line = get_next_line(0);
		}
	}
	print_null_err(core->limiter, core);
}
