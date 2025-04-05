/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelckma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:50:44 by rpelckma          #+#    #+#             */
/*   Updated: 2024/12/11 11:50:54 by rpelckma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dst_tmp;
	const char	*src_temp;

	dst_tmp = dst;
	src_temp = src;
	if (dst_tmp == src_temp)
		return (dst_tmp);
	while (n > 0)
	{
		*dst_tmp = *src_temp;
		dst_tmp++;
		src_temp++;
		n--;
	}
	return (dst);
}
