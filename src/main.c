/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llelias <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 15:38:19 by llelias           #+#    #+#             */
/*   Updated: 2019/01/09 17:28:34 by llelias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

int		fillit(char *file, int alg)
{
	int		dim;
	t_env	*e;

	dim = 0;
	e = c_env(dim, file);
	dim = ft_nsqr(e->nop_m * 4);
	change_dim(e, dim);
	if (alg)
		while ((!solve_ll(*e, 0, 0, 0)))
			change_dim(e, e->dim + 1);
	else
		while ((!solve_sh(*e, 0)))
			change_dim(e, e->dim + 1);
	make_map(*e);
	return (0);
}

/*
** Set FLAG to 1 for fillit project.
** If FLAG == 0, fillit will take a second argument either a 1 or 0
** to determine which algorithm to use a 0 for sharris, 1 for llelias
*/

int		main(int argc, char **argv)
{
	char	*file;
	int		alg;
	int		flag;

	flag = 1;
	alg = 0;
	if (flag)
	{
		if (argc != 2)
			usage();
	}
	else
	{
		if (argc != 3)
			usage();
		alg = ft_atoi(argv[2]);
	}
	file = argv[1];
	return (fillit(file, alg));
}
