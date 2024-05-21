#include "../includes/pipex_bonus.h"

void    read_line(t_pipex *core, char *limit)
{
    char *line;

    line = get_next_line(0);
    while(line)
    {
        if (!ft_strncmp(line, limit, ft_strlen(limit)))
        {
            free(line);
            return;
        }
        if (write(core->pipe[0][WRITE_SIDE], line, ft_strlen(line)) < 0)
            (destroy(core), peexit("pipex", 1, 'P', false));
        free(line);
        line = get_next_line(0);
    }
}

