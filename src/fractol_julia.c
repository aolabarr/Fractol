/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_julia.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 13:41:28 by aolabarr          #+#    #+#             */
/*   Updated: 2024/06/30 18:20:57 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int julia_iterations(t_complex C, t_mouse Z)
{
    int         iter;
    float      mod_pw2;
    t_mouse   aux;

    iter = 0;
    mod_pw2 = ft_pow(Z.x, 2) + ft_pow(Z.y, 2);
    while (iter < MAXITER && mod_pw2 < ESC_RAD)
    {
        aux.x = ft_pow(Z.x, 2) - ft_pow(Z.y, 2) + C.real;
        aux.y = 2 * Z.x * Z.y + C.i;
        Z = aux;
        mod_pw2 = ft_pow(Z.x, 2) + ft_pow(Z.y, 2);
        iter++;
    }
    return (iter);
}
