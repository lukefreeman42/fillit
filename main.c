/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llelias <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 15:38:19 by llelias           #+#    #+#             */
/*   Updated: 2018/12/20 10:35:50 by llelias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	char *file = "test";
	int dim = atoi(argv[1]);
	env *e = c_env(dim, file);

	while  ((!solve(*e, 0, 0, 0)))
		change_dim(e, e->dim + 1);
//	int t = atoi(argv[1]);
//	int r = atoi(argv[2]);
//	int c = atoi(argv[3]);
//	if (fits(*e, t, r, c))
//		place(*e, t, r, c);
	ft_putstr("\n");
	make_map(*e);
	return (0);
}
