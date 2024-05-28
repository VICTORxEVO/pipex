#include "pipex_bonus.h"

void    print_null_err(int n_lines, char *limiter, t_pipex *core)
{
    char *str;

    str = ft_itoa(n_lines, core);
    puterr("pipex: warning: here-document at line ");
    (puterr(str), free(str));
    puterr(" delimited by end-of-file (wanted `");
    puterr(limiter), puterr("')\n");
    (destroy(core), exit(0));
}