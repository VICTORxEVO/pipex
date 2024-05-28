/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seal_all_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysbai-jo <ysbai-jo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:30:39 by ysbai-jo          #+#    #+#             */
/*   Updated: 2024/05/28 14:44:05 by ysbai-jo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	seal_all_p(int **pipes, t_pipex *core)
{
	int	i;

	i = -1;
	while (pipes[++i])
	{
		if (close(pipes[i][READ_SIDE]) || close(pipes[i][WRITE_SIDE]))
			(destroy(core), peexit("pipex :", 1, 'P', false));
	}
}
