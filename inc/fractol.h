/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 21:41:35 by marvin            #+#    #+#             */
/*   Updated: 2024/06/13 21:41:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

// Libraries
#include "../lib/libft/src/libft.h"
#include "fractol_color.h"
#include "../lib/minilibx-linux/mlx_int.h"
#include "../lib/minilibx-linux/mlx.h"
#include <math.h>
// Libft: 		stdlib.h unistd.h
// Minilibx:	stdlib.h unistd.h stdio.h string.h fcntl.h


// Types of variables
typedef struct s_complex
{
	float	real;
	float	i;
}			t_complex;

typedef struct s_image
{
	void		*ptr;
	void		*addr;
	int			bpp;
	int			line_len;
	int			endian;
	int			update;
	float		domain[4];
	float		zoom;
	int			*palette;
	int			maxiter;
}				t_image;

typedef struct s_mouse
{
	float	x;
	float	y;
}			t_mouse;

typedef struct s_mlx_data
{
	void		*mlx;
	void		*win;
	char		*name;
	t_image		img;
	int			close;
	int			update;
	t_mouse		mouse;
	t_complex	julia;
}			t_mlx_data;


// Control parameters
# define EXIT_FAILURE 1
# define MALLOC_ERROR 1

// Error messages
# define INPUT_MESSAGE	"instrucciones\n"
# define MALLOC_MESSAGE	"Malloc error: memory allocate failure\n"

// Type of fractals
# define MANDELBROT		"mandelbrot"
# define JULIA			"julia"
# define NEWTON			"newton"

//Variable macros
# define WIDTH				800
# define HEIGHT				800
# define MAXITER			100
# define INTERPOLATE_TYPE 	"linear"
# define ZOOM_FACTOR 		0.1
# define ARROW_MOVE 		0.05
# define DELTA_MAXITER		10
# define MAX_MAXITER		300
# define MIN_MAXITER		10

//Constant macros
# define ESC_RAD		4.0
# define DOM_MIN		-2.0
# define DOM_MAX		2.0
# define PALETTE_SIZE 	11
# define PLUS_KEY		65453
# define MINUS_KEY		65451


// MAIN
void		init_fractal(t_mlx_data	*data, int ac, char **av);
int			init_mlx(t_mlx_data	*data);
int			init_palette(t_mlx_data *data);

// RENDER
int			render_image(t_mlx_data *data);
int			create_image(t_mlx_data *data);
t_complex	get_complex(float *dom, int x, int y);

// PARSE
void		parse_julia(t_mlx_data *data, char *real, char *imag);
int			check_input_error(char *str);

//EQUATIONS
int			mandel_iterator(t_complex C, int maxiter);
int			julia_iterations(t_complex C, t_complex Z);

// LIBX
void		initial_set_data(t_mlx_data *data);
void		*new_window(t_mlx_data *data, char *title);
int			handle_close(t_mlx_data *data);
int			close_window(t_mlx_data *data);

// KEYS
int			handle_key_input(int key, t_mlx_data *data);
void		set_initial_zoom(t_mlx_data *data);
void		set_traslation_move(t_mlx_data *data, int key);
void		set_static_zoom(t_mlx_data *data, int key);

// COLOR
int			interpolate_color(float value, int *palette);
int			interpol_bezier(float value, int *palette);
int			interpol_linear(float value, int *palette);
void		put_color_pixel(t_mlx_data *data, t_image img, int x, int y);

// MEM
void		ft_free_mat_int(int **mat, int size);
int			**ft_malloc_mat_int(int x, int y);

//UTILS
float 		ft_pow(float num, int pow);
int			factorial(int n);
float 		binomial_coeff(float n, float k);

//EVENTS
int			mouse_move(int x, int y, t_mlx_data *data);
int			mouse_button(int button, int x, int y, t_mlx_data *data);
int			mouse_move_render(int x, int y, t_mlx_data *data);

#endif