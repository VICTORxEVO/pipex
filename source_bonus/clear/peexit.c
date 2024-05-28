/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   peexit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysbai-jo <ysbai-jo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:29:21 by ysbai-jo          #+#    #+#             */
/*   Updated: 2024/05/28 14:42:10 by ysbai-jo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	peexit(char *msg, int exit_code, char flag, bool free_or_not)
{
	if (flag == 'P')
		perror(msg);
	else
		puterr(msg);
	if (free_or_not == true)
		free(msg);
	exit(exit_code);
}
