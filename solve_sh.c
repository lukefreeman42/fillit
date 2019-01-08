/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_sh.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llelias <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 17:23:23 by llelias           #+#    #+#             */
/*   Updated: 2019/01/07 17:11:20 by llelias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		solve_sh(t_env e, int i)
{
	int r;
	int c;
	int sf;

	sf = 0;
	r = 0;
	while(r < e.dim && t_check(e) && sf == 0)
	{
		c = 0;
		while (c < e.dim && sf == 0)
		{
			if (place(e, i, r, c))
				if (solve_sh(e, i + 1))
					sf = 1;
			if (sf == 0)
				rmv(e, i, r, c);
			c++;
		}
		r++;
	}
	if (t_check(e) == 0 || sf)
		return (1);
	else
		return (0);
}
