/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysbai-jo <ysbai-jo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 11:07:53 by ysbai-jo          #+#    #+#             */
/*   Updated: 2024/05/12 15:41:45 by ysbai-jo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"


int main(int ac, char *av[], char *env[])
{
    t_pipex core;
    int pid;
    int i;
    int status;
    
    parser(ac, av, &core, env);
    while (++core.i < core.n_cmd)
    {
        pid = fork();
        if (pid < 0)
            (destroy(&core), peexit("pipex: ", 1, 'P', false));
        if (!pid)
            child_action(&core);
        else
        {
            core.pids[core.i] = pid;
            waitpid(pid, &status, 0);
            delete_1cmd(&core.cmd);
        }
    }
}