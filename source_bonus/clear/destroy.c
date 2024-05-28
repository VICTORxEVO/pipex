/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysbai-jo <ysbai-jo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:29:15 by ysbai-jo          #+#    #+#             */
/*   Updated: 2024/05/28 14:29:17 by ysbai-jo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	free_2d(void **arr)
{
	int	i;

	if (!arr)
		return ;
	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}

void	destroy(t_pipex *core)
{
	free_2d((void **)core->path);
	ft_lstclear(&core->cmd);
	if (core->pids)
		free(core->pids);
	free_2d((void **)core->pipe);
}
