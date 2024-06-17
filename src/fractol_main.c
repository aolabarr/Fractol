/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 21:38:34 by marvin            #+#    #+#             */
/*   Updated: 2024/06/13 21:38:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	int	stop;
	if (ac < 2)
		return (EXIT_SUCCESS);
	if (ac == 2 && !ft_strncmp(av[1], "mandelbrot", 10))
	{
		stop = mandelbrot();
		if (stop)
			return (EXIT_FAILURE);
	}	
	else if (ac == 2 && !ft_strncmp(av[1], "julia", 10))
		julia();
	else
		return (ft_putstr_fd(INPUT_MESSAGE, STDOUT_FILENO));

	return (0);
}

int mandelbrot(void)
{
	t_mlx_data	data;

	ft_putstr_fd("Mandelbrot fractal INICIO\n", STDOUT_FILENO);
	data.mlx = mlx_init();
	if (!data.mlx)
		return (MALLOC_ERROR);
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Mandelbrot Fractal");
	if (!data.win)
	{
		ft_putstr_fd("Mandelbrot fractal WIN ERROR\n", STDOUT_FILENO);
		mlx_destroy_display(data.mlx);
		free(data.mlx);
		return (MALLOC_ERROR);
	}
	data.img.ptr = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	//printf("IMG - %p\t%d\t%d\n",data.img.pix_ptr, data.img.line_len, data.img.bpp);
	data.img.pix_ptr = mlx_get_data_addr(data.img.ptr,
											&data.img.bpp,
											&data.img.line_len,
											&data.img.endian);
	data.img.com_map = NULL;
	data.img.iter_map = NULL;
	printf("IMG - %p\t%d\t%d\t%d\n",data.img.pix_ptr, data.img.line_len, data.img.bpp, data.img.endian);
	mlx_key_hook(data.win, handle_input_mandelbrot, &data);
	mlx_loop(data.mlx);
	mlx_destroy_window(data.mlx, data.win);
	mlx_destroy_display(data.mlx);
	free(data.mlx);
	ft_putstr_fd("Mandelbrot fractal FINISH\n", STDOUT_FILENO);
	return (0) ;
}

void julia(void)
{
	ft_putstr_fd("Julia fractal INICIO\n", STDOUT_FILENO);
	return ;
}

int	handle_input_mandelbrot(int key, t_mlx_data *data)
{
	if (key == XK_Escape)
	{
		ft_putstr_fd("ESC key has been pressed\n", STDOUT_FILENO);
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		exit(1);
	}
	if (key == XK_r)
	{
		printf("Prueba 100\n");
		data->img.com_map = get_complex_map();
		printf("Prueba 200\n");
		data->img.iter_map = get_iter_map(data->img.com_map);
		printf("Prueba 300\n");
		image_color(data->img, data->img.iter_map);
		printf("Prueba 400\n");
	}
	printf("Prueba 500\n");
	mlx_put_image_to_window(data->mlx, data->win, data->img.ptr, 0, 0);
	printf("Prueba 600\n");
	return (0);
}

void image_color(t_image img, int **iter_map)
{
	int		x;
	int		y;
	int		offset;
	int color;

	x = 1;
	color = YELLOW;
	while (x < WIDTH)
	{
		//printf("Prueba 600\tx: %d\n", x);
		y = 1;
		while (y < HEIGHT)
		{	
			//printf("Prueba 700\titer: %d\n", iter_map[x][y]);
			offset = (img.line_len * y) + x * (img.bpp / 8);
			if (iter_map[x][y])
				*(int *)(img.pix_ptr + offset) = color * iter_map[x][y];
			else
				*(int *)(img.pix_ptr + offset) = YELLOW;
			y++;
		}
		x++;
	}		
}

int	encode_rgb(byte red, byte green, byte blue)
{
	return (red << 16 | green << 8 | blue);
}

