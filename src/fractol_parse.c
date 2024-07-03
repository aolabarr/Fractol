/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 09:55:11 by aolabarr          #+#    #+#             */
/*   Updated: 2024/07/03 09:58:57 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	parse_julia(t_data *data, char *real, char *imag)
{
	if (check_input_error(real) || check_input_error(imag))
	{
		perror(INPUT_MESSAGE);
		exit(EXIT_FAILURE);
	}
	data->julia.real = ft_atoi_float(real);
	data->julia.i = ft_atoi_float(imag);
	return ;
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
