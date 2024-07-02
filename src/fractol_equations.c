/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_equations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 13:41:28 by aolabarr          #+#    #+#             */
/*   Updated: 2024/07/02 17:08:57 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int mandel_iterator(t_complex C, int maxiter)
{
    int         iter;
    float      mod_pw2;
    t_complex   Z;
    t_complex   aux;

    iter = 0;
    mod_pw2 = 0;
    Z.real = 0;
    Z.i = 0;
    while (iter < maxiter && mod_pw2 < ESC_RAD)
    {
        aux.real = Z.real * Z.real - Z.i * Z.i + C.real;
        aux.i = 2 * Z.real * Z.i + C.i;
        Z = aux;
        mod_pw2 = Z.real * Z.real + Z.i * Z.i;
        iter++;
    }
    return (iter);
}

int julia_iterator(t_complex C, t_complex Z, int maxiter)
{
    int         iter;
    float      mod_pw2;
    t_complex   aux;

    iter = 0;
    mod_pw2 = ft_pow(Z.real, 2) + ft_pow(Z.i, 2);
    while (iter < maxiter && mod_pw2 < ESC_RAD)
    {
        aux.real = ft_pow(Z.real, 2) - ft_pow(Z.i, 2) + C.real;
        aux.i = 2 * Z.real * Z.i + C.i;
        Z = aux;
        mod_pw2 = ft_pow(Z.real, 2) + ft_pow(Z.i, 2);
        iter++;
    }
    return (iter);
}
