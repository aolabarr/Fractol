/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_mem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 12:15:11 by aolabarr          #+#    #+#             */
/*   Updated: 2024/06/23 13:10:40 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    ft_free_mat_int(int **mat, int size)
{
    int i;

	if (!mat)
		return ;
    i = 0;
    while (i < size)
        free(mat[i++]);
    free(mat);
    mat = NULL;
    return ;
}

void    ft_free_mat_tcomplex(t_complex **mat, int size)
{
    int i;

	if (!mat)
		return ;
    i = 0;
    while (i < size)
		free(mat[i++]);
    free(mat);
    mat = NULL;
    return ;
}

int	**ft_malloc_mat_int(int x, int y)
{
	int **map;
	int	i;

    map = malloc(sizeof(int *) * y);
	if (!map)
		return(NULL);
    i = 0;
    while (i < y)
	{
		map[i] = malloc(sizeof(int) * x);
		if (!map[i])
			return (ft_free_mat_int(map, i), NULL);
		i++;
	}
	return (map);
}

t_complex	**ft_malloc_mat_tcomplex(int x, int y)
{
	t_complex **map;
	int	i;

    map = malloc(sizeof(t_complex *) * y);
	if (!map)
		return(NULL);
    i = 0;
    while (i < y)
	{
		map[i] = malloc(sizeof(t_complex) * x);
		if (!map[i])
			return (ft_free_mat_tcomplex(map, i), NULL);
		i++;
	}
	return (map);
}

