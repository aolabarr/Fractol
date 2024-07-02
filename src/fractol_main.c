/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 12:41:17 by aolabarr          #+#    #+#             */
/*   Updated: 2024/07/02 17:39:10 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	main(int ac, char **av)
{
	int			exit_value;
	t_mlx_data	data;
	
	if (ac < 2)
		return (EXIT_SUCCESS);
	init_fractal(&data, ac, av);
	exit_value = init_mlx(&data);
	if (exit_value == MALLOC_ERROR)
		return (perror(MALLOC_MESSAGE), EXIT_FAILURE);
	
	return (0);
}

void	init_fractal(t_mlx_data	*data, int ac, char **av)
{
	if (ac == 2 && !ft_strncmp(av[1], MANDELBROT, ft_strlen(av[1])))
		data->name = ft_strdup(MANDELBROT);	
	else if (ac == 4 && !ft_strncmp(av[1], JULIA, ft_strlen(av[1])))
	{
		parse_julia(data, av[2], av[3]);
		data->name = ft_strdup(JULIA);
	}
	else
	{
        perror(INPUT_MESSAGE);
        exit(EXIT_FAILURE);
	}
	initial_set_data(data);
	return ;
}

int init_mlx(t_mlx_data	*data)
{
	if (init_palette(data))
		return (MALLOC_ERROR);
	data->mlx = mlx_init();
	if (!data->mlx)
		return (MALLOC_ERROR);
	if (!new_window(data, data->name))
		return (MALLOC_ERROR);
	//printf("00 - julia C: (%f, %f)\n", data->julia.real,data->julia.i);
	mlx_loop_hook(data->mlx, render_image, data);
	mlx_hook(data->win, DestroyNotify, NoEventMask, handle_close, data);
	mlx_hook(data->win, KeyPress, KeyPressMask, handle_key_input, data);
	if (!ft_strncmp(data->name, MANDELBROT, ft_strlen(data->name)))
	{
		mlx_hook(data->win, MotionNotify, PointerMotionMask, mouse_move, data);
		mlx_hook(data->win, ButtonPress, ButtonPressMask, mouse_button, data);
	}	
	else if (!ft_strncmp(data->name, JULIA, ft_strlen(data->name)))
		mlx_hook(data->win, MotionNotify, PointerMotionMask, mouse_move_render, data);
	mlx_loop(data->mlx);
	return (0);
}

int	init_palette(t_mlx_data *data)
{
	if (N0_PALLETE == 1)
		return (palette_1(data));
	else if (N0_PALLETE == 2)
		return (palette_2(data));
	else if (N0_PALLETE == 3)
		return (palette_3(data));
	return (0);
}
int	palette_1(t_mlx_data *data)
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
int	palette_2(t_mlx_data *data)
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
int	palette_3(t_mlx_data *data)
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


