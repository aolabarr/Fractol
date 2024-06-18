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
    int x;
    int y;

    
    map = malloc(sizeof(int *) * HEIGHT);
    y = 0;
    while (y < HEIGHT)
        map[y++] = malloc(sizeof(int) * WIDTH);
    y = 0;
    printf("Prueba 1000\n");
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            //printf("(x,y)=(%d,%d)\n", x , y);
            map[y][x] = mandel_iterations(c_map[y][x]);
			if (map[y][x] == MAXITER)
				printf("IN TO MANDELBROT\n");
            //else
             //   printf("(x,y)=(%d,%d)\t iter= %d\n", x, y, map[y][x]);
            //if (x % 100 == 0)
              //  getchar();
            x++;
        }
        y++;
    }

    return (map);
}

t_complex   **get_complex_map(void)
{
    //Pero con Zoom hay que cambiar ancho y alto
    t_complex   **map;
    int         x;
    int         y;

    map = malloc(sizeof(t_complex *) * HEIGHT);
    y = 0;
    while (y < HEIGHT)
        map[y++] = malloc(sizeof(t_complex) * WIDTH);
    map[0][0].real = DOM_MIN;
    map[0][0].i = DOM_MAX;
    y = 0;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            map[y][x].real = DOM_MIN + (DOM_MAX - DOM_MIN) / WIDTH * x;
            map[y][x].i = DOM_MAX - (DOM_MAX - DOM_MIN) / HEIGHT * y;
            //printf("(x,y)=(%d,%d)\t complex=(%f,%f)\n", x, y, map[y][x].real, map[y][x].i);
            x++;
        }
        y++;
    }
    return (map);
}

int mandel_iterations(t_complex C)
{
    int         iter;
    double      mod_pw2;
    t_complex   Z;
    t_complex   aux;

    iter = 0;
    mod_pw2 = 0;
    Z.real = 0;
    Z.i = 0;
    while (iter < MAXITER && mod_pw2 < ESC_RAD)
    {
        aux.real = pow2(Z.real) - pow2(Z.i) + C.real;
        aux.i = 2 * Z.real * Z.i + C.i;
        Z = aux;
        mod_pw2 = pow2(Z.real) + pow2(Z.i);
        iter++;
    }
    if (mod_pw2 < ESC_RAD)
        printf("iter: %d\tmod: %f\treal: %f\timg: %f\n", iter, mod_pw2, Z.real, Z.i);
    return (iter);
}

