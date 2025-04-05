/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_terminal_colors.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelckma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 12:10:17 by rpelckma          #+#    #+#             */
/*   Updated: 2024/12/11 13:04:33 by rpelckma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include "../inc/libft.h"

void	print_terminal_colors(void)
{
	int	i;

	i = 0;
	while (i < 256)
	{
		printf(" \e[1;48;5;%im%i%s\e[0m", i, i, i < 100 ? " " : "");
		if (i == 15 || !((i - 15) % 36))
			printf("\n");
		i++;
	}
	printf("\n");
	i = 0;
	while (i < 256)
	{
		printf("\e[1;48;5;%im  \e[0m", i);
		if (i == 15 || !((i - 15) % 36))
			printf("\n");
		i++;
	}
	printf("\n");
	printf("\\e[1m | \e[1m BOLD\033[0m \n");
	printf("\\e[3m | \e[3m ITALIC\033[0m\n");
	printf("\\e[4m | \e[4m UNDERLINE\033[0m\n");
	printf("\\e[9m | \e[9m STRIKETHROUGH\033[0m\n");
	printf("\n");
}*/
