/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prnt.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llelias <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 15:31:21 by llelias           #+#    #+#             */
/*   Updated: 2018/12/19 15:36:43 by llelias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_row(int row, int bin, int dim, tetra *tset)
{
	int c;
	
	c = dim - 1;
	if (dim > 0)
	{
		if (row / bin == 1)
		{
			row -= bin;
			bin /= 2;
			print_row(row, bin, dim - 1, tset);
			ft_putstr("#");
		}
		else
		{
			bin /= 2;
			print_row(row, bin, dim - 1, tset);
			ft_putstr(".");
		}
	}
}

void	print_map(env e)
{
	int i;

	i = 0;
	while (i < e.dim)
	{
		print_row(e.map[i], ft_power(2, e.dim - 1), e.dim, e.tset);
		ft_putstr("\n");
		i++;
	}
}
