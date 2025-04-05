/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelckma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 12:00:29 by rpelckma          #+#    #+#             */
/*   Updated: 2024/12/11 12:00:38 by rpelckma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	ldst;
	size_t	lsrc;
	size_t	i;
	size_t	j;

	ldst = ft_strlen(dst);
	lsrc = ft_strlen(src);
	i = 0;
	j = ldst;
	if (ldst < dstsize - 1 && dstsize > 0)
	{
		while (src[i] && (ldst + i < dstsize - 1))
		{
			dst[j] = src[i];
			j++;
			i++;
		}
		dst[j] = 0;
	}
	if (ldst >= dstsize)
		ldst = dstsize;
	return (ldst + lsrc);
}
