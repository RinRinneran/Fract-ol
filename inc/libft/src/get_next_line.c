/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelckma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 12:07:15 by rpelckma          #+#    #+#             */
/*   Updated: 2024/12/11 12:07:47 by rpelckma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

size_t	ft_strlen(const char *str);
char	*read_file(int fd, char *main_str);
char	*return_func(char *main_str);
char	*reset(char *main_str);

char	*get_next_line(int fd)
{
	static char	*main_str[1024];
	char		*return_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	main_str[fd] = read_file(fd, main_str[fd]);
	if (!main_str[fd])
		return (NULL);
	return_str = return_func(main_str[fd]);
	main_str[fd] = reset(main_str[fd]);
	return (return_str);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*read_file(int fd, char *main_str)
{
	int		i;
	char	*buffer_str;

	i = 1;
	buffer_str = malloc(BUFFER_SIZE + 1);
	if (!buffer_str)
		return (NULL);
	while (!ft_strchr(main_str, '\n') && i != 0)
	{
		i = read(fd, buffer_str, BUFFER_SIZE);
		if (i == -1)
		{
			free(buffer_str);
			return (NULL);
		}
		buffer_str[i] = '\0';
		main_str = ft_strjoin(main_str, buffer_str);
	}
	free(buffer_str);
	return (main_str);
}

char	*return_func(char *main_str)
{
	char	*next_line;
	int		i;

	i = 0;
	if (!main_str[i])
		return (NULL);
	while (main_str[i] && main_str[i] != '\n')
		i++;
	i++;
	next_line = ft_substr(main_str, 0, i);
	return (next_line);
}

char	*reset(char *main_str)
{
	char	*rest;
	int		i;

	i = 0;
	while (main_str[i] && main_str[i] != '\n')
		i++;
	i++;
	rest = ft_substr(main_str, i, ft_strlen(main_str));
	if (rest[0] == '\0')
	{
		free(rest);
		rest = NULL;
	}
	free(main_str);
	return (rest);
}
