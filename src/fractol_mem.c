/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_mem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 12:15:11 by aolabarr          #+#    #+#             */
/*   Updated: 2024/06/21 12:17:59 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
