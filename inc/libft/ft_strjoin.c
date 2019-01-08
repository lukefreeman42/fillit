/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llelias <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 07:03:47 by llelias           #+#    #+#             */
/*   Updated: 2018/11/30 07:12:51 by llelias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*join;
	size_t	n1;
	size_t	n2;
	size_t	status;

	status = 0;
	if (s1 && s2)
	{
		n1 = ft_strlen(s1);
		n2 = ft_strlen(s2);
		if ((join = ft_strnew(n1 + n2)))
			if ((status = ft_strlcpy(join, s1, n1)) == n1)
				if ((status = ft_strlcat(join, s2, n1 + n2)) == n2)
					return (join);
	}
	return (NULL);
}
