/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_render_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 12:05:26 by aolabarr          #+#    #+#             */
/*   Updated: 2024/07/09 10:17:30 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol_bonus.h"

int	render_image_bonus(t_data *data)
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
		if (create_image_bonus(data) == MALLOC_ERROR)
			return (MALLOC_ERROR);
		mlx_put_image_to_window(data->mlx, data->win, data->img.ptr, 0, 0);
		data->update = 0;
	}
	return (0);
}

int	create_image_bonus(t_data *data)
{
	int	x;
	int	y;

	x = 1;
	while (x < WIDTH)
	{
		y = 1;
		while (y < HEIGHT)
		{
			put_color_pixel_bonus(data, data->img, x, y);
			y++;
		}
		x++;
	}
	if (data->julia_dinamic == 0)
		data->julia_dinamic = 1;
	return (0);
}

void	put_color_pixel_bonus(t_data *data, t_image img, int x, int y)
{
	int				offset;
	t_new_data		new_data;
	unsigned int	color;
	float			norm;
	t_complex		aux;

	offset = (img.line_len * y) + x * (img.bpp / 8);
	aux = get_complex_bonus(img.domain, x, y);
	new_data = get_newton_iters(data, data->newton, aux);
	color = 0;
	norm = (float)new_data.iter / data->img.maxiter * 10;
	if (data->newton_tricolor == 1)
	{
		if (new_data.no_root == 1)
			color = encode_rgb(255 * (10 - norm), 0, 0);
		else if (new_data.no_root == 2)
			color = encode_rgb(0, 255 * (10 - norm), 0);
		else if (new_data.no_root == 3)
			color = encode_rgb(0, 0, 255 * (10 - norm));
	}
	else
		color = interpolate_color(img.type, norm, img.palette);
	*(int *)(img.addr + offset) = color;
	return ;
}

t_complex	get_complex_bonus(float *dom, int x, int y)
{
	t_complex	c;

	c.real = dom[0] + (dom[1] - dom[0]) / WIDTH * x;
	c.i = dom[3] - (dom[3] - dom[2]) / HEIGHT * y;
	return (c);
}

unsigned int	encode_rgb(unsigned char r, unsigned char g, unsigned char b)
{
	return ((r << 16) | (g << 8) | (b));
}
