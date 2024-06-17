/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_mandelbrot.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:45:12 by marvin            #+#    #+#             */
/*   Updated: 2024/06/17 16:45:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int     **get_iter_map(t_complex **c_map)
{
    int **map;
    int i;
    int j;

    map = malloc(sizeof(int *) * HEIGHT);
    i = 0;
    while (i < HEIGHT)
        map[i++] = malloc(sizeof(int) * WIDTH);
    j = 0;
    while (i < HEIGHT)
    {
        j = 0;
        while (j < WIDTH)
        {
            map[i][j] = calculate_iterations(c_map[i][j]);
            j++;
        }
        i++;
    }

    return (map);
}

t_complex   **get_complex_map(void)
{
    //Pero con Zoom hay que cambiar ancho y alto
    t_complex   **map;
    int         i;
    int         j;

    map = malloc(sizeof(t_complex *) * HEIGHT);
    i = 0;
    while (i < HEIGHT)
        map[i++] = malloc(sizeof(t_complex) * WIDTH);
    map[0][0].real = DOM_MIN;
    map[0][0].i = DOM_MAX;
    i = 0;
    while (i < HEIGHT)
    {
        j = 0;
        while (j < WIDTH)
        {
            map[i][j].real = DOM_MIN + (DOM_MAX - DOM_MIN) / WIDTH * j;
            map[i][j].i = DOM_MAX - (DOM_MAX - DOM_MIN) / HEIGHT * i;
            j++;
        }
        i++;
    }
    return (map);
}

int calculate_iterations(t_complex c)
{
    int         iter;
    int         mod_pw2;
    t_complex   Z;
    t_complex   aux;

    iter = 0;
    mod_pw2 = 0;
    Z.real = 0;
    Z.i = 0;
    while (iter < MAXITER && mod_pw2 < 4)
    {
        aux.real = pow2(Z.real) - pow2(c.i) + c.real;
        aux.i = 2 * Z.real * Z.i + c.i;
        Z = aux;
        mod_pw2 = pow2(Z.real) + pow2(Z.i);
        iter++;
    }
    if (iter == MAXITER)
        return (0);
    return (iter);
}

