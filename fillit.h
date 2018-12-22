/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llelias <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 11:31:24 by llelias           #+#    #+#             */
/*   Updated: 2018/12/21 13:34:38 by llelias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft/libft.h"
# define NUMO_T 11

typedef struct{
	int		*row;
	int		avail;
	int		r;
	int		c;
	char	a;
}tetra;

typedef struct{
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
void	make_map(env e);
void	error(void);
int		valid_tset(tetra *tset, int num);
#endif
