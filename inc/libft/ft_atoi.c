/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llelias <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 17:59:39 by llelias           #+#    #+#             */
/*   Updated: 2019/01/08 05:40:50 by llelias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_isdigit(int c)
{
	if (c >= (int)'0' && c <= (int)'9')
		return (1);
	else
		return (0);
}

static int			ft_isws(int c)
{
	if (c == (int)' ' || c == (int)'\n' || c == (int)'\t' || c == (int)'\r'
			|| c == (int)'\v' || c == (int)'\f')
		return (1);
	else
		return (0);
}

static const char	*skip_ws(const char *str)
{
	while (ft_isws(*str))
		str++;
	return (str);
}

static int			set_flag(const char *str)
{
	if (*str == '-')
		return (1);
	else
		return (0);
}

int					ft_atoi(const char *str)
{
	long int	tot;
	int			flag;

	flag = 0;
	tot = 0;
	str = skip_ws(str);
	if (*str == '-' || *str == '+')
		flag = set_flag(str++);
	while (ft_isdigit(*str))
		tot = (tot * 10) + (*str++ - 48);
	if (flag)
		tot = tot * -1;
	return ((int)tot);
}
