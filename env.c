/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llelias <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 11:36:50 by llelias           #+#    #+#             */
/*   Updated: 2018/12/19 15:53:00 by llelias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	void	standardize(tetra t)
{
	int i;
	while (!(t.row[0] % 2 || t.row[1] % 2 || t.row[2] % 2 || t.row[3] % 2)
		   && (i = -1))
		while (++i < 4)
			t.row[i] /= 2;
	while (t.row[0] == 0 && (i = -1))
	{
		while (++i < 3)
			t.row[i] = t.row[i + 1];
		t.row[3] = 0;
	}
}

static void	c_tetra(tetra *tset, int num, char *src)
{
	int rd;
	int bin;

	rd = 0;
	tset[num].row = (int*)ft_memalloc(4 * sizeof(int));
	tset[num].avail = 1;
	tset[num].a = num + 'A';
	while (rd < 20)
	{
		if (rd % 5 == 0)
			bin = 1;
		if (src[rd] == '#')
			tset[num].row[rd/5] += bin;
		bin *= 2;
		rd++;
	}
	standardize(tset[num]);
}

static int		c_tset(char *file, tetra **tset)
{
	char rb[21];
	int	num;
	int	fd;
	int	i;

	num = 0;
	i = -1;
	fd = open(file, O_RDONLY);
	*tset = (tetra*)ft_memalloc(NUMO_T *sizeof(tetra));
	while (read(fd, rb, 21) > 0)
		c_tetra(*tset, num++, rb);
	return (num);
}

env		*c_env(int dim, char *file)
{
	env *e;
	tetra *tset;

	e = (env*)ft_memalloc(sizeof(env));
	e->map = (int*)ft_memalloc(dim * sizeof(int));
	e->dim = dim;
	e->nop_m = c_tset(file, &tset);
	e->tset = tset;
	return (e);
}

void	change_dim(env *e, int dim)
{
	free(e->map);
	e->map = (int*)ft_memalloc(dim *sizeof(int));
	e->dim = dim;
}	