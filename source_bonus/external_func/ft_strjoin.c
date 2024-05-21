/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysbai-jo <ysbai-jo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 11:55:29 by ysbai-jo          #+#    #+#             */
/*   Updated: 2024/05/21 10:19:34 by ysbai-jo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex_bonus.h"

char	*ft_strjoin(char *s1, char *s2, char flag, t_pipex *core)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*new;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new = malloc_V1e2(sizeof(char) * (s1_len + s2_len + 1), core);
	if (!new)
		return (NULL);
	ft_memcpy(new, s1, s1_len);
	ft_strlcpy(&new[s1_len], s2, s2_len + 1);
	if (flag == 'L')
		free(s1);
	else if (flag == 'R')
		free (s2);
	else if (flag == 'A')
		(free(s1), free(s2));
	return (new);
}
