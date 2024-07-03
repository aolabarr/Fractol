/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 09:55:11 by aolabarr          #+#    #+#             */
/*   Updated: 2024/07/03 13:30:00 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	parse_input(t_data *data, char *real, char *imag, char *name)
{
	if (check_input_error(real) || check_input_error(imag))
	{
		ft_putstr_fd(INPUT_MESSAGE, STDOUT_FILENO);
		exit(EXIT_FAILURE);
	}
	if (!ft_strncmp(name, JULIA, ft_strlen(JULIA)))
	{
		data->julia.real = ft_atoi_float(real);
		data->julia.i = ft_atoi_float(imag);
	}
	if (!ft_strncmp(name, NEWTON, ft_strlen(NEWTON)))
	{
		data->newton.c1 = ft_atoi_float(real);
		data->newton.c2 = ft_atoi_float(imag);
	}
	
	return (0);
}

int	check_input_error(char *str)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(str))
	{
		if (!(ft_isdigit(str[i]) || str[i] == '.'
				|| str[i] == '+' || str[i] == '-'))
		{
			return (EXIT_FAILURE);
		}
		if (str[i] == '+' || str[i] == '-')
		{
			if (!ft_isdigit(str[i + 1]))
				return (EXIT_FAILURE);
		}
		i++;
	}
	return (0);
}
