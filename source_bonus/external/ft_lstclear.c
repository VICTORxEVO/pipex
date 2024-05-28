/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysbai-jo <ysbai-jo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:37:32 by ysbai-jo          #+#    #+#             */
/*   Updated: 2024/05/28 09:13:23 by ysbai-jo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_lstclear(t_cmd **lst)
{
	t_cmd	*tm;

	if (!lst)
		return ;
	while ((*lst) != NULL)
	{
		tm = (*lst)->next;
		ft_lstdelone(*lst);
		*lst = tm;
	}
	*lst = NULL;
}
