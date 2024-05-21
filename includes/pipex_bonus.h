#ifndef PIPEX_H
# define PIPEX_H

// needed libraries
# include "get_next_line.h"
# include <stdbool.h>
# include <errno.h>
# include <sys/wait.h>
# include <limits.h>

//some macros
# define WRITE_SIDE 1
# define READ_SIDE  0





// needed structs
typedef struct s_cmd
{
    char **cmd_and_args;
    char **duptfull_paths;
    char *str_cmd;
    struct s_cmd *next;
}   t_cmd;

typedef struct s_pipex
{
    char  *f_in;
    char    *f_out;
    int in_fd;
    int out_fd;
    char **path;
    int n_cmd;
    t_cmd *cmd;
    int i;
    int *pids;
    int **pipe;
    int n_pipes;
    char **env;
}   t_pipex;


// external functions
void	ft_lstadd_back(t_cmd **lst, t_cmd *new);
void	ft_lstclear(t_cmd **lst);
t_cmd	*ft_lstnew_cmd(char **cmd_and_args, char *str_cmd, t_pipex *core);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	**ft_split(const char *s, char c, t_pipex *core);
char	*ft_strchr(const char *str, int c);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char *s1, char *s2, char flag, t_pipex *core);
int     ft_strncmp(const char *str1, const char *str2, size_t n);
char	*get_next_line(int fd);
void	puterr(char *s);
void    ft_lstdelone(t_cmd *node);
bool is_all_spaces(const char *s);

//algo functions
char **get_paths(char **env, t_pipex *core);
t_cmd   *get_cmds(int n_cmd, char *av[], t_pipex *core);
void	parser(int ac, char *av[], t_pipex *core, char *env[]);
void    seal_unused_p(t_pipex *core);
void	prepere_in_out(t_pipex *core);
void	check_fin_fout(t_pipex *core);
void	exec_cmd(t_pipex *core);
void    dup2fd(int oldfd, int newfd, t_pipex *core);
char	*get_valid_path(t_pipex *core, char **duptfull_paths);
void    verify_cmd(char *path, t_pipex *core);
void    child_action(t_pipex *core);
void    seal_all_p(int **pipes, t_pipex *core);
void    parent_action(t_pipex *core, int *status);
void create_pipes(t_pipex *core);

//here_doc functions
void    child_cmd1(t_pipex *core);
void    close_pipes(int **pipes, t_pipex *core, char flag);
void    here_doc(char *av[], t_pipex *core, char *env[]);
void    parent_cmd2(t_pipex *core);
void    read_line(t_pipex *core, char *limit);






// clear functions
void    *malloc_V1e2(size_t size, t_pipex *core);
void    destroy(t_pipex *core);
void    free_2d(void **arr);
void    delete_1cmd(t_cmd **lst);



//exit functions
void    peexit(char *msg, int exit_code, char flag, bool free_or_not);
























# endif