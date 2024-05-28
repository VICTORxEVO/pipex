/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent_action.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysbai-jo <ysbai-jo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:30:36 by ysbai-jo          #+#    #+#             */
/*   Updated: 2024/05/28 14:30:38 by ysbai-jo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	parent_action(t_pipex *core)
{
	int	status;
	int	i;

	i = -1;
	while (core->pids[++i] != INT_MIN)
		waitpid(core->pids[i], &status, 0);
	destroy(core);
	exit(status >> 8);
}
