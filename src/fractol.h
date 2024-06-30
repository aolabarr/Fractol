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

#include "../lib/libft/src/libft.h"
#include "../lib/minilibx-linux/mlx_int.h"
#include "../lib/minilibx-linux/mlx.h"

// LIBFT 	stdlib.h unistd.h
// MINILIBX stdlib.h unistd.h stdio.h string.h fcntl.h
#include <math.h>

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
	int			**iter_map;
	float		domain[4];
	float		zoom;
	int			*palette;
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
	t_image		img;
	int			close;
	int			update;
	t_mouse		mouse;
	t_complex	julia;
}			t_mlx_data;

# define EXIT_FAILURE 1
# define MALLOC_ERROR 1
# define INPUT_MESSAGE "instrucciones\n"
# define MALLOC_MESSAGE "Malloc error: memory allocate failure\n"

//Variable macros
# define WIDTH				800
# define HEIGHT				800
# define MAXITER			100
# define INTERPOLATE_TYPE 	"linear"
# define ZOOM_FACTOR 		0.1
# define ARROW_MOVE 		0.05

//Constant macros
# define ESC_RAD		4.0
# define DOM_MIN		-2.0
# define DOM_MAX		2.0
# define PALETTE_SIZE 	11
# define PLUS_KEY		65453
# define MINUS_KEY		65451


//Color palette - divergent points
#define COLOR_0  0x7FFF00  // Chartreuse
#define COLOR_1  0x00FF00  // Green
#define COLOR_2  0x0000FF  // Blue
#define COLOR_3  0x3F00FF  // Blue-Violet
#define COLOR_4  0x7F00FF  // Violet
#define COLOR_5  0xBF00FF  // Purple
#define COLOR_6  0xFF00FF  // Magenta
#define COLOR_7  0xFF007F  // Rose
#define COLOR_8  0xFF0000  // Red
#define COLOR_9  0xFF7F00  // Orange
#define COLOR_10  0xFFFF00  // Yellow

//Color palette - covergent points
#define GREEN       0x00FF00 // Verde
#define YELLOW      0xFFFF00 // Amarillo
#define ORANGE      0xFFA500 // Naranja
#define PINK        0xFFC0CB // Rosa
#define TEAL        0x008080 // Verde azulado
#define BLACK       0x000000 // Negro

// MAIN
int			mandelbrot(void);
int			julia(t_complex c);
int			color_palette(t_mlx_data *data);

// MANDELBROT
int			render_mandelbrot(t_mlx_data *data);
int			create_mandelbrot_image(t_mlx_data *data);
int			mandel_iterations(t_complex c);
t_complex	get_complex(float *dom, int x, int y);

// JULIA
t_complex   parse_julia(char *real, char *imag);
int			check_input_error(char *str);

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
void		put_color_pixel(t_image img, int x, int y);

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

#endif