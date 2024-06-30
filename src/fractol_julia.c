/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_julia.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 13:41:28 by aolabarr          #+#    #+#             */
/*   Updated: 2024/06/30 15:59:28 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex   parse_julia(char *real, char *imag)
{
    t_complex   c;
    
    if (check_input_error(real) || check_input_error(imag))
    {
        perror(INPUT_MESSAGE);
        exit(EXIT_FAILURE);
    }
    c.real = ft_atoi_float(real);
    c.i = ft_atoi_float(imag);
    return (c);
        
}

int check_input_error(char *str)
{
    size_t i;

    i = 0;
    while (i < ft_strlen(str))
    {
        if (!(ft_isdigit(str[i]) || str[i] == '.' 
                || str[i] == '+' || str[i] == '-'))
            return (EXIT_FAILURE); 
        i++;
    }
    return (0);
}
