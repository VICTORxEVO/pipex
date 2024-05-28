/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysbai-jo <ysbai-jo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:27:44 by ysbai-jo          #+#    #+#             */
/*   Updated: 2024/05/28 14:36:19 by ysbai-jo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_lstdelone(t_cmd *node)
{
	free_2d((void **)node->cmd_and_args);
	free_2d((void **)node->duptfull_paths);
	free(node);
}
