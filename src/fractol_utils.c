/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 18:07:06 by marvin            #+#    #+#             */
/*   Updated: 2024/06/17 18:07:06 by marvin           ###   ########.fr       */
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

void    ft_int_mat_free(int **mat, int size)
{
    int i;

    i = 0;
    while (i < size)
        free(mat[i++]);
    free(mat);
    mat = NULL;
    return ;
}

void    ft_tcomplex_mat_free(t_complex **mat, int size)
{
    int i;

    i = 0;
    while (i < size)
        free(mat[i++]);
    free(mat);
    mat = NULL;
    return ;
}