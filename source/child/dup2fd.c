/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup2fd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysbai-jo <ysbai-jo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:26:47 by ysbai-jo          #+#    #+#             */
/*   Updated: 2024/05/28 14:27:08 by ysbai-jo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	dup2fd(int oldfd, int newfd, t_pipex *core)
{
	if (dup2(oldfd, newfd) < 0)
		(destroy(core), peexit("pipex", 1, 'P', false));
}
