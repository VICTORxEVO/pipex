/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysbai-jo <ysbai-jo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:22:56 by ysbai-jo          #+#    #+#             */
/*   Updated: 2024/05/07 13:35:48 by ysbai-jo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

t_cmd	*ft_lstnew_cmd(char *path, char **args, t_pipex *core)
{
	t_pipex	*new;
	bool res;
	
	new = malloc_V2(sizeof(t_pipex), core);
	new->cmd->next = NULL;
	new->cmd->cmd_p = path;
	new->cmd->cmd_args = args;
	res = ft_lstadd_back(&core->cmd, new);
	if (!res)
		(perror("pipex: malloc:"), destroy(core));
}
