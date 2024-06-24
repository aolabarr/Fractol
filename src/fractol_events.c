/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_events.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 12:00:03 by aolabarr          #+#    #+#             */
/*   Updated: 2024/06/24 17:27:20 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_move(int x, int y, t_mlx_data *data)
{
	
	data->mouse.x = x;
	data->mouse.y = y;
	return (0);
}

int	mouse_button(int key, int x, int y, t_mlx_data *data)
{
	double	*cur;
	double	fact;
	double	pos[2];
	double dx;
	double dy;
	
	cur = data->img.domain;
	pos[0] = (cur[1] - cur[0]) / WIDTH * x + cur[0];
	pos[1] = (cur[3] - cur[2]) / HEIGHT * y + cur[2];
	fact = (cur[1] - cur[0]) * data->img.zoom / 100;
	dx = (pos[0] - cur[0]) / (cur[1] - cur[0]);
	dy = (pos[1] - cur[2]) / (cur[3] - cur[2]);

	if (key == 4)
	{
		data->img.domain[0] = cur[0] + fact * dx;
		data->img.domain[1] = cur[1] - fact * (1 - dx);
		data->img.domain[2] = cur[2] + fact * dy;
		data->img.domain[3] = cur[3] - fact * (1 - dy);
	}
	else if (key == 5)
	{
		data->img.domain[0] = cur[0] - fact * dx;
		data->img.domain[1] = cur[1] + fact * (1 - dx);
		data->img.domain[2] = cur[2] - fact * dy;
		data->img.domain[3] = cur[3] + fact * (1 - dy);
	}
	data->update = 1;
	return (0);
}
