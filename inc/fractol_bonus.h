/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 10:54:59 by aolabarr          #+#    #+#             */
/*   Updated: 2024/07/09 10:16:11 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

// Libraries
# include "fractol.h"

# define INPUT_MESSAGE_BONUS "\
\n******** FRACTOL BONUS ********\n\n\
Introduce correct arguments:\n\n\
	-> The complex polynomial is: a * z³ + b\n\n\
	-> ./fractol_bonus newton   < a > < b > \n\n\
        p.e.: ./fractol_bonus newton 1  -1\n\
              ./fractol_bonus newton 1.5 8\n\n\
To see the control set buttons:\n\n\
	-> ./fractol_bonus control\n\n\
****** AND ENJOY ! ******\n\n"

# define CONTROL_MESSAGE_BONUS "\
\n****************     FRACTOL BONUS     ****************\n\n\
This are the control options:\n\n\
	-> Traslate image:		Arrows (Up / Down / Left / Rigth)\n\
	-> Central zoom in / out:	+ / -\n\
	-> Mouse direction zoom:	Move the mouse scroll button\n\
	-> More image accuracy:		p	(less render speed)\n\
	-> Less image accuracy:		m	(more render speed)\n\
	-> Reset zoom & accuracy:	delete\n\
	-> Linear color mode:		l\n\
	-> Bezier color mode:		b\n\
	-> Tricolor mode:		t	(activate / deactivate)\n\n\
	NOTE 1: Changing the accuracy the color changes.\n\n\
	NOTE 2: Without the tricolor mode only is appreciate the convergence behaviour\n\
                and activating the tricolor mode is possible to see the convergence to\n\
                each complex root.\n\n\
**************     AND ENJOY !     **************\n\n"

typedef struct s_new_data
{
	int			iter;
	t_complex	root;
	int			no_root;
}				t_new_data;

//MAIN
void			init_fractal_bonus(t_data *data, int ac, char **av);
void			handle_perror_bonus(void);
int				handle_init_mlx_bonus(t_data *data);
int				parse_input_bonus(t_data *data, char **av);

// RENDER
int				render_image_bonus(t_data *data);
int				create_image_bonus(t_data *data);
void			put_color_pixel_bonus(t_data *data, t_image img, int x, int y);
t_complex		get_complex_bonus(float *dom, int x, int y);
unsigned int	encode_rgb(unsigned char r, unsigned char g, unsigned char b);

// NEWTON
t_new_data		get_newton_iters(t_data *data, t_coef coefs, t_complex z0);
void			get_newton_roots(t_data *data, t_coef coefs);
t_new_data		newton_iterator(t_data *data, t_coef cfs, t_complex z0);
int				handle_key_input_bonus(int key, t_data *data);

// COMPLEX
t_complex		ft_cpx_divide(t_complex a, t_complex b);
t_complex		ft_cpx_pow(t_complex a, int pow);
t_complex		ft_cpx_multi_escalar(t_complex c, float a);
t_complex		ft_cpx_sum_escalar(t_complex c, float a);

#endif