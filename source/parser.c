#include "../includes/pipex.h"

void	inti(t_pipex *core, char *av[], int ac, char *env[])
{
	core->env = env;
	core->f_in = av[1];
	core->f_out = av[ac - 1];
	core->cmd = get_cmds(ac - 3, av + 2, core);
	core->n_cmd = ac - 3;
	core->pids = malloc_V2(sizeof(int) * core->n_cmd, core);
	core->
}



void	parser(int ac, char *av[], t_pipex *core, char *env[])
{
	if (ac < 5)
		(puterr("pipex: usage <__input_file> <__cmd_1> <__cmd_2> <__output_file>"),
			exit(EXIT_FAILURE));
    init(core, av, ac, env);
}