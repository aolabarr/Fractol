/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_complex_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 01:31:20 by marvin            #+#    #+#             */
/*   Updated: 2024/07/07 18:15:51 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

t_complex	ft_cpx_divide(t_complex a, t_complex b)
{
	t_complex	c;
	float		div;
	float		aux;

	div = b.real * b.real + b.i * b.i;
	aux = a.real * b.real + a.i * b.i;
	c.real = aux / div;
	aux = a.i * b.real - a.real * b.i;
	c.i = aux / div;
	return (c);
}

t_complex	ft_cpx_pow(t_complex a, int pow)
{
	int			i;
	t_complex	aux;
	t_complex	c;

	c.real = a.real;
	c.i = a.i;
	i = 1;
	while (i < pow)
	{
		aux.real = c.real * a.real - c.i * a.i;
		aux.i = c.real * a.i + c.i * a.real;
		c = aux;
		i++;
	}
	return (c);
}

t_complex	ft_cpx_multi_escalar(t_complex c, float a)
{
	t_complex	res;

	res.real = c.real * a;
	res.i = c.i * a;
	return (res);
}

t_complex	ft_cpx_sum_escalar(t_complex c, float a)
{
	t_complex	res;

	res.real = c.real + a;
	res.i = c.i;
	return (res);
}
