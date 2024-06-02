/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent_action.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysbai-jo <ysbai-jo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:30:36 by ysbai-jo          #+#    #+#             */
/*   Updated: 2024/06/02 18:18:32 by ysbai-jo         ###   ########.fr       */
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
	if (core->is_her_doc)
	{
		if (unlink(core->f_in) == -1)
			(puterr("pipex: here_doc: warning: failed to remove "),
				puterr(core->f_in), puterr(" file\n"));
	}
	destroy(core);
	exit(status >> 8);
}
