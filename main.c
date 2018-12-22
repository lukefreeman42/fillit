/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llelias <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 15:38:19 by llelias           #+#    #+#             */
/*   Updated: 2018/12/20 19:02:25 by llelias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	char	*file;
	int		dim;
	env		*e;

	if (argc == 0)
		return (-1);
	file = "test";
	dim = atoi(argv[1]);
	e = c_env(dim, file);
	while ((!solve(*e, 0, 0, 0)))
		change_dim(e, e->dim + 1);
	ft_putstr("\n");
	make_map(*e);
	return (0);
}
