/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llelias <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 07:13:50 by llelias           #+#    #+#             */
/*   Updated: 2018/11/30 09:40:29 by llelias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t status;

	status = 0;
	if (dst && src)
	{
		while (n--)
		{
			if (*dst)
				dst++;
			else
			{
				status++;
				*dst++ = *src++;
			}
		}
	}
	return (status);
}
