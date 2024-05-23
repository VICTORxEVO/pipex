/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysbai-jo <ysbai-jo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 21:07:10 by ysbai-jo          #+#    #+#             */
/*   Updated: 2024/05/23 21:07:11 by ysbai-jo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

void    destroy(t_pipex *core)
{
    free_2d((void **)core->path);
    ft_lstclear(&core->cmd);
    free(core->pids);
    free_2d((void **)core->pipe);
}
