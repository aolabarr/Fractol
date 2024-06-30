/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 12:41:17 by aolabarr          #+#    #+#             */
/*   Updated: 2024/06/30 10:56:34 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	int	stop;
	
	if (ac < 2)
		return (EXIT_SUCCESS);
	if (ac == 2 && !ft_strncmp(av[1], "mandelbrot", ft_strlen(av[1])))
		stop = mandelbrot();	
	else if (ac == 4 && !ft_strncmp(av[1], "julia", 10))
		stop = julia();
	else
		return (perror(INPUT_MESSAGE), EXIT_FAILURE);
	if (stop)
		return (perror(MALLOC_MESSAGE), EXIT_FAILURE);
	return (0);
}

int mandelbrot(void)
{
	t_mlx_data	data;

	initial_set_data(&data);
	if (color_palette(&data))
		return (MALLOC_ERROR);
	data.mlx = mlx_init();
	if (!data.mlx)
		return (MALLOC_ERROR);
	if (!new_window(&data, "Mandelbrot Fractal"))
		return (MALLOC_ERROR);
	mlx_loop_hook(data.mlx, render_mandelbrot, &data);
	mlx_hook(data.win, DestroyNotify, NoEventMask, handle_close, &data);
	mlx_hook(data.win, KeyPress, KeyPressMask, handle_key_input, &data);
	mlx_hook(data.win, MotionNotify, PointerMotionMask, mouse_move, &data);
	mlx_hook(data.win, ButtonPress, ButtonPressMask, mouse_button, &data);
	mlx_loop(data.mlx);
	return (0);
}

int julia(void)
{
	ft_putstr_fd("Julia fractal INICIO\n", STDOUT_FILENO);
	return (0);
}
int	color_palette(t_mlx_data *data)
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


