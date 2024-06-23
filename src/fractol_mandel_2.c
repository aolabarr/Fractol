/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_mandel_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 12:52:19 by aolabarr          #+#    #+#             */
/*   Updated: 2024/06/23 17:57:17 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_key_input_mandel(int key, t_mlx_data *data)
{
	if (key == XK_Escape || data->close == 1)
		close_window(data);
	else if (key == XK_space)
		set_initial_zoom(data);
		
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
void	set_initial_zoom(t_mlx_data *data)
{
	data->img.domain[0] = DOM_MIN;
	data->img.domain[1] = DOM_MAX;
	data->img.domain[2] = DOM_MIN;
	data->img.domain[3] = DOM_MAX;
	data->update = 1;
	return ;
}
	
