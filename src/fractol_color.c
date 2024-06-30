/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 13:01:45 by aolabarr          #+#    #+#             */
/*   Updated: 2024/06/30 18:29:09 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_color_pixel(t_mlx_data *data, t_image img, int x, int y)
{
	int			offset;
	int			iter;
	float		norm;
	
	offset = (img.line_len * y) + x * (img.bpp / 8);
	if (!ft_strncmp(data->name, "mandelbrot", ft_strlen("mandelbrot")))
    	iter = mandel_iterations(get_complex(img.domain, x, y));
	if (!ft_strncmp(data->name, "julia", ft_strlen("julia")))
		iter = julia_iterations(data->julia, get_complex(img.domain, x, y));
	if (iter != MAXITER)
	{
		norm = (float)iter / MAXITER * 10;
		*(int *)(img.addr + offset) = interpolate_color(norm, img.palette);
		//*(int *)(img.addr + offset) = YELLOW;
	}	
	else
		*(int *)(img.addr + offset) = BLACK;
	return ;
}

int interpolate_color(float value, int *palette)
{
	int color;
	
	color = 0;
	if (!ft_strncmp(INTERPOLATE_TYPE, "linear", ft_strlen("linear")))
		color = interpol_linear(value, palette);
	else if (!ft_strncmp(INTERPOLATE_TYPE, "bezier", ft_strlen("bezier")))
		color = interpol_bezier(value, palette);
	return (color);
}

int	interpol_linear(float value, int *palette)
{
	float	c1;
	float	c2;
	int		color;

	c1 = palette[(int)(value)];
	c2 = palette[(int)(value) + 1];
	color = (int)(c1 + (c2 - c1) * (value - (int)(value)));
	return (color);
}

int	interpol_bezier(float value, int *palette)
{
	float	aux;
	int		color;
	int		i;
	int		n;

	n = PALETTE_SIZE - 1;
	color = 0;
	i = 0;
	while (i <= n)
	{
		aux = ft_pow(1 - value / 10, n - i) * ft_pow(value / 10, i) * palette[i];
		color += (float)binomial_coeff(PALETTE_SIZE - 1, i) * aux;
		i++;
	}	
	return (color);
}

