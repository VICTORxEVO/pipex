#include "../includes/pipex.h"

t_cmd   get_cmds(int ac, char *av[], t_pipex *core)
{
    int i;
    t_cmd *node;
    t_cmd *head;
    char **cmd;
    char **path;

    i = -1;
    while (++i < ac)
    {
        node = add_new_cmd(av[i], &head);
        if (ft_strchr(node->cmd_p, '/'))
            continue;
        node->paths = get_path(core->env, node);   
    }
}
