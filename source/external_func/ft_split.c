/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysbai-jo <ysbai-jo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 11:50:16 by ysbai-jo          #+#    #+#             */
/*   Updated: 2024/05/12 10:52:06 by ysbai-jo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

static int	word_num(const char *s, const char x)
{
	int	wn;

	wn = 0;
	while (*s)
	{
		if (*s == x)
			s++;
		else
		{
			wn++;
			while (*s && *s != x)
				s++;
		}
	}
	return (wn);
}

static char	**mem_error(char **arr)
{
	int	r;

	r = 0;
	while (arr[r])
	{
		free(arr[r]);
		r++;
	}
	free(arr);
	return (NULL);
}

static char	*do_word(const char *s, const char x, int *q_resume, t_pipex *core)
{
	int		len;
	char	*word;
	int		i;

	len = 0;
	while (s[*q_resume] == x)
		(*q_resume)++;
	i = *q_resume;
	while (s[i] && s[i++] != x)
		len++;
	word = malloc_V1e2(sizeof(char) * (len + 1), core);
	i = 0;
	while (s[*q_resume] && s[*q_resume] != x)
	{
		word[i] = s[*q_resume];
		(*q_resume)++;
		i++;
	}
	word[i] = '\0';
	return (word);
}

char **handle_null(t_pipex *core, char *s)
{
	char **arr;

	if (!s)
		return (NULL);
	arr = malloc_V1e2(sizeof(char *) * 2, core);
	arr[1] = 0;
	arr[0] = malloc_V1e2(sizeof(char) * 1, core);
	arr[0][0] = ' ';
	return (arr);
}

char	**ft_split(const char *s, char c, t_pipex *core)
{
	char	**arr;
	int		q_res;
	int		wn;
	int		i;

	if (!*s || !s)
		return (handle_null(core, s));
	wn = word_num(s, c);
	arr = malloc_V1e2(sizeof(char *) * (wn + 1), core);
	arr[wn] = 0;
	q_res = 0;
	i = 0;
	while (i < wn)
	{
		arr[i] = do_word(s, c, &q_res, core);
		if (!(arr[i]))
			return (mem_error(arr));
		i++;
	}
	return (arr);
}
