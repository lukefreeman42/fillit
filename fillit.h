/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llelias <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 11:31:24 by llelias           #+#    #+#             */
/*   Updated: 2018/12/19 19:25:42 by llelias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft/libft.h"
#define		NUMO_T 11

typedef	struct{
	int		*row;
	int		avail;
	int		r;
	int		c;
	char	a;
} tetra;



typedef	struct{
	tetra	*tset;
	int 	*map;
	int		dim;
	int		nop_m;
}env;

int		solve(env e, int num, int r, int c);
env		*c_env(int dim, char *file);
void	change_dim(env *e, int dim);
int		fits(env e, int num, int r, int c);
int		place(env e, int num, int r, int c);
int		rmv(env e, int num, int r, int c);
void	print_row(int row, int bin, int dim, tetra *tset);
void	print_map(env e);	
