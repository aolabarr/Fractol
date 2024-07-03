/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 10:00:32 by aolabarr          #+#    #+#             */
/*   Updated: 2024/07/03 10:02:37 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

float	ft_pow(float num, int pow)
{
	int		i;
	float	res;

	if (pow == 0)
		return (1);
	res = 1;
	i = 0;
	while (i++ < pow)
		res = res * num;
	return (res);
}

int	factorial(int n)
{
	int	res;
	int	i;

	i = 1;
	res = 1;
	while (i++ <= n)
		res = res * i;
	return (res);
}

float	binomial_coeff(float n, float k)
{
	float	res;

	res = (float)factorial(n) / (float)(factorial(k) * factorial(n - k));
	return (res);
}
