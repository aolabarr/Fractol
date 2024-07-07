/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_main_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 10:59:50 by aolabarr          #+#    #+#             */
/*   Updated: 2024/07/07 18:21:43 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol_bonus.h"

int	main(int ac, char **av)
{
	int		control;
	t_data	data;

	if (ac < 2)
		return (EXIT_SUCCESS);
	init_fractal_bonus(&data, ac, av);
	control = handle_init_mlx_bonus(&data);
	if (control == MALLOC_ERROR)
		return (handle_perror_bonus(), EXIT_FAILURE);
	return (0);
}

void	handle_perror_bonus(void)
{
	if (errno == ENOMEM)
		perror(MALLOC_MESSAGE);
	return ;
}

void	init_fractal_bonus(t_data *data, int ac, char **av)
{
	if (ac == 4)
		parse_input_bonus(data, av);
	if (ac == 4 && !ft_strncmp(av[1], NEWTON, ft_strlen(NEWTON)))
		data->name = ft_strdup(NEWTON);
	else if (!ft_strncmp(av[1], CONTROL, ft_strlen(CONTROL)))
	{
		ft_putstr_fd(CONTROL_MESSAGE_BONUS, STDOUT_FILENO);
		exit(EXIT_SUCCESS);
	}
	else
	{
		ft_putstr_fd(INPUT_MESSAGE_BONUS, STDOUT_FILENO);
		exit(EXIT_FAILURE);
	}
	initial_set_data(data);
	return ;
}

int	handle_init_mlx_bonus(t_data *data)
{
	if (init_palette(data))
		return (MALLOC_ERROR);
	data->mlx = mlx_init();
	if (!data->mlx)
		return (MALLOC_ERROR);
	if (!new_window(data, data->name))
		return (MALLOC_ERROR);
	mlx_loop_hook(data->mlx, render_image_bonus, data);
	mlx_hook(data->win, DestroyNotify, NoEventMask, handle_close, data);
	mlx_hook(data->win, KeyPress, KeyPressMask, handle_key_input_bonus, data);
	mlx_hook(data->win, ButtonPress, ButtonPressMask, handle_scroll, data);
	mlx_hook(data->win, MotionNotify, PointerMotionMask, mouse_move, data);
	mlx_loop(data->mlx);
	return (0);
}

int	parse_input_bonus(t_data *data, char **av)
{
	size_t	i;

	i = 2;
	while (i < ft_matsize(av))
	{
		if (check_input_error(av[i]))
		{
			ft_putstr_fd(INPUT_MESSAGE_BONUS, STDOUT_FILENO);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	if (!ft_strncmp(av[1], NEWTON, ft_strlen(NEWTON)))
	{
		data->newton.c1 = ft_atoi_float(av[2]);
		data->newton.c2 = ft_atoi_float(av[3]);
		data->newton.c3 = ft_atoi_float(av[4]);
		data->newton.c4 = ft_atoi_float(av[5]);
	}
	return (0);
}
