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

#include "../lib/libft/libft.h"
#include "../lib/minilibx-linux/mlx_int.h"
#include "../lib/minilibx-linux/mlx.h"

typedef unsigned char byte;

typedef struct s_mlx_data
{
	void	*mlx;
	void	*win;
	t_img	img;
}			t_mlx_data;

# define EXIT_FAILURE 1
# define MALLOC_ERROR 1
# define INPUT_MESSAGE "instrucciones"

# define WIDTH 500
# define HEIGHT 500

int		mandelbrot(void);
void	julia(void);
int		handle_input(int key, t_mlx_data *data);
void	image_color(t_img img, int color);
int	encode_rgb(byte red, byte green, byte blue);


#endif