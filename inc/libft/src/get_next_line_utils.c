/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelckma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 12:08:15 by rpelckma          #+#    #+#             */
/*   Updated: 2024/12/11 12:08:52 by rpelckma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			if ((char)c == str[i])
				return ((char *)&str[i]);
			i++;
		}
		if ((char)c == str[i])
			return ((char *)&str[i]);
	}
	return (NULL);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (s[0] == 0 || ft_strlen(s) <= start)
		return (ft_strdup(""));
	sub = NULL;
	if (len > ft_strlen(s))
		sub = malloc(ft_strlen(s) + 1);
	else
		sub = malloc(len + 1);
	if (!sub)
		return (NULL);
	while (i < len && s[start])
	{
		sub[i] = s[start];
		i++;
		start++;
	}
	sub[i] = 0;
	return (sub);
}

char	*ft_strdup(char *s1)
{
	char	*output_str;
	int		i;

	output_str = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	i = 0;
	if (!output_str)
		return (NULL);
	while (s1[i])
	{
		output_str[i] = s1[i];
		i++;
	}
	output_str[i] = '\0';
	return (output_str);
}

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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	size_t	size_s1;
	size_t	size_s2;
	size_t	i;

	if (s1 == NULL)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = 0;
	}
	i = 0;
	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	new = malloc(size_s1 + size_s2 + 1);
	if (!new)
		return (NULL);
	while (i < size_s1 + 1)
	{
		((char *)new)[i] = ((char *)s1)[i];
		i++;
	}
	ft_strlcat(new, s2, size_s1 + size_s2 + 1);
	free(s1);
	return (new);
}
