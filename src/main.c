/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelckma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 10:48:19 by rpelckma          #+#    #+#             */
/*   Updated: 2025/04/07 20:42:15 by rpelckma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static void	select_fractal(t_fractal *fractal, char *query,
		void (**calc_function)(t_fractal *, int, int))
{
	if (ft_strncmp(query, "mandel", 7) == 0)
	{
		fractal->name = "mandel";
		*calc_function = calc_mandel;
	}
	else if (ft_strncmp(query, "julia", 6) == 0)
	{
		fractal->name = "julia";
		if (!fractal->custom_params)
		{
			fractal->julia_real = -0.745429;
			fractal->julia_img = 0.05;
		}
		*calc_function = calc_julia;
	}
	else if (ft_strncmp(query, "ship", 5) == 0)
	{
		fractal->name = "ship";
		*calc_function = calc_ship;
	}
	else
	{
		ft_putendl_fd("fractals: mandel, julia, ship", 1);
		exit_fractal(fractal);
	}
}

int	draw_fractal(t_fractal *fractal, char *query)
{
	void	(*calc_function)(t_fractal *, int, int);

	select_fractal(fractal, query, &calc_function);
	draw_fractal_loop(fractal, calc_function);
	mlx_put_image_to_window(fractal->mlx, fractal->window, fractal->image, 0,
		0);
	return (0);
}

static void	set_fractal_coords(t_fractal *f, int x, int y, int img_size)
{
	if (ft_strncmp(f->name, "julia", 6) == 0)
	{
		f->z_real = ((x - img_size / 2.0) / f->zoom) + f->offset_x;
		f->z_img = ((y - img_size / 2.0) / f->zoom) + f->offset_y;
		if (f->custom_params)
		{
			f->c_real = f->julia_real;
			f->c_img = f->julia_img;
		}
		else
		{
			f->c_real = -0.7;
			f->c_img = 0.27015;
		}
	}
	else
	{
		f->z_real = 0;
		f->z_img = 0;
		f->c_real = ((x - img_size / 2.0) / f->zoom) + f->offset_x;
		f->c_img = ((y - img_size / 2.0) / f->zoom) + f->offset_y;
	}
}

void	draw_fractal_loop(t_fractal *fractal, void (*calc_function)(t_fractal *,
			int, int))
{
	int	x;
	int	y;
	int	img_size;

	img_size = fractal->line_size / (fractal->bpp / 8);
	x = 0;
	while (x < img_size)
	{
		y = 0;
		while (y < img_size)
		{
			set_fractal_coords(fractal, x, y, img_size);
			calc_function(fractal, x, y);
			y++;
		}
		x++;
	}
}

int	main(int argc, char **argv)
{
	t_fractal	*fractal;

	if (ft_check_arguments(argc, argv) == 0)
	{
		ft_putendl_fd(USAGE_MSG_1, 1);
		ft_putendl_fd(USAGE_MSG_2, 1);
		return (ft_print_julia_presets());
	}
	fractal = malloc(sizeof(t_fractal));
	if (!fractal)
		return (1);
	init_fractal(fractal);
	if (argc == 4 && ft_strncmp(argv[1], "julia", 6) == 0)
	{
		fractal->custom_params = 1;
		fractal->julia_real = ft_atodbl(argv[2]);
		fractal->julia_img = ft_atodbl(argv[3]);
	}
	init_mlx(fractal);
	mlx_key_hook(fractal->window, key_hook, fractal);
	mlx_mouse_hook(fractal->window, mouse_hook, fractal);
	mlx_hook(fractal->window, 17, 0L, exit_fractal, fractal);
	draw_fractal(fractal, argv[1]);
	mlx_loop(fractal->mlx);
	return (0);
}
