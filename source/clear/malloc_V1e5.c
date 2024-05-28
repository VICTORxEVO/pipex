/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_V1e5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysbai-jo <ysbai-jo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 21:07:23 by ysbai-jo          #+#    #+#             */
/*   Updated: 2024/05/28 09:09:05 by ysbai-jo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    *malloc_V1e2(size_t size, t_pipex *core)
{
    void *data;

    data = malloc(size);
    if (!data)
        (perror("pipex: malloc:"), destroy(core));
    return (data);
}
