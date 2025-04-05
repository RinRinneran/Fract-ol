/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelckma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:36:43 by rpelckma          #+#    #+#             */
/*   Updated: 2024/12/11 11:36:57 by rpelckma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*tem;

	i = 0;
	tem = (unsigned char *)s;
	while (n > i)
	{
		tem[i] = 0;
		i++;
	}
	s = tem;
}
