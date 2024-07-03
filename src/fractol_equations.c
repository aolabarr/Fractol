/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_equations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 09:38:26 by aolabarr          #+#    #+#             */
/*   Updated: 2024/07/03 09:48:07 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

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
