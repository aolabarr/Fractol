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
	int			endian;

	endian = 0;
	ft_putstr_fd("Mandelbrot fractal INICIO\n", STDOUT_FILENO);
	data.mlx = mlx_init();
	printf("mlx dir: %p\n", data.mlx);
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
	data.img.image = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	printf("IMG - %p\t%d\t%d\n",data.img.data, data.img.size_line, data.img.bpp);
	data.img.data = mlx_get_data_addr(data.img.image,
									&data.img.bpp,
									&data.img.size_line,
									&endian);
	printf("IMG - %p\t%d\t%d\n",data.img.data, data.img.size_line, data.img.bpp);
	mlx_key_hook(data.win, handle_input, &data);
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

int	handle_input(int key, t_mlx_data *data)
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
		image_color(data->img, encode_rgb(255, 0, 0));
	else if (key == XK_g)
		image_color(data->img, encode_rgb(0, 255, 0));
	else if (key == XK_b)
		image_color(data->img, encode_rgb(0, 0, 255));
	mlx_put_image_to_window(data->mlx, data->win, (void *)data->img.image, 0, 0);
	return (0);
}

void image_color(t_img img, int color)
{
	//printf("Prueba 002\n");
	int		x;
	int		y;

	x = 1;
	while (x <= WIDTH)
	{
		y = 1;
		while (y <= HEIGHT)
		{
			//printf("x: %d, y: %d\n", x, y);
			//printf("%p\t%d\t%d\n",img.data, img.size_line, img.bpp);
			*(img.data + (img.size_line * y) + x * (img.bpp / 8)) = color;
			y++;
		}
		x++;
	}		
}

int	encode_rgb(byte red, byte green, byte blue)
{
	return (red << 16 | green << 8 | blue);
}
