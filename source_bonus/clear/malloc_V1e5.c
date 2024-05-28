#include "pipex_bonus.h"


void    *malloc_V1e2(size_t size, t_pipex *core)
{
    void *data;

    data = malloc(size);
    if (!data)
        (perror("pipex: malloc"), destroy(core), exit(EXIT_FAILURE));
    return (data);
}
