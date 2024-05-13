#include "../includes/pipex.h"

static char **get_full_path(char **path, char *cmd, t_pipex *core)
{
    char **full_path;
    int i;

        
    if (!path)
        return (NULL);
    i = 0;
    while (path[i])
        i++;
    full_path = malloc_V1e2(sizeof(char *) * i + 1, core);
    i = -1;
    while (path[++i])
        full_path[i] = ft_strjoin(path[i], cmd, 'N', core);
    full_path[i] = NULL;
    return (full_path);
}

static t_cmd    *add_new_cmd(char *cmd_full, t_cmd **node, t_pipex *core)
{
    char **splited;
    t_cmd *cmd_node;

    splited = ft_split(cmd_full, ' ', core);
    cmd_node = ft_lstnew_cmd(splited, cmd_full, core);
    ft_lstadd_back(node, cmd_node);
    return (cmd_node);
}


t_cmd   *get_cmds(int ac, char *av[], t_pipex *core)
{
    int i;
    t_cmd *cmd_node;
    t_cmd *to_check;

    i = -1;
    cmd_node = NULL;
    while (++i < ac)
    {
        to_check = add_new_cmd(av[i], &cmd_node, core);
        to_check->duptfull_paths = NULL;
        if (ft_strchr(to_check->cmd_and_args[0], '/') || av[i][0] == '.')
            continue;
        to_check->duptfull_paths = get_full_path(core->path, to_check->cmd_and_args[0], core);
    }
    return (cmd_node);
}
