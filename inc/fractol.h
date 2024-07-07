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
	float	c3;
	float	c4;
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
	t_complex	center;
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
	int			no_root;
	t_coef		newton;
	int			newton_tricolor;
}			t_data;

// Exit parameters
# define EXIT_FAILURE 1
# define MALLOC_ERROR 1

// Messages
# define INPUT_MESSAGE	"\
\n******** FRACTOL ********\n\n\
Introduce correct arguments:\n\n\
	-> ./fractol mandelbrot\n\n\
	-> ./fractol julia <real> <imag>\n\n\
        p.e.: ./fractol julia -0.8  0.156\n\
              ./fractol julia 0.355 0.355\n\n\
To see the control set buttons:\n\n\
	-> ./fractol control\n\n\
****** AND ENJOY ! ******\n\n"

# define CONTROL_MESSAGE "\
\n****************     FRACTOL     ****************\n\n\
This are the control options:\n\n\
	-> Traslate image:		Arrows (Up / Down / Left / Rigth)\n\
	-> Central zoom in / out:	+ / -\n\
	-> Mouse direction zoom:	Move the mouse scroll button\n\
	-> More image accuracy:		p	(less render speed)\n\
	-> Less image accuracy:		m	(more render speed)\n\
	-> Reset zoom & accuracy:	delete\n\
	-> Linear color mode:		l\n\
	-> Bezier color mode:		b	(poor render speed)\n\n\
	NOTE: Changing the accuracy the color changes\n\n\
**************     AND ENJOY !     **************\n\n"

# define MALLOC_MESSAGE	"\nMalloc error: memory allocate failure\n"
# define ESC_MESSAGE "\nESC key o X button of window has been pressed\n"

// Type of fractals
# define MANDELBROT		"mandelbrot"
# define JULIA			"julia"
# define NEWTON			"newton"
# define CONTROL		"control"

//Variable macros
# define WIDTH				800
# define HEIGHT				800
# define MAXITER			100
# define BEZIER			 	"bezier"
# define LINEAR				"linear"
# define ZOOM_FACTOR 		0.1
# define ARROW_MOVE 		0.05
# define DELTA_MAXITER		10
# define MAX_MAXITER		300
# define MIN_MAXITER		10
# define N0_PALLETE			2

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
int			handle_scroll(int button, int x, int y, t_data *data);
int			mouse_rend(int x, int y, t_data *data);
void		set_scroll_button(t_data *data, t_mouse dif, int key);
void		set_domain(t_data *data, t_mouse dif, float scale);

// PARSE
int			parse_input(t_data *data, char *real, char *imag, char *name);
int			check_input_error(char *str);

//EQUATIONS
void		put_color_pixel(t_data *data, t_image img, int x, int y);
int			get_julia_iters(t_data *data, int x, int y);
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

// INTERPOLATION
int			interpolate_color(char *type, float value, int *palette);
int			interpol_linear(float value, int *palette);
int			interpol_bezier(float value, int *palette);

//UTILS
float		ft_pow(float num, int pow);
int			factorial(int n);
float		binomial_coeff(float n, float k);

#endif