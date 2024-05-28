/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysbai-jo <ysbai-jo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:22:56 by ysbai-jo          #+#    #+#             */
/*   Updated: 2024/05/28 09:09:27 by ysbai-jo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_cmd	*ft_lstnew_cmd(char **cmd_and_args, char *str_cmd, t_pipex *core)
{
	t_cmd	*new;
	
	new = malloc_V1e2(sizeof(t_cmd), core);
	new->next = NULL;
	new->cmd_and_args = cmd_and_args;
	new->str_cmd = str_cmd;
	return (new);
}
