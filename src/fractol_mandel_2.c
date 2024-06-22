/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_mandel_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 12:52:19 by aolabarr          #+#    #+#             */
/*   Updated: 2024/06/22 19:13:19 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_key_input_mandel(int key, t_mlx_data *data)
{
	if (key == XK_Escape || data->close == 1)
		close_window(data);
	return (0);
}

int handle_close(t_mlx_data *data)
{
    data->close = 1;  
    return (0);
}

int	close_window(t_mlx_data *data)
{
	ft_putstr_fd("ESC key has been pressed\n", STDOUT_FILENO);
	if (data->img.com_map)
	{
		ft_free_mat_tcomplex(data->img.com_map, HEIGHT);
		data->img.com_map = NULL;
	}
	if (data->img.iter_map)
	{
		ft_free_mat_int(data->img.iter_map, HEIGHT);
		data->img.iter_map = NULL;
	}
	if (data->img.ptr)
	{
		mlx_destroy_image(data->mlx, data->img.ptr);
		data->img.ptr = NULL;
	}
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(EXIT_SUCCESS);
	return (0);
}
