#include "../includes/pipex.h"

static bool check_file(char *str, char flag,t_pipex *core)
{
	int fd;

	if (flag == 'I')
	{
		if (access(str, F_OK) || access(str, R_OK))
			return(false);
		fd = open(str, O_RDONLY);
		if (fd < 0)
			return(false);
		if (close(fd) < 0)
			(destroy(core), peexit("pipex", 1, 'P', false));
		return (true);
	}
	if (access(str, F_OK) || access(str, W_OK))
		return(false);
	fd = open(str, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (fd < 0)
			return(false);
	if (close(fd) < 0)
		(destroy(core), peexit("pipex", 1, 'P', false));
	return (true);
}

static void check_files(t_pipex *core)
{
	char *str;

	if (!check_file(core->f_in, 'I', core))
	{
		str = ft_strjoin("pipex: ", core->f_in, 'N', core);
		(perror(str), free(str));
		if (!check_file(core->f_out, 'O', core))
		{
			str = ft_strjoin("pipex: ", core->f_out, 'N', core);
			(perror(str), free(str));
		}
		(destroy(core), exit(1));
	}

}

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
	check_files(core);
}

void	parser(int ac, char *av[], t_pipex *core, char *env[])
{
	if (ac != 5)
		(puterr("pipex: usage <__input_file> <__cmd_1> <__cmd_2> <__output_file>\n"),
			exit(EXIT_FAILURE));
    init(core, av, ac, env);
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