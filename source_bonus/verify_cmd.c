#include "../includes/pipex_bonus.h"

void    verify_cmd(char *path, t_pipex *core)
{
    if (access(path, F_OK))
        (destroy(core), peexit(ft_strjoin("pipex: ", path, 'N', core), 127, 'P', true));
    else if (access(path, X_OK))
        (destroy(core), peexit(ft_strjoin("pipex: ", path, 'N', core), 126, 'P', true));
}
