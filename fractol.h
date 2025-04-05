/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelckma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 10:47:39 by rpelckma          #+#    #+#             */
/*   Updated: 2025/04/05 12:06:18 by rpelckma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./libft/inc/libft.h"
# include "./minilibx-linux/mlx.h"
# include <math.h>

# define SIZE 1000

# define ESC 65307
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define C 99
# define P 112
# define M 109
# define SCROLL_UP 4
# define SCROLL_DOWN 5

typedef struct s_fractal
{
	// MLX-related
	void	*mlx;
	void	*window;
	void	*image;
	void	*img_data;
	int		bpp;
	int		line_size;
	int		endian;

	// Fractal properties
	char	*name;
	int		max_iterations;
	int		color_scheme;

	// Complex Plane Parameters
	double	z_real;
	double	z_img;
	double	c_real;
	double	c_img;

	// Julia Set Parameters
	double	julia_real;
	double	julia_img;
	int		custom_params;

	// Viewport Controls
	double	offset_x;
	double	offset_y;
	double	zoom;
}			t_fractal;

void		color_pixel(t_fractal *fractal, int x, int y, int color);
int			ft_is_valid_nbr(const char *str);
int			exit_fractal(t_fractal *fractal);
int			ft_check_arguments(int ac, char **av);
double		gen_random_c(void);
void		change_iter(t_fractal *fractal, int key_code);
void		init_fractal(t_fractal *fractal);
void		init_mlx(t_fractal *fractal);
void		calc_mandel(t_fractal *fractal, int x, int y);
void		calc_julia(t_fractal *fractal, int x, int y);
void		calc_ship(t_fractal *fractal, int x, int y);
int			draw_fractal(t_fractal *fractal, char *query);
void		draw_fractal_loop(t_fractal *fractal,
				void (*calc_function)(t_fractal *, int, int));
int			key_hook(int key_code, t_fractal *fractal);
int			mouse_hook(int mouse_code, int x, int y, t_fractal *fractal);

#endif
