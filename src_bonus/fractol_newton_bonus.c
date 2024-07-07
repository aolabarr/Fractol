/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_newton_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 10:53:54 by aolabarr          #+#    #+#             */
/*   Updated: 2024/07/07 18:18:49 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol_bonus.h"

t_new_data	get_newton_iters(t_data *data, t_coef coefs, t_complex z0)
{
	t_new_data	new_data;
	t_complex	z;
	t_complex	root;
	int			i;
	float		tol;

	if (data->root_ok == 0)
		get_newton_roots(data, coefs);
	new_data = newton_iterator(data, coefs, z0);
	i = 0;
	tol = TOL * 100;
	while (i < 3)
	{
		z = new_data.root;
		root = data->roots[i];
		if (fabs(z.real - root.real) < tol && fabs(z.i - root.i) < tol)
		{
			new_data.no_root = i;
			break ;
		}
		i++;
	}
	return (new_data);
}

void	get_newton_roots(t_data *data, t_coef coef)
{
	float	mod;
	float	theta;
	int		i;

	if (coef.c1 < 0)
	{
		coef.c1 = -coef.c1;
		coef.c2 = -coef.c2;
	}
	mod = fabs(cbrt(coef.c2 / coef.c1));
	if (coef.c2 < 0)
		theta = 0;
	else
		theta = PI;
	i = 0;
	while (i < 3)
	{
		data->roots[i].real = mod * cos((theta + 2 * PI * i) / 3);
		data->roots[i].i = mod * sin((theta + 2 * PI * i) / 3);
		i++;
	}
	data->root_ok = 1;
	return ;
}

t_new_data	newton_iterator(t_data *data, t_coef cfs, t_complex z0)
{
	t_new_data	new_data;
	float		mod[2];
	t_complex	aux;
	t_complex	fx_prima;
	t_complex	z1;

	new_data.iter = 0;
	mod[0] = 0;
	mod[1] = sqrt(z0.real * z0.real + z0.i * z0.i);
	while (new_data.iter < data->img.maxiter && fabs(mod[1] - mod[0]) > TOL)
	{
		aux = ft_cpx_multi_escalar(ft_cpx_pow(z0, 3), cfs.c1);
		aux = ft_cpx_sum_escalar(aux, cfs.c2);
		fx_prima = ft_cpx_multi_escalar(ft_cpx_pow(z0, 2), 3 * cfs.c1);
		aux = ft_cpx_divide(aux, fx_prima);
		z1.real = z0.real - aux.real;
		z1.i = z0.i - aux.i;
		mod[0] = mod[1];
		mod[1] = sqrt(z1.real * z1.real + z1.i * z1.i);
		z0 = z1;
		new_data.iter++;
	}
	new_data.root = z1;
	return (new_data);
}

int	handle_key_input_bonus(int key, t_data *data)
{
	if (key == XK_t)
	{
		if (data->newton_tricolor == 0)
			data->newton_tricolor = 1;
		else
			data->newton_tricolor = 0;
	}
	else
		handle_key_input(key, data);
	if (key != XK_Escape)
		data->update = 1;
	return (0);
}
