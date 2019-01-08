/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fstrjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llelias <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 08:35:20 by llelias           #+#    #+#             */
/*   Updated: 2018/12/02 08:49:26 by llelias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_fstrjoin(char *s1, char *s2, int x)
{
	char *join;

	join = ft_strjoin(s1, s2);
	if (x == 1)
		ft_strdel(&s1);
	if (x == 2)
		ft_strdel(&s2);
	if (x == 3)
	{
		ft_strdel(&s1);
		ft_strdel(&s2);
	}
	return (join);
}
