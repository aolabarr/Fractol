/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 13:01:45 by aolabarr          #+#    #+#             */
/*   Updated: 2024/06/24 16:13:05 by aolabarr         ###   ########.fr       */
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
				*(int *)(img.addr + offset) = interpolate_color(norm, pal);
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
int interpolate_color(double value, int *palette)
{
	int color;
	
	color = 0;
	if (!ft_strncmp(INTERPOLATE_TYPE, "linear", ft_strlen("linear")))
		color = interpol_linear(value, palette);
	else if (!ft_strncmp(INTERPOLATE_TYPE, "bezier", ft_strlen("bezier")))
		color = interpol_bezier(value, palette);
	return (color);
}

int	interpol_linear(double value, int *palette)
{
	double	c1;
	double	c2;
	int		color;

	c1 = palette[(int)(value)];
	c2 = palette[(int)(value) + 1];
	color = (int)(c1 + (c2 - c1) * (value - (int)(value)));
	return (color);
}

int	interpol_bezier(double value, int *palette)
{
	double	t;
	int		i;
	int		color;
	int		n;

	t = value / 10;
	n = PALETTE_SIZE - 1;
	color = 0;
	i = 0;
	while (i <= n)
	{
		color += (double)binomial_coeff(PALETTE_SIZE - 1, i) * ft_pow(1 - t, n - i) * ft_pow(t, i) * palette[i];
		i++;
	}	
	return (color);
}

