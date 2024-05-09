/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysbai-jo <ysbai-jo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 11:05:34 by ysbai-jo          #+#    #+#             */
/*   Updated: 2024/05/07 15:33:38 by ysbai-jo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

// needed libraries
# include "get_next_line.h"
# include <stdbool.h>
# include <errno.h>







// needed structs
typedef struct s_cmd
{
    char *cmd_p;
    char **cmd_args;
    char **paths;
    struct s_cmd *next;
}   t_cmd;

typedef struct s_trash
{
    void *data;
    struct s_trash *next;
}   t_trash;

typedef struct s_pipex
{
    char  *f_in;
    char    *f_out;
    t_trash *collector;
    char **env;
    int n_cmd;
    t_cmd *cmd;
    int i;
    int *pids;
}   t_pipex;


// external functions
bool	ft_lstadd_back(t_cmd **lst, t_cmd *new);
void	ft_lstclear(t_trash **lst);
t_cmd	*ft_lstnew_cmd(char *path, char **args, t_pipex *core);
t_trash	*ft_lstnew(void *content);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	**ft_split(const char *s, char c);
char	*ft_strchr(const char *str, int c);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
int	ft_strncmp(const char *str1, const char *str2, size_t n);
char	*get_next_line(int fd);
void	puterr(char *s);







// clear functions
void    *malloc_V2(size_t size, t_pipex *core);


















#endif