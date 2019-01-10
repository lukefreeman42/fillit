/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llelias <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 16:12:31 by llelias           #+#    #+#             */
/*   Updated: 2019/01/09 17:38:15 by llelias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

static void		standardize(t_tetra t)
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

static void		c_tetra(t_tetra *tset, int num, char *src)
{
	int rd;
	int bin;
	int hash;

	rd = 0;
	hash = 0;
	tset[num].row = (int*)ft_memalloc(4 * sizeof(int));
	tset[num].a = num + 'A';
	while (rd < 21)
	{
		if (rd % 5 == 0)
			bin = 1;
		if (src[rd] == '#' && (hash += 1))
			tset[num].row[rd / 5] += bin;
		if ((bin *= 2) && rd % 5 == 4)
			if (src[rd] != '\n')
				error();
		if (rd % 5 != 4 && rd != 20)
			if (src[rd] != '.' && src[rd] != '#')
				error();
		rd++;
	}
	if (hash != 4)
		error();
	standardize(tset[num]);
}

static int		c_tset(char *file, t_tetra **tset)
{
	char	rb[21];
	int		num;
	int		fd;
	int		i[2];

	num = 0;
	fd = open(file, O_RDONLY);
	if (NUMO_T < 1)
		error();
	*tset = (t_tetra*)ft_memalloc(NUMO_T * sizeof(t_tetra));
	while ((i[0] = read(fd, rb, 21)) > 0)
	{
		c_tetra(*tset, num++, rb);
		if (i[0] != 20 && i[0] != 21)
			error();
		i[1] = i[0];
	}
	if (i[1] != 20)
		error();
	i[0] = -1;
	while (i[0] < num)
		(*tset)[i[0]++].avail = 1;
	if (!valid_tset(*tset, num))
		error();
	return (num);
}

t_env			*c_env(int dim, char *file)
{
	t_env	*e;
	t_tetra	*tset;

	e = (t_env*)ft_memalloc(sizeof(t_env));
	e->map = (int*)ft_memalloc(dim * sizeof(int));
	e->dim = dim;
	e->nop_m = c_tset(file, &tset);
	e->tset = tset;
	return (e);
}

void			change_dim(t_env *e, int dim)
{
	free(e->map);
	e->map = (int*)ft_memalloc(dim * sizeof(int));
	e->dim = dim;
}
