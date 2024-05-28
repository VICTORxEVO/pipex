#include "pipex_bonus.h"

void    read_line(t_pipex *core, char *limit)
{
    char    *line;
    int     n_lines;

    n_lines = 0;
    line = get_next_line(0);
    while(line && ++n_lines)
    {
        if (!ft_strncmp(line, limit, (ft_strlen(line) - 1)))
        {
            free(line);
            if (close(core->pipe[0][WRITE_SIDE]) < 0)
                (destroy(core), peexit("pipex", 1, 'P', false));
            return;
        }
        if (write(core->pipe[0][WRITE_SIDE], line, ft_strlen(line)) < 0)
            (destroy(core), peexit("pipex", 1, 'P', false));
        free(line);
        line = get_next_line(0);
    }
    if (close(core->pipe[0][WRITE_SIDE]) < 0)
        (destroy(core), peexit("pipex", 1, 'P', false));
    print_null_err(n_lines, limit, core);
}

