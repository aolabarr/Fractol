/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 12:41:17 by aolabarr          #+#    #+#             */
/*   Updated: 2024/07/03 11:38:12 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	main(int ac, char **av)
{
	int		exit_value;
	t_data	data;

	if (ac < 2)
		return (EXIT_SUCCESS);
	init_fractal(&data, ac, av);
	exit_value = init_mlx(&data);
	if (exit_value == MALLOC_ERROR)
		return (handle_perror(), EXIT_FAILURE);
	return (0);
}
void	handle_perror(void)
{
	if (errno == ENOMEM)
		perror(MALLOC_MESSAGE);
	return ;
}

void	init_fractal(t_data	*data, int ac, char **av)
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
		ft_putstr_fd(INPUT_MESSAGE, STDOUT_FILENO);
		exit(EXIT_FAILURE);
	}
	initial_set_data(data);
	return ;
}

int	init_mlx(t_data	*data)
{
	if (init_palette(data))
		return (MALLOC_ERROR);
	data->mlx = mlx_init();
	if (!data->mlx)
		return (MALLOC_ERROR);
	if (!new_window(data, data->name))
		return (MALLOC_ERROR);
	mlx_loop_hook(data->mlx, render_image, data);
	mlx_hook(data->win, DestroyNotify, NoEventMask, handle_close, data);
	mlx_hook(data->win, KeyPress, KeyPressMask, handle_key_input, data);
	if (!ft_strncmp(data->name, MANDELBROT, ft_strlen(data->name)))
	{
		mlx_hook(data->win, MotionNotify, PointerMotionMask, mouse_move, data);
		mlx_hook(data->win, ButtonPress, ButtonPressMask, mouse_button, data);
	}
	else if (!ft_strncmp(data->name, JULIA, ft_strlen(data->name)))
		mlx_hook(data->win, MotionNotify, PointerMotionMask, mouse_rend, data);
	mlx_loop(data->mlx);
	return (0);
}
