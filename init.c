/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelckma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 12:47:40 by rpelckma          #+#    #+#             */
/*   Updated: 2025/04/05 12:11:22 by rpelckma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	ft_is_valid_nbr(const char *str)
{
	int	has_digit;
	int	decimal_count;

	if (!str || !*str)
		return (0);
	has_digit = 0;
	decimal_count = 0;
	if (*str == '+' || *str == '-')
		str++;
	while (*str)
	{
		if (ft_isdigit(*str))
			has_digit = 1;
		else if (*str == '.' && decimal_count == 0)
			decimal_count++;
		else
			return (0);
		str++;
	}
	return (has_digit);
}

void	init_fractal(t_fractal *fractal)
{
	fractal->mlx = NULL;
	fractal->window = NULL;
	fractal->image = NULL;
	fractal->img_data = NULL;
	fractal->bpp = 0;
	fractal->line_size = 0;
	fractal->endian = 0;
	fractal->name = NULL;
	fractal->max_iterations = 42;
	fractal->color_scheme = 0xFCBE11;
	fractal->z_real = 0.0;
	fractal->z_img = 0.0;
	fractal->c_real = 0.0;
	fractal->c_img = 0.0;
	fractal->julia_real = 0.0;
	fractal->julia_img = 0.0;
	fractal->custom_params = 0;
	fractal->zoom = 300.0;
	fractal->offset_x = -((SIZE / 2.0) / fractal->zoom);
	fractal->offset_y = -((SIZE / 2.0) / fractal->zoom);
}

void	init_mlx(t_fractal *fractal)
{
	fractal->mlx = mlx_init();
	fractal->window = mlx_new_window(fractal->mlx, SIZE, SIZE, "Fract-ol");
	fractal->image = mlx_new_image(fractal->mlx, SIZE, SIZE);
	fractal->img_data = mlx_get_data_addr(fractal->image, &fractal->bpp,
			&fractal->line_size, &fractal->endian);
}
