/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seal_all_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysbai-jo <ysbai-jo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:28:21 by ysbai-jo          #+#    #+#             */
/*   Updated: 2024/06/02 16:40:52 by ysbai-jo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	seal_all_p(int **pipes, t_pipex *core)
{
	int	i;

	i = -1;
	while (pipes[++i])
	{
		if (close(pipes[i][READ_SIDE]) || close(pipes[i][WRITE_SIDE]))
			(destroy(core), peexit("pipex :", 1, 'P', false));
	}
	if (!core->i)
	{
		if (close(core->in_fd))
			(destroy(core), peexit("pipex", 1, 'P', false));
	}
	else if (core->i == core->n_pipes)
	{
		if (close(core->out_fd))
			(destroy(core), peexit("pipex", 1, 'P', false));
	}
}
