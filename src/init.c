/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelckma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 12:47:40 by rpelckma          #+#    #+#             */
/*   Updated: 2025/04/07 20:41:45 by rpelckma         ###   ########.fr       */
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

int	ft_print_julia_presets(void)
{
	ft_putendl_fd("Julia Set suggestions", 1);
	ft_putendl_fd("  0.285 0.01        → Twisted seahorse shapes", 1);
	ft_putendl_fd("  0.355 0.355       → Dense dendritic structure", 1);
	ft_putendl_fd("  0.37 -0.1         → Nebula-like spirals", 1);
	ft_putendl_fd("  -0.70176 -0.3842  → Classic Julia (connected, filled)", 1);
	ft_putendl_fd("  -0.4 0.6          → Lightning/cracked glass pattern", 1);
	ft_putendl_fd("  -0.8 0.156        → Delicate symmetric spirals", 1);
	ft_putendl_fd("  -0.7269 0.1889    → Detailed, swirling structure", 1);
	ft_putendl_fd("  0.0 0.8           → Funnel/vortex shape", 1);
	ft_putendl_fd("  -0.2 0.75         → Pinched, shell-like forms", 1);
	ft_putendl_fd("  -1.476 0.0        → Thin flower petal structures", 1);
	return (1);
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
