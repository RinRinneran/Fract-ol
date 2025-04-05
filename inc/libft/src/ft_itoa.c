/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelckma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:41:03 by rpelckma          #+#    #+#             */
/*   Updated: 2024/12/11 11:41:20 by rpelckma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static int	ft_len(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char			*fnl;
	int				size;
	unsigned int	nb;

	nb = n;
	size = ft_len(n) + 1;
	fnl = (char *)malloc(size * sizeof(char));
	if (!fnl)
		return (NULL);
	if (n < 0)
	{
		nb = -n;
		fnl[0] = '-';
	}
	if (n == 0)
		fnl[0] = '0';
	fnl[--size] = '\0';
	while (--size >= 0 && nb)
	{
		fnl[size] = nb % 10 + '0';
		nb /= 10;
	}
	return (fnl);
}
