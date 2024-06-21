/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_mandel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 12:47:20 by aolabarr          #+#    #+#             */
/*   Updated: 2024/06/21 12:58:14 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int render_mandelbrot(t_mlx_data *data)
{
	if (data->img.ptr)
		mlx_destroy_image(data->mlx, data->img.ptr);
	data->img.ptr = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.ptr,
											&data->img.bpp,
											&data->img.line_len,
											&data->img.endian);
	//printf("IMG - %p\t%d\t%d\t%d\n",data.img.pix_ptr, data.img.line_len, data.img.bpp, data.img.endian);
	data->img.com_map = NULL;
	data->img.iter_map = NULL;
	create_mandelbrot_image(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.ptr, 0, 0);
	return (0);
}

void    create_mandelbrot_image(t_mlx_data *data)
{
    data->img.com_map = get_complex_map();
	data->img.iter_map = get_iter_map(data->img.com_map);
    ft_tcomplex_mat_free(data->img.com_map, HEIGHT);
	put_color_image(data->img, data->img.iter_map);
    ft_int_mat_free(data->img.iter_map, HEIGHT);
    data->img.com_map = NULL;
    data->img.iter_map = NULL;
    //rintf("%p\t%p\n", data->mlx, data->img.ptr);
    //mlx_destroy_image(data->mlx, data->img.ptr);
    return ;
}
int     **get_iter_map(t_complex **c_map)
{
    int **map;
    int x;
    int y;

    
    map = malloc(sizeof(int *) * HEIGHT);
    y = 0;
    while (y < HEIGHT)
        map[y++] = malloc(sizeof(int) * WIDTH);
    y = 0;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            map[y][x] = mandel_iterations(c_map[y][x]);
            x++;
        }
        y++;
    }
    return (map);
}

t_complex   **get_complex_map(void)
{
    //Pero con Zoom hay que cambiar ancho y alto
    t_complex   **map;
    int         x;
    int         y;

    map = malloc(sizeof(t_complex *) * HEIGHT);
    y = 0;
    while (y < HEIGHT)
        map[y++] = malloc(sizeof(t_complex) * WIDTH);
    map[0][0].real = DOM_MIN;
    map[0][0].i = DOM_MAX;
    y = 0;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            map[y][x].real = DOM_MIN + (DOM_MAX - DOM_MIN) / WIDTH * x;
            map[y][x].i = DOM_MAX - (DOM_MAX - DOM_MIN) / HEIGHT * y;
            x++;
        }
        y++;
    }
    return (map);
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
        aux.real = pow2(Z.real) - pow2(Z.i) + C.real;
        aux.i = 2 * Z.real * Z.i + C.i;
        Z = aux;
        mod_pw2 = pow2(Z.real) + pow2(Z.i);
        iter++;
    }
    return (iter);
}

