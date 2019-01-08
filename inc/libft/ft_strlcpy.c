/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llelias <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 08:34:38 by llelias           #+#    #+#             */
/*   Updated: 2019/01/08 06:04:59 by llelias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	size_t cp_n;

	cp_n = 0;
	if (dst && src)
		while (n--)
		{
			if (*src)
				cp_n++;
			*dst++ = (*src) ? *src++ : '\0';
		}
	return (cp_n);
}
