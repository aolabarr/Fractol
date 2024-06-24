/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_libx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 12:49:52 by aolabarr          #+#    #+#             */
/*   Updated: 2024/06/24 17:24:22 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	initial_set_data(t_mlx_data *data)
{
	data->mlx = NULL;
	data->win = NULL;
	data->close = 0;
	data->img.ptr = NULL;
	data->img.addr = NULL;
	data->img.bpp = 0;
	data->img.line_len = 0;
	data->img.endian = 0;
	data->update = 1;
	data->img.iter_map = NULL;
	data->img.domain[0] = DOM_MIN;
	data->img.domain[1] = DOM_MAX;
	data->img.domain[2] = DOM_MIN;
	data->img.domain[3] = DOM_MAX;
	data->img.zoom = ZOOM_FACTOR;
	return ;
}

void	*new_window(t_mlx_data *data, char *title)
{
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, title);
	if (!data->win)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		return (NULL);
	}
	return (data->win);
}
