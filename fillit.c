/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llelias <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 17:07:23 by llelias           #+#    #+#             */
/*   Updated: 2018/12/15 11:56:21 by llelias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "stdio.h"

void	left_most(tetra p)
{
	int i;
	while (p.row[0] % 2 == 0 && p.row[1] % 2 == 0 
			&&  p.row[2] % 2 == 0 && p.row[3] % 2 == 0)
	{
		i = -1;
		while (++i < 4)
			p.row[i] /= 2;
	}
}

void	top_most(tetra p) //takes in a peice and shift it to its topmost position.
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
	pset[i].row = (int*)malloc(4 * sizeof(int));
	pset[i].row = (int*)ft_memset(pset[i].row, 0, 16);
	pset[i].use = 1;
	while (j < 20)
	{
		if (j % 5 == 0)
			bin = 1;
		if (rb[j] == '#')
			pset[i].row[j/5] += bin;
		bin *= 2;
		j++;
	}
	left_most(pset[i]);
	top_most(pset[i]);
}			

void	c_pset(int fd, tetra **pset)
{
	char rb[21];
	int i;
	i = 0;
	while (read(fd, rb, 21) > 0)
	{
		c_p(*pset, i, rb);
		i++;
	}
}

int	*c_map(int dim)
{
	int *map;

	map = (int*)malloc(dim * sizeof(int));
	map = (int*)ft_memset(map, 0, dim * 4);
	return (map);
}



int fits(int *map, int r, int c, tetra p) //might need dimension parameter
{
	int i;

	i = 0;
	while (i < 4)
	{
		if ((map[i + r] ^ (p.row[i] * ft_power(2, c))) != map[i + r] + (p.row[i] * ft_power(2,c)))
			return (0);
		i++;
	}
	return (1);
}

void	place_p(int *map, int r, int c, tetra p)
{
	int i;
	
	i = 0;
	while (i < 4)
	{
		map[i + r] = (map[i + r] ^ (p.row[i] * ft_power(2, c)));
		i++;
	}
	p.use = 0;
}

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

void	print_map(int *map, int dim) //need dim because of max bin.
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

int main(int argc, char **argv)
{
	int fd =	open("test", O_RDONLY);
	int i =		0; //
	int j = 	0; //
	int p1 = atoi(argv[1]);
	int r1 = atoi(argv[2]);
	int c1 = atoi(argv[3]);

	int p2 = atoi(argv[4]);
	int r2 = atoi(argv[5]);
	int c2 = atoi(argv[6]);
	int	*map = c_map(5);
	tetra *pset = (tetra*)malloc(10 * sizeof(tetra));
	c_pset(fd, &pset);
	//test fits
	printf("%d\n", fits(map, r1, c1, pset[p1]));
	place_p(map, r1, c1, pset[p1]);
	printf("%d\n", fits(map, r2, c2, pset[p2]));
	place_p(map, r2, c2, pset[p2]);
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
