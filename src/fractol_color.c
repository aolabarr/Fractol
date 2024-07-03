/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 13:01:45 by aolabarr          #+#    #+#             */
/*   Updated: 2024/07/03 15:18:10 by aolabarr         ###   ########.fr       */
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
	else if (!ft_strncmp(data->name, NEWTON, ft_strlen(NEWTON)))
	{
		aux = get_complex(img.domain, x, y);
		iter = get_newton_iters(data, data->newton, aux);
	}
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

int	get_newton_iters(t_data *data, t_coef coefs, t_complex z)
{
	int			iter;
	float		mod_0;
	float		mod_1;
	float		aux;

	if (data->root_ok == 0)
		get_newton_roots(data, coefs);
	printf("root 1: (%f, %f)\n", data->roots[0].real,  data->roots[0].i);
	iter = 0;
	mod_0 = 0;
	mod_1 = z.real * z.real + z.i * z.i;
	while (iter < data->img.maxiter && mod_1 - mod_0 > TOL)
	{
		aux = coefs.c1 * (ft_pow(z.real, 3) - 3 * z.real * ft_pow(z.i, 2) + coefs.c2);
		z.real = z.real - aux / (3 * coefs.c1 * (ft_pow(z.real, 2) - ft_pow(z.i, 2)));
		aux = coefs.c1 * (3 * z.i * ft_pow(z.real, 2) - ft_pow(z.i, 3));
		z.i = z.i - aux / (3 * coefs.c1 * (ft_pow(z.real, 2) - ft_pow(z.i, 2)));
		mod_0 = mod_1;
		mod_1 = z.real * z.real + z.i * z.i;
		iter++;
	}
	//printf("iter: %d\tmod: %f\n", iter, mod_1);
	return (iter);
}
void	get_newton_roots(t_data *data, t_coef coefs)
{
	float		mod;
	float		theta;
	int			i;

	mod = cbrt(coefs.c2 / coefs.c1);
	theta = - PI;
	printf("theta: %f\n", theta);
	i = 0;
	while (i < 3)
	{
		data->roots[i].real = mod * cos((theta + 2 * PI * i) / 3);
		data->roots[i].i = mod * sin((theta + 2 * PI * i) / 3);
		i++;
	}
	data->root_ok = 1;
	return ;
}
