/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysbai-jo <ysbai-jo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 11:55:25 by ysbai-jo          #+#    #+#             */
/*   Updated: 2024/05/21 10:19:31 by ysbai-jo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex_bonus.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	len;

	len = (ft_strlen(s) + 1);
	ptr = malloc(sizeof(char) * len);
	if (!ptr)
		return (0);
	return ((char *)(ft_memcpy(ptr, s, len)));
}