/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_v1e2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysbai-jo <ysbai-jo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:35:19 by ysbai-jo          #+#    #+#             */
/*   Updated: 2024/06/02 18:23:27 by ysbai-jo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	*malloc_v1e2(size_t size, t_pipex *core)
{
	void	*data;

	data = malloc(size);
	if (!data)
		(perror("pipex: malloc"), destroy(core));
	return (data);
}
