/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_mandel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 12:47:20 by aolabarr          #+#    #+#             */
/*   Updated: 2024/06/23 18:04:48 by aolabarr         ###   ########.fr       */
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
		data->img.com_map = NULL;
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
    get_complex_map(data);
	if (get_iter_map(data) == MALLOC_ERROR)
		return (MALLOC_ERROR);
    palette = color_palette();
	if (!palette)
		return (MALLOC_ERROR);
	put_color_image(data->img, data->img.iter_map, palette);
    free(palette);
	ft_free_mat_tcomplex(data->img.com_map, HEIGHT);
    ft_free_mat_int(data->img.iter_map, HEIGHT);
    data->img.com_map = NULL;
    data->img.iter_map = NULL;
    return (0);
}
int     get_iter_map(t_mlx_data *data)
{
    int **map;
    int x;
    int y;

	map = ft_malloc_mat_int(WIDTH, HEIGHT);
	if (!map)
		return (MALLOC_ERROR);
    y = 0;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            map[y][x] = mandel_iterations(data->img.com_map[y][x]);
            x++;
        }
        y++;
    }
	data->img.iter_map = map;
    return (0);
}

int   get_complex_map(t_mlx_data *data)
{
    t_complex   **map;
    int         x;
    int         y;
    double		*dom;

    dom = data->img.domain;
    map = ft_malloc_mat_tcomplex(WIDTH, HEIGHT);
    y = 0;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            map[y][x].real = dom[0] + (dom[1] - dom[0]) / WIDTH * x;
            map[y][x].i = dom[3] - (dom[3] - dom[2]) / HEIGHT * y;
            //map[y][x].real = DOM_MIN + (DOM_MAX - DOM_MIN) / WIDTH * x;
            //map[y][x].i = DOM_MAX - (DOM_MAX - DOM_MIN) / HEIGHT * y;
            x++;
        }
        y++;
    }
	data->img.com_map = map;
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
        aux.real = pow(Z.real, 2) - pow(Z.i, 2) + C.real;
        aux.i = 2 * Z.real * Z.i + C.i;
        Z = aux;
        mod_pw2 = pow(Z.real, 2) + pow(Z.i, 2);
        iter++;
    }
    return (iter);
}

