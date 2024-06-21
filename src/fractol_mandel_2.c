/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_mandel_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 12:52:19 by aolabarr          #+#    #+#             */
/*   Updated: 2024/06/21 13:04:00 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_key_input_mandel(int key, t_mlx_data *data)
{
	if (key == XK_Escape)
	{
		ft_putstr_fd("ESC key has been pressed\n", STDOUT_FILENO);
		if (data->img.com_map)
		{
			ft_tcomplex_mat_free(data->img.com_map, HEIGHT);
			data->img.com_map = NULL;
		}
		if (data->img.iter_map)
		{
			ft_int_mat_free(data->img.iter_map, HEIGHT);
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
	}
	return (0);
}