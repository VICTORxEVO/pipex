#include "pipex.h"

void create_pipes(t_pipex *core)
{
    int i;
    
    core->pipe = malloc_V1e2(sizeof(int *) * (core->n_pipes + 1), core);
	core->pipe[core->n_pipes] = NULL;
	i = -1;
	while (++i < core->n_pipes)
	{
		core->pipe[i] = malloc_V1e2(sizeof(int) * 2, core);
		if (pipe(core->pipe[i]))
			(destroy(core), peexit("pipex: ", 1, 'P', false));
	}
}
