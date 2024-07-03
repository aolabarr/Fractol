/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_events.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 12:00:03 by aolabarr          #+#    #+#             */
/*   Updated: 2024/07/03 10:45:37 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	mouse_move(int x, int y, t_data *data)
{
	data->mouse.x = x;
	data->mouse.y = y;
	return (0);
}

int	mouse_rend(int x, int y, t_data *data)
{
	data->mouse.x = x;
	data->mouse.y = y;
	data->update = 1;
	return (0);
}

int	mouse_button(int key, int x, int y, t_data *data)
{
	float	*dom;
	t_mouse	pos;
	t_mouse	dif;
	t_mouse	ratio;

	dom = data->img.domain;
	pos.x = (dom[1] - dom[0]) / WIDTH * x + dom[0];
	pos.y = (dom[3] - dom[2]) / HEIGHT * y + dom[2];
	dif.x = (dom[1] - dom[0]) * ZOOM_FACTOR;
	dif.y = (dom[3] - dom[2]) * ZOOM_FACTOR;
	ratio.x = (pos.x - dom[0]) / (dom[1] - dom[0]);
	ratio.y = (pos.y - dom[2]) / (dom[3] - dom[2]);
	set_mouse_button(data, dif, ratio, key);
	data->update = 1;
	return (0);
}

void	set_mouse_button(t_data *data, t_mouse dif, t_mouse ratio, int key)
{
	float	*dom;

	dom = data->img.domain;
	if (key == 4)
	{
		data->img.domain[0] = dom[0] + dif.x * ratio.x;
		data->img.domain[1] = dom[1] - dif.x * (1 - ratio.x);
		data->img.domain[2] = dom[2] + dif.y * ratio.y;
		data->img.domain[3] = dom[3] - dif.y * (1 - ratio.y);
		data->img.zoom = data->img.zoom * (1 - ZOOM_FACTOR);
	}
	else if (key == 5)
	{
		data->img.domain[0] = dom[0] - dif.x * ratio.x;
		data->img.domain[1] = dom[1] + dif.x * (1 - ratio.x);
		data->img.domain[2] = dom[2] - dif.y * ratio.y;
		data->img.domain[3] = dom[3] + dif.y * (1 - ratio.y);
		data->img.zoom = data->img.zoom * (1 + ZOOM_FACTOR);
	}
	return ;
}
