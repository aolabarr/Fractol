/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_palette.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 09:19:27 by aolabarr          #+#    #+#             */
/*   Updated: 2024/07/03 09:37:29 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	init_palette(t_data *data)
{
	if (N0_PALLETE == 1)
		return (palette_1(data));
	else if (N0_PALLETE == 2)
		return (palette_2(data));
	else if (N0_PALLETE == 3)
		return (palette_3(data));
	return (0);
}

int	palette_1(t_data *data)
{
	int	*colors;

	colors = malloc(sizeof(int) * 11);
	if (!colors)
		return (MALLOC_ERROR);
	colors[0] = COLOR_0;
	colors[1] = COLOR_1;
	colors[2] = COLOR_2;
	colors[3] = COLOR_3;
	colors[4] = COLOR_4;
	colors[5] = COLOR_5;
	colors[6] = COLOR_6;
	colors[7] = COLOR_7;
	colors[8] = COLOR_8;
	colors[9] = COLOR_9;
	colors[10] = COLOR_10;
	data->img.palette = colors;
	return (0);
}

int	palette_2(t_data *data)
{
	int	*colors;

	colors = malloc(sizeof(int) * 11);
	if (!colors)
		return (MALLOC_ERROR);
	colors[0] = COLOR_20;
	colors[1] = COLOR_21;
	colors[2] = COLOR_22;
	colors[3] = COLOR_23;
	colors[4] = COLOR_24;
	colors[5] = COLOR_25;
	colors[6] = COLOR_26;
	colors[7] = COLOR_27;
	colors[8] = COLOR_28;
	colors[9] = COLOR_29;
	colors[10] = COLOR_30;
	data->img.palette = colors;
	return (0);
}

int	palette_3(t_data *data)
{
	int	*colors;

	colors = malloc(sizeof(int) * 11);
	if (!colors)
		return (MALLOC_ERROR);
	colors[0] = COLOR_40;
	colors[1] = COLOR_41;
	colors[2] = COLOR_42;
	colors[3] = COLOR_43;
	colors[4] = COLOR_44;
	colors[5] = COLOR_45;
	colors[6] = COLOR_46;
	colors[7] = COLOR_47;
	colors[8] = COLOR_48;
	colors[9] = COLOR_49;
	colors[10] = COLOR_50;
	data->img.palette = colors;
	return (0);
}
