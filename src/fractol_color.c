/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 13:01:45 by aolabarr          #+#    #+#             */
/*   Updated: 2024/06/21 13:02:24 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void put_color_image(t_image img, int **iter_map)
{
	int		x;
	int		y;
	int		offset;
	int		color1;
	int		color2;

	x = 1;
	color1 = YELLOW;
	color2 = BLUE;
	while (x < WIDTH)
	{
		//printf("Prueba 600\tx: %d\n", x);
		y = 1;
		while (y < HEIGHT)
		{	
			//printf("Prueba 700\titer: %d\n", iter_map[x][y]);
			offset = (img.line_len * y) + x * (img.bpp / 8);
			if (iter_map[y][x] != MAXITER)
				*(int *)(img.addr + offset) = (color1 + color2) / 2 * iter_map[y][x];
			else
				*(int *)(img.addr + offset) = BLACK;
			y++;
		}
		x++;
	}		
}

int	encode_rgb(byte red, byte green, byte blue)
{
	return (red << 16 | green << 8 | blue);
}
