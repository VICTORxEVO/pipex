#include "pipex_bonus.h"

char **get_paths(char **env, t_pipex *core)
{
    int i;
    char **path;
    
    i = -1;
    while (env[++i])
    {
        if (!ft_strncmp(env[i], "PATH=", 5))
        {
            path = ft_split(ft_strchr(env[i], '/'), ':', core);
            if (!path)
                return (NULL);
            i = -1;
            while (path[++i])
                path[i] = ft_strjoin(path[i], "/", 'L', core);
            return (path);
        }
    }
    return (NULL);
}
