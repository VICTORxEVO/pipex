#include "../../includes/pipex_bonus.h"

void    destroy(t_pipex *core)
{
    free_2d((void **)core->path);
    ft_lstclear(&core->cmd);
    if (core->pids)
        free(core->pids);
    free_2d((void **)core->pipe);
}
