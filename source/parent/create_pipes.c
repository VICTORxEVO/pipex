/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pipes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysbai-jo <ysbai-jo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:28:16 by ysbai-jo          #+#    #+#             */
/*   Updated: 2024/05/28 14:34:13 by ysbai-jo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	create_pipes(t_pipex *core)
{
	int	i;

	core->pipe = malloc_v1e2(sizeof(int *) * (core->n_pipes + 1), core);
	core->pipe[core->n_pipes] = NULL;
	i = -1;
	while (++i < core->n_pipes)
	{
		core->pipe[i] = malloc_v1e2(sizeof(int) * 2, core);
		if (pipe(core->pipe[i]))
			(destroy(core), peexit("pipex: ", 1, 'P', false));
	}
}
