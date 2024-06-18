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

typedef unsigned char byte;

typedef struct s_complex
{
	double	real;
	double	i;
}			t_complex;

typedef struct s_image
{
	void	*ptr;
	void	*pix_ptr;
	int		bpp;
	int		line_len;
	int		endian;
	int		**iter_map;
	t_complex	**com_map;
}				t_image;

typedef struct s_mlx_data
{
	void	*mlx;
	void	*win;
	t_image	img;
}			t_mlx_data;



# define EXIT_FAILURE 1
# define MALLOC_ERROR 1
# define INPUT_MESSAGE "instrucciones"

# define WIDTH 1000
# define HEIGHT 1000

# define MAXITER 100
# define ESC_RAD 4.0
# define DOM_MIN -2.0
# define DOM_MAX 2.0

#define RED         0xFF0000 // Rojo
#define GREEN       0x00FF00 // Verde
#define BLUE        0x0000FF // Azul
#define YELLOW      0xFFFF00 // Amarillo
#define CYAN        0x00FFFF // Cian
#define MAGENTA     0xFF00FF // Magenta
#define ORANGE      0xFFA500 // Naranja
#define PURPLE      0x800080 // Púrpura
#define BROWN       0xA52A2A // Marrón
#define PINK        0xFFC0CB // Rosa
#define LIME        0x00FF00 // Lima
#define TEAL        0x008080 // Verde azulado
#define BLACK       0x000000 // Negro


int		mandelbrot(void);
void	julia(void);
int		handle_input_mandelbrot(int key, t_mlx_data *data);
void	image_color(t_image img, int **iter_map);
int		encode_rgb(byte red, byte green, byte blue);

// MANDELBROT
int     **get_iter_map(t_complex **c_map);
t_complex   **get_complex_map(void);
int			mandel_iterations(t_complex c);
int			pow2(double num);


#endif