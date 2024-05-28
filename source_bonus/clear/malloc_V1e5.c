/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_V1e5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysbai-jo <ysbai-jo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:29:18 by ysbai-jo          #+#    #+#             */
/*   Updated: 2024/05/28 14:34:13 by ysbai-jo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	*malloc_v1e2(size_t size, t_pipex *core)
{
	void	*data;

	data = malloc(size);
	if (!data)
		(perror("pipex: malloc"), destroy(core), exit(EXIT_FAILURE));
	return (data);
}
