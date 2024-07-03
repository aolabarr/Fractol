/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_libx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 12:49:52 by aolabarr          #+#    #+#             */
/*   Updated: 2024/07/03 15:15:53 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	initial_set_data(t_data *data)
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
	data->img.domain[0] = DOM_MIN;
	data->img.domain[1] = DOM_MAX;
	data->img.domain[2] = DOM_MIN;
	data->img.domain[3] = DOM_MAX;
	data->img.zoom = 1;
	data->img.maxiter = MAXITER;
	data->julia_dinamic = 0;
	data->img.type = ft_strdup(LINEAR);
	data->root_ok = 0;
	return ;
}

void	*new_window(t_data *data, char *title)
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

int	handle_close(t_data *data)
{
	data->close = 1;
	return (0);
}

int	close_window(t_data *data)
{
	if (data->img.ptr)
		mlx_destroy_image(data->mlx, data->img.ptr);
	if (data->img.palette)
		free(data->img.palette);
	if (data->name)
		free(data->name);
	if (data->img.type)
		free(data->img.type);
	data->name = NULL;
	data->name = NULL;
	data->img.palette = NULL;
	data->img.ptr = NULL;
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	ft_putstr_fd(ESC_MESSAGE, STDOUT_FILENO);
	exit(EXIT_SUCCESS);
	return (0);
}
