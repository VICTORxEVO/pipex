/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_null_err.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysbai-jo <ysbai-jo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:29:59 by ysbai-jo          #+#    #+#             */
/*   Updated: 2024/05/28 14:43:22 by ysbai-jo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	print_null_err(int n_lines, char *limiter, t_pipex *core)
{
	char	*str;

	str = ft_itoa(n_lines, core);
	puterr("pipex: warning: here-document at line ");
	(puterr(str), free(str));
	puterr(" delimited by end-of-file (wanted `");
	(puterr(limiter), puterr("')\n"));
}
