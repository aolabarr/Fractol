/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 13:01:45 by aolabarr          #+#    #+#             */
/*   Updated: 2024/06/22 17:38:50 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void put_color_image(t_image img, int **iter_map, int *pal)
{
	int		x;
	int		y;
	int		offset;
	double	norm;

	x = 1;
	while (x < WIDTH)
	{
		y = 1;
		while (y < HEIGHT)
		{	
			offset = (img.line_len * y) + x * (img.bpp / 8);
			if (iter_map[y][x] != MAXITER)
			{
				norm = (double)iter_map[y][x] / MAXITER * 10;
				*(int *)(img.addr + offset) = interpolated_color(norm, pal);
			}	
			else
				*(int *)(img.addr + offset) = BLACK;
			y++;
		}
		x++;
	}		
}
int *color_palette(void)
{
	int	*colors;

	colors = malloc(sizeof(int) * 11);
	if (!colors)
		return (NULL);
	colors[0] = COLOR_0;
	colors[1] = COLOR_1;
	colors[2] = COLOR_2;
	colors[3] = COLOR_3;
	colors[4] = COLOR_4;
	colors[5] = COLOR_5;
	colors[6] = COLOR_6;
	colors[7] = COLOR_7;
	colors[8] = COLOR_8;
	colors[9] = COLOR_9;
	colors[10] = COLOR_10;
	return (colors);
}
int	interpolated_color(double value, int *palette)
{
	double	c1;
	double	c2;
	int		color;

	c1 = palette[(int)trunc(value)];
	c2 = palette[(int)ceil(value)];
	color = (int)trunc(c1 + (c2 - c1) * (value - trunc(value)));
	return (color);
}
