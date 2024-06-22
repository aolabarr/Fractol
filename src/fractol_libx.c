/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_libx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 12:49:52 by aolabarr          #+#    #+#             */
/*   Updated: 2024/06/21 14:53:58 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	initial_set_data(t_mlx_data *data)
{
	data->mlx = NULL;
	data->win = NULL;
	data->img.ptr = NULL;
	data->img.addr = NULL;
	data->img.bpp = 0;
	data->img.line_len = 0;
	data->img.endian = 0;
	data->img.update = 1;
	data->img.com_map = NULL;
	data->img.iter_map = NULL;
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
