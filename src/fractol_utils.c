/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 12:48:20 by aolabarr          #+#    #+#             */
/*   Updated: 2024/06/21 12:48:29 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double pow2(double num)
{
    return (num * num);
}

int	max_int_mat(int **matrix, int y, int x)
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
