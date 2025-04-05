/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utls.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelckma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 11:57:41 by rpelckma          #+#    #+#             */
/*   Updated: 2025/04/05 11:47:52 by rpelckma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	color_pixel(t_fractal *fractal, int x, int y, int color)
{
	int	*buffer;

	buffer = fractal->img_data;
	buffer[(y * fractal->line_size / 4) + x] = color;
}

int	ft_check_arguments(int ac, char **av)
{
	if (ac != 2 && ac != 4)
		return (0);
	else if (ac == 4 && (ft_strncmp(av[1], "ship", 5) == 0 || ft_strncmp(av[1],
				"mandel", 7) == 0))
		return (0);
	else if (ac == 4)
	{
		if ((ft_is_valid_nbr(av[2]) > 0) && (ft_is_valid_nbr(av[3]) > 0))
			return (1);
		else
			return (0);
	}
	else
		return (1);
}

int	exit_fractal(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->image);
	fractal->image = NULL;
	mlx_destroy_window(fractal->mlx, fractal->window);
	fractal->window = NULL;
	mlx_destroy_display(fractal->mlx);
	free(fractal->mlx);
	fractal->mlx = NULL;
	free(fractal);
	exit(1);
	return (0);
}

void	change_iter(t_fractal *fractal, int key_code)
{
	if (key_code == M)
	{
		if (fractal->max_iterations > 42)
			fractal->max_iterations -= 42;
	}
	else if (key_code == P)
	{
		if (fractal->max_iterations < 4200)
			fractal->max_iterations += 42;
	}
}
