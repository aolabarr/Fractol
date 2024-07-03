/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 13:01:45 by aolabarr          #+#    #+#             */
/*   Updated: 2024/07/03 11:08:04 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	put_color_pixel(t_data *data, t_image img, int x, int y)
{
	int			offset;
	int			iter;
	int			color;
	float		norm;
	t_complex	aux;

	offset = (img.line_len * y) + x * (img.bpp / 8);
	if (!ft_strncmp(data->name, MANDELBROT, ft_strlen(data->name)))
	{
		aux = get_complex(img.domain, x, y);
		iter = mandel_iterator(aux, data->img.maxiter);
	}
	if (!ft_strncmp(data->name, JULIA, ft_strlen(data->name)))
		iter = get_julia_iters(data, img, x, y);
	if (iter != data->img.maxiter)
	{
		norm = (float)iter / data->img.maxiter * 10;
		color = interpolate_color(img.type, norm, img.palette);
		*(int *)(img.addr + offset) = color;
	}
	else
		*(int *)(img.addr + offset) = BLACK;
	return ;
}

int	get_julia_iters(t_data *data, t_image img, int x, int y)
{
	int			iter;
	t_complex	aux1;
	t_complex	aux2;

	if (data->julia_dinamic == 0)
	{
		aux1 = get_complex(img.domain, x, y);
		iter = julia_iterator(data->julia, aux1, data->img.maxiter);
	}
	else
	{
		aux1 = get_complex(img.domain, data->mouse.x, data->mouse.y);
		aux2 = get_complex(img.domain, x, y);
		iter = julia_iterator(aux1, aux2, data->img.maxiter);
	}
	return (iter);
}

int	interpolate_color(char *type, float value, int *palette)
{
	int	color;

	color = 0;
	if (!ft_strncmp(type, LINEAR, ft_strlen(type)))
		color = interpol_linear(value, palette);
	else if (!ft_strncmp(type, BEZIER, ft_strlen(type)))
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

int	interpol_bezier(float value, int *pal)
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
		aux = ft_pow(1 - value / 10, n - i) * ft_pow(value / 10, i) * pal[i];
		color += (float)binomial_coeff(PALETTE_SIZE - 1, i) * aux;
		i++;
	}
	return (color);
}
