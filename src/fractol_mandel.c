/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_mandel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 17:13:34 by aolabarr          #+#    #+#             */
/*   Updated: 2024/06/29 16:50:51 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int render_mandelbrot(t_mlx_data *data)
{
    if (data->close == 1)
        close_window(data);
	else if (data->update == 1)
	{
		if (data->img.ptr)
			mlx_destroy_image(data->mlx, data->img.ptr);
		data->img.ptr = mlx_new_image(data->mlx, WIDTH, HEIGHT);
		data->img.addr = mlx_get_data_addr(data->img.ptr,
											&data->img.bpp,
											&data->img.line_len,
											&data->img.endian);
		data->img.iter_map = NULL;
		if (create_mandelbrot_image(data) == MALLOC_ERROR)
			return (MALLOC_ERROR);
		mlx_put_image_to_window(data->mlx, data->win, data->img.ptr, 0, 0);
        data->update = 0;
	}
	return (0);
}

int    create_mandelbrot_image(t_mlx_data *data)
{
    int			x;
	int			y;
	
	x = 1;
	while (x < WIDTH)
	{
		y = 1;
		while (y < HEIGHT)
		{
			put_color_pixel(data->img, x, y);	
			y++;
		}
		x++;
	}		
    return (0);
}

t_complex	get_complex(double *dom, int x, int y)
{
	t_complex	c;

	c.real = dom[0] + (dom[1] - dom[0]) / WIDTH * x;
    c.i = dom[3] - (dom[3] - dom[2]) / HEIGHT * y;
	return (c);
}

int mandel_iterations(t_complex C)
{
    int         iter;
    double      mod_pw2;
    t_complex   Z;
    t_complex   aux;

    iter = 0;
    mod_pw2 = 0;
    Z.real = 0;
    Z.i = 0;
    while (iter < MAXITER && mod_pw2 < ESC_RAD)
    {
        aux.real = ft_pow(Z.real, 2) - ft_pow(Z.i, 2) + C.real;
        aux.i = 2 * Z.real * Z.i + C.i;
        Z = aux;
        mod_pw2 = ft_pow(Z.real, 2) + ft_pow(Z.i, 2);
        iter++;
    }
    return (iter);
}

