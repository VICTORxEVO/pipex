/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysbai-jo <ysbai-jo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:30:01 by ysbai-jo          #+#    #+#             */
/*   Updated: 2024/05/28 09:12:52 by ysbai-jo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static long	calc_len(long nbr)
{
	long	sum;

	sum = 0;
	if (nbr < 0)
		++sum;
	while (nbr)
	{
		nbr /= 10;
		++sum;
	}
	return (sum);
}

char	*ft_itoa(int n, t_pipex *core)
{
	long	f_len;
	char	*cp;
	long	n_pro;

	if (n == 0)
		return (ft_strdup("0"));
	n_pro = n;
	f_len = calc_len(n_pro);
	cp = malloc_V1e2(sizeof(char) * (f_len + 1), core);
	cp[f_len--] = 0;
	if (n_pro < 0)
	{
		*cp = '-';
		n_pro *= -1;
	}
	while (n_pro)
	{
		cp[f_len--] = n_pro % 10 + '0';
		n_pro /= 10;
	}
	return (cp);
}
