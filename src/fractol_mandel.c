/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_mandel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 17:13:34 by aolabarr          #+#    #+#             */
/*   Updated: 2024/06/24 17:27:11 by aolabarr         ###   ########.fr       */
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
		//printf("IMG - %p\t%d\t%d\t%d\n",data->img.addr, data->img.line_len, data->img.bpp, data->img.endian);
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
    int *palette;
    
	if (get_iter_map(data) == MALLOC_ERROR)
		return (MALLOC_ERROR);
    palette = color_palette();
	if (!palette)
		return (MALLOC_ERROR);
	put_color_image(data->img, data->img.iter_map, palette);
    free(palette);
    ft_free_mat_int(data->img.iter_map, HEIGHT);
    data->img.iter_map = NULL;
    return (0);
}
int     get_iter_map(t_mlx_data *data)
{
    t_complex	c;
	double		*dom;
    int			**map;
    int			x;
    int			y;

	map = ft_malloc_mat_int(WIDTH, HEIGHT);
	if (!map)
		return (MALLOC_ERROR);
	dom = data->img.domain;
    y = 0;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
			c.real = dom[0] + (dom[1] - dom[0]) / WIDTH * x;
            c.i = dom[3] - (dom[3] - dom[2]) / HEIGHT * y;
            map[y][x] = mandel_iterations(c);
            x++;
        }
        y++;
    }
	data->img.iter_map = map;
    return (0);
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

