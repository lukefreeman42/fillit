/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llelias <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 10:19:22 by llelias           #+#    #+#             */
/*   Updated: 2018/12/21 19:52:18 by llelias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	error(void)
{
	ft_putstr("Does not support negative exponents... yet");
	return (-1);
}

int			ft_power(int n, int p)
{
	int tot;

	tot = 1;
	if (p < 0)
		return (error());
	while (p-- > 0)
		tot *= n;
	return (tot);
}
