/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 12:41:17 by aolabarr          #+#    #+#             */
/*   Updated: 2024/06/24 16:51:10 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	int	stop;
	if (ac < 2)
		return (EXIT_SUCCESS);
	if (ac == 2 && !ft_strncmp(av[1], "mandelbrot", 10))
	{
		stop = mandelbrot();
		if (stop)
			return (perror(INPUT_MESSAGE), EXIT_FAILURE);
	}	
	else if (ac == 2 && !ft_strncmp(av[1], "julia", 10))
		julia();
	else
		return (ft_putstr_fd(INPUT_MESSAGE, STDOUT_FILENO));

	return (0);
}

int mandelbrot(void)
{
	t_mlx_data	data;

	initial_set_data(&data);
	data.mlx = mlx_init();	if (!data.mlx)
		return (MALLOC_ERROR);
	if (!new_window(&data, "Mandelbrot Fractal"))
		return (MALLOC_ERROR);
	mlx_key_hook(data.win, handle_key_input_mandel, &data);
	mlx_loop_hook(data.mlx, render_mandelbrot, &data);
	mlx_hook(data.win, DestroyNotify, NoEventMask, handle_close, &data);
	mlx_hook(data.win, MotionNotify, PointerMotionMask, mouse_move, &data);
	mlx_hook(data.win, ButtonPress, ButtonPressMask, mouse_button, &data);
	mlx_loop(data.mlx);
	return (0);
}

void julia(void)
{
	ft_putstr_fd("Julia fractal INICIO\n", STDOUT_FILENO);
	return ;
}


