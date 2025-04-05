/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelckma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 11:22:46 by rpelckma          #+#    #+#             */
/*   Updated: 2025/04/04 19:44:14 by rpelckma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	calc_mandel(t_fractal *f, int x, int y)
{
	int		i;
	double	temp;

	f->z_real = 0.0;
	f->z_img = 0.0;
	f->c_real = (x / f->zoom) + f->offset_x;
	f->c_img = (y / f->zoom) + f->offset_y;
	i = 0;
	while (i < f->max_iterations)
	{
		temp = f->z_real * f->z_real - f->z_img * f->z_img + f->c_real;
		f->z_img = 2 * f->z_real * f->z_img + f->c_img;
		f->z_real = temp;
		if (f->z_real * f->z_real + f->z_img * f->z_img >= __DBL_MAX__)
			break ;
		i++;
	}
	if (i == f->max_iterations)
		color_pixel(f, x, y, 0x000000);
	else
		color_pixel(f, x, y, f->color_scheme * i);
}

void	calc_julia(t_fractal *f, int x, int y)
{
	int		i;
	double	temp;

	f->z_real = x / f->zoom + f->offset_x;
	f->z_img = y / f->zoom + f->offset_y;
	if (!f->custom_params)
	{
		f->julia_real = -0.745429;
		f->julia_img = 0.05;
	}
	i = 0;
	while (i < f->max_iterations)
	{
		temp = f->z_real * f->z_real - f->z_img * f->z_img + f->julia_real;
		f->z_img = 2 * f->z_img * f->z_real + f->julia_img;
		f->z_real = temp;
		if (f->z_real * f->z_real + f->z_img * f->z_img >= 4.0)
			break ;
		i++;
	}
	if (i == f->max_iterations)
		color_pixel(f, x, y, 0x000000);
	else
		color_pixel(f, x, y, f->color_scheme * i);
}

void	calc_ship(t_fractal *f, int x, int y)
{
	int		i;
	double	temp;

	f->z_real = 0.0;
	f->z_img = 0.0;
	f->c_real = (x / f->zoom) + f->offset_x;
	f->c_img = (y / f->zoom) + f->offset_y;
	i = 0;
	while (i < f->max_iterations)
	{
		temp = f->z_real * f->z_real - f->z_img * f->z_img + f->c_real;
		f->z_img = fabs(2.0 * f->z_real * f->z_img) + f->c_img;
		f->z_real = fabs(temp);
		if (f->z_real * f->z_real + f->z_img * f->z_img >= __DBL_MAX__)
			break ;
		i++;
	}
	if (i == f->max_iterations)
		color_pixel(f, x, y, 0x000000);
	else
		color_pixel(f, x, y, f->color_scheme * i);
}
