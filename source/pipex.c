/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysbai-jo <ysbai-jo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 11:07:53 by ysbai-jo          #+#    #+#             */
/*   Updated: 2024/05/05 12:11:43 by ysbai-jo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"


int main(int ac, char *av[], char *env[])
{
    t_pipex core;
    int pid;
    int i;
    
    parser(ac, av, &core, env);
    while (++core.i < core.n_cmd)
    {
        pid = fork();
        if (pid < 0)
            (perror("pipex:"), destroy(core), exit(EXIT_FAILURE));
        else if (!pid)
            child_action(&core);
        else
        {
            destroy_cmd(&core.cmd);
            core.pids[core.i] = pid;
        }
    }
}