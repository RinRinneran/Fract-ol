/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mnk_input_handling.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelckma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 12:23:42 by rpelckma          #+#    #+#             */
/*   Updated: 2025/04/05 11:49:39 by rpelckma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	zoom(t_fractal *fractal, int x, int y, int zoom_direction)
{
	double	zoom_lvl;

	zoom_lvl = 1.1;
	if (zoom_direction == 1)
	{
		fractal->offset_x = (x / fractal->zoom + fractal->offset_x) - (x
				/ (fractal->zoom * zoom_lvl));
		fractal->offset_y = (y / fractal->zoom + fractal->offset_y) - (y
				/ (fractal->zoom * zoom_lvl));
		fractal->zoom *= zoom_lvl;
	}
	else if (zoom_direction == -1)
	{
		fractal->offset_x = (x / fractal->zoom + fractal->offset_x) - (x
				/ (fractal->zoom / zoom_lvl));
		fractal->offset_y = (y / fractal->zoom + fractal->offset_y) - (y
				/ (fractal->zoom / zoom_lvl));
		fractal->zoom /= zoom_lvl;
	}
}

int	key_hook(int key_code, t_fractal *fractal)
{
	if (key_code == ESC)
		exit_fractal(fractal);
	else if (key_code == LEFT)
		fractal->offset_x -= 42 / fractal->zoom;
	else if (key_code == RIGHT)
		fractal->offset_x += 42 / fractal->zoom;
	else if (key_code == DOWN)
		fractal->offset_y += 42 / fractal->zoom;
	else if (key_code == UP)
		fractal->offset_y -= 42 / fractal->zoom;
	else if (key_code == C)
		fractal->color_scheme = (fractal->color_scheme + (255 * 255 * 255)
				/ 100) % (255 * 255 * 255);
	else if (key_code == M || key_code == P)
		change_iter(fractal, key_code);
	draw_fractal(fractal, fractal->name);
	return (0);
}

int	mouse_hook(int mouse_code, int x, int y, t_fractal *fractal)
{
	if (mouse_code == SCROLL_UP)
		zoom(fractal, x, y, 1);
	else if (mouse_code == SCROLL_DOWN)
		zoom(fractal, x, y, -1);
	draw_fractal(fractal, fractal->name);
	return (0);
}
