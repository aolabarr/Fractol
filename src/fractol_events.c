/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_events.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 12:00:03 by aolabarr          #+#    #+#             */
/*   Updated: 2024/07/02 17:08:10 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	mouse_move(int x, int y, t_mlx_data *data)
{
	
	data->mouse.x = x;
	data->mouse.y = y;
	return (0);
}

int	mouse_move_render(int x, int y, t_mlx_data *data)
{
	data->mouse.x = x;
	data->mouse.y = y;
	data->update = 1;
	return (0);
}

int	mouse_button(int key, int x, int y, t_mlx_data *data)
{
	float	*dom;
	float	pos[2];
	float	dif[2];
	float	ratio[2];
	
	dom = data->img.domain;
	pos[0] = (dom[1] - dom[0]) / WIDTH * x + dom[0];
	pos[1] = (dom[3] - dom[2]) / HEIGHT * y + dom[2];
	dif[0] = (dom[1] - dom[0]) * ZOOM_FACTOR;
	dif[1] = (dom[3] - dom[2]) * ZOOM_FACTOR;
	ratio[0] = (pos[0] - dom[0]) / (dom[1] - dom[0]);
	ratio[1] = (pos[1] - dom[2]) / (dom[3] - dom[2]);
	set_mouse_button(data, dif, ratio, key);
	/*
	if (key == 4)
	{
		data->img.domain[0] = dom[0] + dif[0] * ratio[0];
		data->img.domain[1] = dom[1] - dif[0] * (1- ratio[0]);
		data->img.domain[2] = dom[2] + dif[1] * ratio[1];
		data->img.domain[3] = dom[3] - dif[1] * (1- ratio[1]);
		data->img.zoom = data->img.zoom * (1 - ZOOM_FACTOR);
	}
	else if (key == 5)
	{
		data->img.domain[0] = dom[0] - dif[0] * ratio[0];
		data->img.domain[1] = dom[1] + dif[0] * (1- ratio[0]);
		data->img.domain[2] = dom[2] - dif[1] * ratio[1];
		data->img.domain[3] = dom[3] + dif[1] * (1- ratio[1]);
		data->img.zoom = data->img.zoom * (1 + ZOOM_FACTOR);
	}
	*/
	data->update = 1;
	return (0);
}
void	set_mouse_button(t_mlx_data *data, float *dif, float *ratio, int key)
{
	float	*dom;

	dom = data->img.domain;
	if (key == 4)
	{
		data->img.domain[0] = dom[0] + dif[0] * ratio[0];
		data->img.domain[1] = dom[1] - dif[0] * (1- ratio[0]);
		data->img.domain[2] = dom[2] + dif[1] * ratio[1];
		data->img.domain[3] = dom[3] - dif[1] * (1- ratio[1]);
		data->img.zoom = data->img.zoom * (1 - ZOOM_FACTOR);
	}
	else if (key == 5)
	{
		data->img.domain[0] = dom[0] - dif[0] * ratio[0];
		data->img.domain[1] = dom[1] + dif[0] * (1- ratio[0]);
		data->img.domain[2] = dom[2] - dif[1] * ratio[1];
		data->img.domain[3] = dom[3] + dif[1] * (1- ratio[1]);
		data->img.zoom = data->img.zoom * (1 + ZOOM_FACTOR);
	}
	return ;
}
