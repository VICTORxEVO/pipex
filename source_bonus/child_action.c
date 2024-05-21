#include "../includes/pipex_bonus.h"

void    child_action(t_pipex *core)
{
    check_fin_fout(core);
    seal_unused_p(core);
    prepere_in_out(core);
    exec_cmd(core);
}
