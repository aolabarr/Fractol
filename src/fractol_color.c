/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 13:01:45 by aolabarr          #+#    #+#             */
/*   Updated: 2024/06/29 16:50:27 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_color_pixel(t_image img, int x, int y)
{
	int			offset;
	int			iter;
	double		norm;
	
	offset = (img.line_len * y) + x * (img.bpp / 8);
    iter = mandel_iterations(get_complex(img.domain, x, y));
	if (iter != MAXITER)
	{
		norm = (double)iter / MAXITER * 10;
		*(int *)(img.addr + offset) = interpolate_color(norm, img.palette);
	}	
	else
		*(int *)(img.addr + offset) = BLACK;
	return ;
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

