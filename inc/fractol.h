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
# include "../lib/libft/src/libft.h"
# include "fractol_color.h"
# include "../lib/minilibx-linux/mlx_int.h"
# include "../lib/minilibx-linux/mlx.h"
# include <math.h>
# include <errno.h>
// Libft: 		stdlib.h unistd.h
// Minilibx:	stdlib.h unistd.h stdio.h string.h fcntl.h

// Types of variables
typedef struct s_complex
{
	float	real;
	float	i;
}			t_complex;

typedef struct s_coef
{
	float	c1;
	float	c2;
}			t_coef;

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
	char		*type;
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
	int			julia_dinamic;
	int			root_ok;
	t_complex	roots[3];
	t_coef		newton;
}			t_data;

// Control parameters
# define EXIT_FAILURE 1
# define MALLOC_ERROR 1

// Messages
# define INPUT_MESSAGE	"\
\n******** FRACTOL ********\n\n\
Introduce correct arguments:\n\n\
-> ./fractol mandelbrot\n\
-> ./fractol julia <real> <imag>\n\n\
****** AND ENJOY ! ******\n\n"

# define MALLOC_MESSAGE	"Malloc error: memory allocate failure\n"
# define ESC_MESSAGE "ESC key o X button of window has been pressed\n"

// Type of fractals
# define MANDELBROT		"mandelbrot"
# define JULIA			"julia"
# define NEWTON			"newton"

//Variable macros
# define WIDTH				500
# define HEIGHT				500
# define MAXITER			100
# define BEZIER			 	"bezier"
# define LINEAR				"linear"
# define ZOOM_FACTOR 		0.1
# define ARROW_MOVE 		0.05
# define DELTA_MAXITER		10
# define MAX_MAXITER		300
# define MIN_MAXITER		10
# define N0_PALLETE			1

//Constant macros
# define ESC_RAD		4.0
# define DOM_MIN		-2.0
# define DOM_MAX		2.0
# define PALETTE_SIZE 	11
# define PLUS_KEY		65453
# define MINUS_KEY		65451
# define PI				3.14159265358979323846
# define TOL			0.00001

// MAIN
void		init_fractal(t_data	*data, int ac, char **av);
int			handle_init_mlx(t_data	*data);
void		handle_perror(void);

//PALETTE
int			init_palette(t_data *data);
int			palette_1(t_data *data);
int			palette_2(t_data *data);
int			palette_3(t_data *data);

// RENDER
int			render_image(t_data *data);
int			create_image(t_data *data);
t_complex	get_complex(float *dom, int x, int y);

//EVENTS
int			mouse_move(int x, int y, t_data *data);
int			mouse_button(int button, int x, int y, t_data *data);
int			mouse_rend(int x, int y, t_data *data);
void		set_mouse_button(t_data *data, t_mouse dif, t_mouse ratio, int key);

// PARSE
int			parse_input(t_data *data, char *real, char *imag, char *name);
int			check_input_error(char *str);

//EQUATIONS
int			mandel_iterator(t_complex C, int maxiter);
int			julia_iterator(t_complex C, t_complex Z, int maxiter);

// LIBX
void		initial_set_data(t_data *data);
void		*new_window(t_data *data, char *title);
int			handle_close(t_data *data);
int			close_window(t_data *data);

// KEYS
int			handle_key_input(int key, t_data *data);
void		set_initial_zoom(t_data *data);
void		set_traslation_move(t_data *data, int key);
void		set_static_zoom(t_data *data, int key);
void		set_maxiter(t_data *data, int key);

// COLOR
void		put_color_pixel(t_data *data, t_image img, int x, int y);
int			get_julia_iters(t_data *data, int x, int y);
int			get_newton_iters(t_data *data, t_coef coefs, t_complex z);
void		get_newton_roots(t_data *data, t_coef coefs);

// INTERPOLATION
int			interpolate_color(char *type, float value, int *palette);
int			interpol_linear(float value, int *palette);
int			interpol_bezier(float value, int *palette);

//UTILS
float		ft_pow(float num, int pow);
int			factorial(int n);
float		binomial_coeff(float n, float k);

t_complex	ft_cpx_divide(t_complex a, t_complex b);
t_complex	ft_cpx_pow(t_complex a, int pow);
t_complex	ft_cpx_multi_escalar(t_complex c, float a);
t_complex	ft_cpx_sum_escalar(t_complex c, float a);

// MEM
void		ft_free_mat_int(int **mat, int size);
int			**ft_malloc_mat_int(int x, int y);

#endif