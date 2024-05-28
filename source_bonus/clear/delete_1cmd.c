/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_1cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysbai-jo <ysbai-jo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:29:09 by ysbai-jo          #+#    #+#             */
/*   Updated: 2024/05/28 14:29:10 by ysbai-jo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	delete_1cmd(t_cmd **lst)
{
	t_cmd	*tmp;

	if (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst);
		(*lst) = tmp;
	}
}