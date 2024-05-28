/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysbai-jo <ysbai-jo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:30:50 by ysbai-jo          #+#    #+#             */
/*   Updated: 2024/05/28 14:46:15 by ysbai-jo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	init(t_pipex *core, char *av[], int ac, char *env[])
{
	core->path = get_paths(env, core);
	core->env = env;
	core->n_cmd = ac - 3;
	core->f_in = av[1];
	core->f_out = av[ac - 1];
	core->cmd = get_cmds(core->n_cmd, av + 2, core);
	core->pids = malloc_v1e2(sizeof(int) * (core->n_cmd + 1), core);
	core->n_pipes = core->n_cmd - 1;
	create_pipes(core);
}

void	parser(int ac, char *av[], t_pipex *core, char *env[])
{
	if (ac < 5)
	{
		puterr("pipex: usage: <__input_file_> ");
		puterr("<__cmd_1_> <__cmd_2_>... <__cmd_n_> <__output_file_>\n");
		exit(EXIT_FAILURE);
	}
	if (!ft_strncmp(av[1], "here_doc", ft_strlen("here_doc")))
	{
		if (ac != 6)
		{
			puterr("pipex: usage: 'here_doc' <__LIMITER_> ");
			puterr("<__cmd_1_> <__cmd_2_> <__output_file_>\n");
			exit(EXIT_FAILURE);
		}
		here_doc(av + 2, core, env);
	}
	init(core, av, ac, env);
}
