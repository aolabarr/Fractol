/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_equations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 09:38:26 by aolabarr          #+#    #+#             */
/*   Updated: 2024/07/07 15:37:23 by aolabarr         ###   ########.fr       */
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

	iter = 0;
	offset = (img.line_len * y) + x * (img.bpp / 8);
	if (!ft_strncmp(data->name, MANDELBROT, ft_strlen(MANDELBROT)))
	{
		aux = get_complex(img.domain, x, y);
		iter = mandel_iterator(aux, data->img.maxiter);
	}
	else if (!ft_strncmp(data->name, JULIA, ft_strlen(JULIA)))
		iter = get_julia_iters(data, x, y);
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

int	get_julia_iters(t_data *data, int x, int y)
{
	int			iter;
	t_complex	aux1;
	t_complex	aux2;

	if (data->julia_dinamic == 0)
	{
		aux1 = get_complex(data->img.domain, x, y);
		iter = julia_iterator(data->julia, aux1, data->img.maxiter);
	}
	else
	{
		aux1 = get_complex(data->img.domain, data->mouse.x, data->mouse.y);
		aux2 = get_complex(data->img.domain, x, y);
		iter = julia_iterator(aux1, aux2, data->img.maxiter);
	}
	return (iter);
}

int	mandel_iterator(t_complex c, int maxiter)
{
	int			iter;
	float		mod_pw2;
	t_complex	z;
	t_complex	aux;

	iter = 0;
	mod_pw2 = 0;
	z.real = 0;
	z.i = 0;
	while (iter < maxiter && mod_pw2 < ESC_RAD)
	{
		aux.real = z.real * z.real - z.i * z.i + c.real;
		aux.i = 2 * z.real * z.i + c.i;
		z = aux;
		mod_pw2 = z.real * z.real + z.i * z.i;
		iter++;
	}
	return (iter);
}

int	julia_iterator(t_complex c, t_complex z, int maxiter)
{
	int			iter;
	float		mod_pw2;
	t_complex	aux;

	iter = 0;
	mod_pw2 = z.real * z.real + z.i * z.i;
	while (iter < maxiter && mod_pw2 < ESC_RAD)
	{
		aux.real = z.real * z.real - z.i * z.i + c.real;
		aux.i = 2 * z.real * z.i + c.i;
		z = aux;
		mod_pw2 = z.real * z.real + z.i * z.i;
		iter++;
	}
	return (iter);
}
