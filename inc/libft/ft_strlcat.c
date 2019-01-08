/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llelias <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:34:58 by llelias           #+#    #+#             */
/*   Updated: 2018/11/08 19:25:38 by llelias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *s1, const char *s2, size_t size)
{
	void	*p;
	size_t	len1;
	size_t	len2;

	p = (void*)s1;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (size <= len1)
		return (len2 + size);
	size -= len1 + 1;
	s1 += len1;
	while (size--)
	{
		*s1++ = *s2;
		if (*s2++ == '\0')
			return (len1 + len2);
	}
	*s1 = '\0';
	return (len1 + len2);
}
