#include "pipex.h"

static void	init(t_pipex *core, char *av[], int ac, char *env[])
{
	core->path = get_paths(env, core);
	core->env = env;
	core->n_cmd = ac - 3;
	core->f_in = av[1];
	core->f_out = av[ac - 1];
	core->cmd = get_cmds(core->n_cmd, av + 2, core);
	core->pids = malloc_V1e2(sizeof(int) * (core->n_cmd + 1), core);
	core->n_pipes = core->n_cmd - 1;
	create_pipes(core);
}

void	parser(int ac, char *av[], t_pipex *core, char *env[])
{
	if (ac != 5)
		(puterr("pipex: usage <__input_file> <__cmd_1> <__cmd_2> <__output_file>\n"),
			exit(EXIT_FAILURE));
    init(core, av, ac, env);
}
