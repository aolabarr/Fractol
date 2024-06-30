/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_keys.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 10:57:24 by aolabarr          #+#    #+#             */
/*   Updated: 2024/06/30 12:40:41 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_key_input(int key, t_mlx_data *data)
{
	if (key == XK_Escape || data->close == 1)
		close_window(data);
	else if (key == XK_Delete)
		set_initial_zoom(data);
	else if (key == XK_Left || key == XK_Right)
		set_traslation_move(data, key);
	else if (key == XK_Up || key == XK_Down)
		set_traslation_move(data, key);
	else if (key == PLUS_KEY || key == MINUS_KEY)
	{
		set_static_zoom(data, key);
		
	}
	if (key != XK_Escape)
		data->update = 1;
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
		data->img.domain[0] += ARROW_MOVE * data->img.zoom;
		data->img.domain[1] += ARROW_MOVE * data->img.zoom;
	}
	else if (key == XK_Right)
	{
		data->img.domain[0] -= ARROW_MOVE * data->img.zoom;
		data->img.domain[1] -= ARROW_MOVE * data->img.zoom;
	}
	else if (key == XK_Up)
	{
		data->img.domain[2] -= ARROW_MOVE * data->img.zoom;
		data->img.domain[3] -= ARROW_MOVE * data->img.zoom;
	}
	else if (key == XK_Down)
	{
		data->img.domain[2] += ARROW_MOVE * data->img.zoom;
		data->img.domain[3] += ARROW_MOVE * data->img.zoom;
	}
	return ;
}

void	set_static_zoom(t_mlx_data *data, int key)
{
	float	*dom;
	float	dx;
	float	dy;
	
	dom = data->img.domain;
	dx = (dom[1] - dom[0]) * ZOOM_FACTOR;
	dy = (dom[3] - dom[2]) * ZOOM_FACTOR;
	if (key == MINUS_KEY)
	{
		data->img.domain[0] = dom[0] + dx / 2;
		data->img.domain[1] = dom[1] - dx / 2;
		data->img.domain[2] = dom[2] + dy / 2;
		data->img.domain[3] = dom[3] - dy / 2;
		data->img.zoom = data->img.zoom * (1 - ZOOM_FACTOR);
	}
	else if (key == PLUS_KEY)
	{
		data->img.domain[0] = dom[0] - dx / 2;
		data->img.domain[1] = dom[1] + dx / 2;
		data->img.domain[2] = dom[2] - dy / 2;
		data->img.domain[3] = dom[3] + dy / 2;
		data->img.zoom = data->img.zoom * (1 + ZOOM_FACTOR);
	}
	return ;
}


	
