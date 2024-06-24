/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 12:48:20 by aolabarr          #+#    #+#             */
/*   Updated: 2024/06/24 17:26:50 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double ft_pow(double num, int pow)
{
    int i;
    double res;

    if (pow == 0)
        return (1);
    res = 1;
    i = 0;
    while (i++ < pow)
        res = res * num;
    return (res);
}

int	max_int_mat(int **matrix, int x, int y)
{
	int max;
    int i;
    int j;

	max = INT_MIN;
    i = 0;
    while (i < y)
    {
        j = 0;
        while (j < x)
        {
            if (matrix[j][i] > max)
                max = matrix[j][i];
            j++;
        }
        i++;  
    }
    return (max);
}
int factorial(int n)
{
    int res;
    int i;

    i = 1;
    res = 1;
    while(i++ <= n)
        res = res * i;
    return (res);
}
double  binomial_coeff(double n, double k)
{
    double res;

    res = (double)factorial(n) / (double)(factorial(k) * factorial(n - k));
    return (res);
}
