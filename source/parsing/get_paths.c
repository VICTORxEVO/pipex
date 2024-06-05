/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysbai-jo <ysbai-jo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:28:31 by ysbai-jo          #+#    #+#             */
/*   Updated: 2024/06/05 14:49:07 by ysbai-jo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_paths(char **env, t_pipex *core)
{
	int		i;
	char	**path;

	i = -1;
	while (env && env[++i])
	{
		if (!ft_strncmp(env[i], "PATH=", 5))
		{
			path = ft_split(env[i] + 5, ':', core);
			if (!path || !path[0][0])
				return (free_2d((void **)path), NULL);
			i = -1;
			while (path[++i])
				path[i] = ft_strjoin(path[i], "/", 'L', core);
			return (path);
		}
	}
	return (NULL);
}
