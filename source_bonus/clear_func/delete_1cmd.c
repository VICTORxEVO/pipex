#include "../../includes/pipex_bonus.h"

void    delete_1cmd(t_cmd **lst)
{
    t_cmd *tmp;
    
    if (*lst)
    {
        tmp = (*lst)->next;
        ft_lstdelone(*lst);
        (*lst) = tmp;
    }
}