#include "../../includes/pipex.h"

void    ft_lstdelone(t_cmd *node)
{
    free_2d((void **)node->cmd_and_args);
    free_2d((void **)node->duptfull_paths);
    free(node);
}