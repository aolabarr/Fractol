/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_libx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 12:49:52 by aolabarr          #+#    #+#             */
/*   Updated: 2024/06/30 11:15:25 by aolabarr         ###   ########.fr       */
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
	data->img.zoom = 1;
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

int handle_close(t_mlx_data *data)
{
    data->close = 1;  
    return (0);
}

int	close_window(t_mlx_data *data)
{
	ft_putstr_fd("ESC key o X button of window has been pressed\n", STDOUT_FILENO);
	if (data->img.ptr)
	{
		mlx_destroy_image(data->mlx, data->img.ptr);
		data->img.ptr = NULL;
	}
	if (data->img.palette)
	{
		free(data->img.palette);
		data->img.palette = NULL;
	}
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(EXIT_SUCCESS);
	return (0);
}
