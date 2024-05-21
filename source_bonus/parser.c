#include "../includes/pipex_bonus.h"

static void	init(t_pipex *core, char *av[], int ac, char *env[])
{
	core->path = get_paths(env, core);
	core->env = env;
	core->n_cmd = ac - 3;
	core->f_in = av[1];
	core->f_out = av[ac - 1];
	core->cmd = get_cmds(core->n_cmd, av + 2, core);
	core->pids = malloc_V1e2(sizeof(int) * core->n_cmd, core);
	core->n_pipes = core->n_cmd - 1;
}

void	parser(int ac, char *av[], t_pipex *core, char *env[])
{
	if (ac < 5)
		(puterr("pipex: usage: <__input_file_> <__cmd_1_> <__cmd_2_> <__output_file_>\n"),
			exit(EXIT_FAILURE));
	if (!ft_strncmp(av[1], "here_doc", ft_strlen("here_doc")))
	{
		if (ac != 6)
		{
			puterr("pipex: usage: 'here_doc' <__LIMITER_> <__cmd_2_> <__output_file_>\n");
			exit(EXIT_FAILURE);
		}
		here_doc(av + 2, core, env);
	}
    init(core, av, ac, env);
	create_pipes(core);
	// for (int i = 0;core->path[i];i++)
	// 	printf("core->path[%d] -> %s\n", i, core->path[i]);
	// printf("\ncore->f_in ->%s", core->f_in);
	// printf("\ncore->f_out ->%s", core->f_out);
	// printf("\n");
	// while (core->cmd)
	// {
	// 	printf("\n");
	// 	for (int i = 0;core->cmd->cmd_and_args && core->cmd->cmd_and_args[i];i++)
	// 		printf("core->cmd->cmd_and_args[%d] ->%s0\n", i, core->cmd->cmd_and_args[i]);
	// 	printf("\n");
	// 	for (int i = 0;core->cmd->duptfull_paths && core->cmd->duptfull_paths[i];i++)
	// 		printf("core->cmd->duptfull_paths[%d] ->%s0\n", i, core->cmd->duptfull_paths[i]);
	// 	core->cmd = core->cmd->next;
	// }
}