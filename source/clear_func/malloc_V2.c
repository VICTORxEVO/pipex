#include "../../includes/pipex.h"

void    destroy(t_pipex *core)
{
    ft_lstclear(&core->collector);
}

void    *malloc_V2(size_t size, t_pipex *core)
{
    void *data;
    bool res;
    data = malloc(size);
    if (!data)
        (perror("pipex: malloc:"), destroy(core));
    res = ft_lstback(&core->collector, ft_lstnew(data));
    if (!res)
        (perror("pipex: malloc:"), destroy(core));
    return (data);
}