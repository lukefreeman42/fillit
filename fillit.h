/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llelias <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 11:31:24 by llelias           #+#    #+#             */
/*   Updated: 2018/12/21 19:54:22 by llelias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft/libft.h"
# define NUMO_T 11

typedef struct	s_tetra
{
	int		*row;
	int		avail;
	int		r;
	int		c;
	char	a;
}				t_tetra;
typedef struct	s_env
{
	t_tetra	*tset;
	int		*map;
	int		dim;
	int		nop_m;
}				t_env;

void			usage(void);
int				solve(t_env e, int num, int r, int c);
t_env			*c_env(int dim, char *file);
void			change_dim(t_env *e, int dim);
int				fits(t_env e, int num, int r, int c);
int				place(t_env e, int num, int r, int c);
int				rmv(t_env e, int num, int r, int c);
void			make_map(t_env e);
void			error(void);
int				valid_tset(t_tetra *tset, int num);
#endif
