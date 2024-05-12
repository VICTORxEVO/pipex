#include "../includes/pipex.h"

static void	init(t_pipex *core, char *av[], int ac, char *env[])
{
	int i;

	core->path = get_paths(env, core);
	core->env = env;
	core->n_cmd = ac - 3;
	core->f_in = av[1];
	core->f_out = av[ac - 1];
	core->cmd = get_cmds(core->n_cmd, av + 2, core);
	core->pids = malloc_V1e5(sizeof(int) * core->n_cmd, core);
	core->n_pipes = core->n_cmd - 1;
	core->pipe = malloc_V1e5(sizeof(int *) * core->n_pipes + 1, core);
	core->pipe[core->n_pipes] = NULL;
	i = -1;
	while (core->pipe[++i])
	{
		core->pipe[i] = malloc_V1e5(sizeof(int) * 2, core);
		if (pipe(core->pipe[i]))
			(destroy(core), peexit("pipex: ", 1, 'P', false));
	}
}

void	parser(int ac, char *av[], t_pipex *core, char *env[])
{
	if (ac != 5)
		(puterr("pipex: usage <__input_file> <__cmd_1> <__cmd_2> <__output_file>\n"),
			exit(EXIT_FAILURE));
    init(core, av, ac, env);
	for (int i = 0;core->path[i];i++)
		printf("core->path[%d] -> %s\n", i, core->path[i]);
	printf("\ncore->f_in ->%s", core->f_in);
	printf("\ncore->f_out ->%s", core->f_out);
	printf("\n");
	while (core->cmd)
	{
		printf("\n");
		for (int i = 0;core->cmd->cmd_and_args && core->cmd->cmd_and_args[i];i++)
			printf("core->cmd->cmd_and_args[%d] ->%s0\n", i, core->cmd->cmd_and_args[i]);
		printf("\n");
		for (int i = 0;core->cmd->duptfull_paths && core->cmd->duptfull_paths[i];i++)
			printf("core->cmd->duptfull_paths[%d] ->%s0\n", i, core->cmd->duptfull_paths[i]);
		core->cmd = core->cmd->next;
	}
	exit(0);
}