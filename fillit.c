/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llelias <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 17:07:23 by llelias           #+#    #+#             */
/*   Updated: 2018/12/15 17:24:21 by llelias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "stdio.h"

/*
**		CREATE ENVIORNMENT
*/

void	m_lft(tetra p)
{
	int i;

	while (p.row[0] % 2 == 0 && p.row[1] % 2 == 0 
			&&  p.row[2] % 2 == 0 && p.row[3] % 2 == 0 && (i = -1))
		while (++i < 4)
			p.row[i] /= 2;
}

void	m_top(tetra p)
{
	int i;

	while (p.row[0] == 0)
	{
		i = -1;
		while (++i < 3)
			p.row[i] = p.row[i + 1];
		p.row[3] = 0;
	}
}

void	c_p(tetra *pset, int i, char *rb)
{
	int j;
	int bin;

	j = 0;
	pset[i].row = (int*)ft_memalloc(4 * sizeof(int));
	pset[i].use = (int*)ft_memalloc(sizeof(int));
	*pset[i].use = 1;
	while (j < 20)
	{
		if (j % 5 == 0)
			bin = 1;
		if (rb[j] == '#')
			pset[i].row[j/5] += bin;
		bin *= 2;
		j++;
	}
	m_lft(pset[i]);
	m_top(pset[i]);
}	

int	c_pset(int fd, tetra **pset)
{
	char rb[21];
	int i;

	i = 0;
	while (read(fd, rb, 21) > 0)
		c_p(*pset, i++, rb);
	return (i);
}

int	*c_map(int dim)
{
	int *map;

	map = (int*)ft_memalloc(dim * sizeof(int));
	return (map);
}

/*
**		MAP MANIPULATION
*/

int fits(int *map, int r, int c, tetra p)
{
	int i;

	i = -1;
	if (*p.use == 0)
		return (0);
	while (++i < 4)
		if ((map[i + r] ^ (p.row[i] * ft_power(2, c)))
			   	!= map[i + r] + (p.row[i] * ft_power(2,c)))
			return (0);
	return (1);
}

void	place_rmv(int *map, int r, int c, tetra p, int rmv)
{
	int i;
	
	i = -1;
	while (++i < 4)
		map[i + r] = (map[i + r] ^ (p.row[i] * ft_power(2, c)));
	if (rmv == 1)
		*p.use = 1;
	else
		*p.use = 0;
}

/*
**		PRINT
*/

void	print_row(int row, int bin, int dim)
{
	if (dim > 0)
	{
		if (row / bin == 1)
		{
			row -= bin;
			bin /= 2;
			print_row(row, bin, dim -1);
			ft_putstr("#");
		}
		else
		{
			bin /= 2;
			print_row(row, bin, dim -1);
			ft_putstr(".");
		}
	}
}

void	print_map(int *map, int dim)
{
	int i;

	i = 0;
	while (i < dim)
	{
		print_row(map[i], ft_power(2, dim - 1), dim);
		ft_putstr("\n");
		i++;
	}
}


/*
**		SOLVE
*/

int		solve(int *map, int dim, int r, int c, tetra *pset, int i, int nop, int nop_max)
{
	if (nop == 0)
	{
		print_map(map, dim);
		return (1);
	}
	if (r == dim)
		return (0);
	if (i >= nop_max)
	{
		if (c == dim - 1)
			return(solve(map, dim, r + 1, 0, pset, 0, nop, nop_max));
		else
			return(solve(map, dim,  r, c + 1, pset, 0, nop, nop_max));
	}
	if (!fits(map, r, c, pset[i]))
		return(solve(map, dim,  r, c, pset, i + 1, nop, nop_max));
	else
	{
		place_rmv(map, r, c, pset[i], 0);
		print_map(map, dim);
		printf("%d", *pset[i].use);
		if (c == dim - 1)
		{
			if(solve(map, dim, r + 1, 0, pset, 0, nop - 1, nop_max))
				return (1);
			else
			{
				place_rmv(map, r, c, pset[i], 1);
				return (solve(map, dim,  r, c, pset, i + 1, nop, nop_max));
			}
		}
		else
		{
			if(solve(map, dim, r, c + 1, pset, 0, nop - 1, nop_max))
				return (1);
			else
			{
				place_rmv(map, r, c, pset[i], 1);
				return (solve(map, dim,  r, c, pset, i + 1, nop, nop_max));
			}
		}
	}
}

/*
**		MAIN
*/

int main(int argc, char **argv)
{
	int fd =	open("test", O_RDONLY);
	int i =		0; //
	int j = 	0; //
	int p1 = atoi(argv[1]);
	int r1 = atoi(argv[2]);
	int c1 = atoi(argv[3]);
	int nop;
	int p2 = atoi(argv[4]);
	int r2 = atoi(argv[5]);
	int c2 = atoi(argv[6]);
	int	*map = c_map(5);
	tetra *pset = (tetra*)malloc(10 * sizeof(tetra));
	nop = c_pset(fd, &pset);
	return (solve(map, 5, 0, 0, pset, 0, nop, nop));
	printf("%d\n", nop);
	//test fits
	printf("%d\n", fits(map, r1, c1, pset[p1]));
	place_rmv(map, r1, c1, pset[p1], 0);
	printf("%d\n", fits(map, r2, c2, pset[p2]));
	place_rmv(map, r2, c2, pset[p2], 0);
	place_rmv(map, r2, c2, pset[p2], 1);
	print_map(map, 5);
	ft_putstr("\n");
	//print peice values
	while (j++ < 4)
	{
		while (i < 4)
		{
			printf("%d", pset->row[i]);
			i++;
		}
		printf("\n");
		i = 0;
		pset++;
	}
	return (0);
}

//NEED TO DO:
