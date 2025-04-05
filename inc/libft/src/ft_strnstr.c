/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelckma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:58:39 by rpelckma          #+#    #+#             */
/*   Updated: 2024/12/11 11:58:45 by rpelckma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	n_len;
	char	*hs;

	i = 0;
	hs = (char *)haystack;
	n_len = ft_strlen(needle);
	if (n_len == 0 || haystack == needle)
		return (hs);
	while (hs[i] && i < len)
	{
		j = 0;
		while (hs[i + j] && needle[j] && hs[i + j] == needle[j] && i + j < len)
			j++;
		if (j == n_len)
			return (hs + i);
		i++;
	}
	return (0);
}
