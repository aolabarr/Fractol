/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_mandel_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 12:52:19 by aolabarr          #+#    #+#             */
/*   Updated: 2024/06/24 17:27:14 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_key_input_mandel(int key, t_mlx_data *data)
{
	if (key == XK_Escape || data->close == 1)
		close_window(data);
	else if (key == XK_Delete)
		set_initial_zoom(data);
	else if (key == XK_Left || key == XK_Right)
		set_traslation_move(data, key);
	else if (key == XK_Up || key == XK_Down)
		set_traslation_move(data, key);
	if (key != XK_Escape)
		data->update = 1;
	return (0);
}

int handle_close(t_mlx_data *data)
{
    data->close = 1;  
    return (0);
}

int	close_window(t_mlx_data *data)
{
	ft_putstr_fd("ESC key o X button of window has been pressed\n", STDOUT_FILENO);
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
void	set_traslation_move(t_mlx_data *data, int key)
{
	if (key == XK_Left)
	{
		data->img.domain[0] += ARROW_MOVE * data->img.zoom / 100;
		data->img.domain[1] += ARROW_MOVE * data->img.zoom / 100;
	}
	else if (key == XK_Right)
	{
		data->img.domain[0] -= ARROW_MOVE * data->img.zoom / 100;
		data->img.domain[1] -= ARROW_MOVE * data->img.zoom / 100;
	}
	else if (key == XK_Up)
	{
		data->img.domain[2] -= ARROW_MOVE * data->img.zoom / 100;
		data->img.domain[3] -= ARROW_MOVE * data->img.zoom / 100;
	}
	else if (key == XK_Down)
	{
		data->img.domain[2] += ARROW_MOVE * data->img.zoom / 100;
		data->img.domain[3] += ARROW_MOVE * data->img.zoom / 100;
	}
	return ;
}


	
