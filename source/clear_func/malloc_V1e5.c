#include "../../includes/pipex.h"


void    *malloc_V1e2(size_t size, t_pipex *core)
{
    void *data;

    data = malloc(size);
    if (!data)
        (perror("pipex: malloc:"), destroy(core));
    return (data);
}