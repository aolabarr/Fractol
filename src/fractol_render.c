/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 13:36:10 by aolabarr          #+#    #+#             */
/*   Updated: 2024/07/03 09:54:31 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	render_image(t_data *data)
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
		if (create_image(data) == MALLOC_ERROR)
			return (MALLOC_ERROR);
		mlx_put_image_to_window(data->mlx, data->win, data->img.ptr, 0, 0);
		data->update = 0;
	}
	return (0);
}

int	create_image(t_data *data)
{
	int	x;
	int	y;

	x = 1;
	while (x < WIDTH)
	{
		y = 1;
		while (y < HEIGHT)
		{
			put_color_pixel(data, data->img, x, y);
			y++;
		}
		x++;
	}
	if (data->julia_dinamic == 0)
		data->julia_dinamic = 1;
	return (0);
}

t_complex	get_complex(float *dom, int x, int y)
{
	t_complex	c;

	c.real = dom[0] + (dom[1] - dom[0]) / WIDTH * x;
	c.i = dom[3] - (dom[3] - dom[2]) / HEIGHT * y;
	return (c);
}
