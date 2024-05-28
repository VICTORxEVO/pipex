/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_pipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysbai-jo <ysbai-jo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:30:03 by ysbai-jo          #+#    #+#             */
/*   Updated: 2024/05/28 14:30:05 by ysbai-jo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	close_pipes(int **pipes, t_pipex *core, char flag)
{
	if (flag == 'P')
	{
		if (close(pipes[0][READ_SIDE]) < 0)
			(destroy(core), peexit("pipex", 1, 'P', false));
		if (close(pipes[1][WRITE_SIDE]) < 0)
			(destroy(core), peexit("pipex", 1, 'P', false));
		return ;
	}
	if (close(pipes[1][READ_SIDE]) < 0)
		(destroy(core), peexit("pipex", 1, 'P', false));
}
