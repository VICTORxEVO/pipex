/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysbai-jo <ysbai-jo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 21:07:10 by ysbai-jo          #+#    #+#             */
/*   Updated: 2024/05/28 09:09:01 by ysbai-jo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    free_2d(void **arr)
{
    int i;

    if (!arr)
        return ;
    i = -1;
    while (arr[++i])
        free(arr[i]);
    free(arr);
}

void    destroy(t_pipex *core)
{
    free_2d((void **)core->path);
    ft_lstclear(&core->cmd);
    free(core->pids);
    free_2d((void **)core->pipe);
}
