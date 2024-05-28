/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysbai-jo <ysbai-jo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:28:49 by ysbai-jo          #+#    #+#             */
/*   Updated: 2024/05/28 14:28:50 by ysbai-jo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	child_action(t_pipex *core)
{
	check_fin_fout(core);
	seal_unused_p(core);
	prepere_in_out(core);
	exec_cmd(core);
}