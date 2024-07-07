/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_events.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 12:00:03 by aolabarr          #+#    #+#             */
/*   Updated: 2024/07/07 15:49:33 by aolabarr         ###   ########.fr       */
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

int	handle_scroll(int key, int x, int y, t_data *data)
{
	float	*dom;
	t_mouse	pos;
	t_mouse	dif;

	dom = data->img.domain;
	pos.x = (dom[1] - dom[0]) / WIDTH * x + dom[0];
	pos.y = dom[3] - (dom[3] - dom[2]) / HEIGHT * y;
	dif.x = pos.x - data->img.center.real;
	dif.y = pos.y - data->img.center.i;
	set_scroll_button(data, dif, key);
	data->update = 1;
	return (0);
}

void	set_scroll_button(t_data *data, t_mouse dif, int key)
{
	if (key == 4)
		set_domain(data, dif, (1 - ZOOM_FACTOR));
	else if (key == 5)
		set_domain(data, dif, (1 + ZOOM_FACTOR));
	return ;
}

void	set_domain(t_data *data, t_mouse dif, float scale)
{
	float	width;
	float	height;

	width = data->img.domain[1] - data->img.domain[0];
	height = data->img.domain[3] - data->img.domain[2];
	data->img.center.real = data->img.center.real + (dif.x * scale);
	data->img.center.i = data->img.center.i + (dif.y * scale);
	data->img.domain[0] = data->img.center.real - width * scale / 2;
	data->img.domain[1] = data->img.center.real + width * scale / 2;
	data->img.domain[2] = data->img.center.i - height * scale / 2;
	data->img.domain[3] = data->img.center.i + height * scale / 2;
	data->img.zoom = data->img.zoom * (1 - ZOOM_FACTOR);
	return ;
}
