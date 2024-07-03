/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_interpol.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 13:31:34 by aolabarr          #+#    #+#             */
/*   Updated: 2024/07/03 13:32:13 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

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
