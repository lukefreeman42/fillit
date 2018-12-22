/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llelias <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 15:38:19 by llelias           #+#    #+#             */
/*   Updated: 2018/12/22 14:29:52 by llelias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	char	*file;
	int		dim;
	t_env	*e;

	dim = 0;
	if (argc != 2)
		usage();
	file = argv[1];
	e = c_env(dim, file);
	dim = ft_nsqr(e->nop_m * 4);
	change_dim(e, dim);
	while ((!solve(*e, 0, 0, 0)))
		change_dim(e, e->dim + 1);
	make_map(*e);
	return (0);
}
