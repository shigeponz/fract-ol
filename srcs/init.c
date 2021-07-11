/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshigemu <hshigemu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 19:10:36 by hshigemu          #+#    #+#             */
/*   Updated: 2021/07/11 23:33:10 by hshigemu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_vars	ft_var_init(char *fractol)
{
	t_vars	var;

	var.mlx = mlx_init();
	if (var.mlx == NULL)
		ft_print_error(MEMALLOC_ERR);
	var.win = mlx_new_window(var.mlx, WIN_WIDTH, WIN_HEIGHT, fractol);
	if (var.win == NULL)
		ft_print_error(MEMALLOC_ERR);
	return (var);
}

t_image	ft_img_init(t_vars var)
{
	t_image	img;

	img.img = mlx_new_image(var.mlx, WIN_WIDTH, WIN_HEIGHT);
	if (img.img == NULL)
		ft_print_error(MEMALLOC_ERR);
	img.addr = (int *)mlx_get_data_addr(img.img, &img.bits_per_pixel,
		&img.line_length, &img.endian);
	return (img);
}

int	ft_validate_argv(char *argv[])
{
	if (ft_strncmp(argv[1], "mandelbrot", 11) == 0)
		return (MANDELBROT_ID);
	if (ft_strncmp(argv[1], "julia", 6) == 0)
		return (JULIA_ID);
	ft_print_help();
	return (0);
}

t_fractol	ft_frac_init(int argc, char *argv[])
{
	t_fractol	ret;

	ret.frac_id = ft_validate_argv(argv);
	if (ret.frac_id == 0)
		ret.var = ft_var_init("mandelbrot");
	if (ret.frac_id == 1)
		ret.var = ft_var_init("julia");
	ret.img = ft_img_init(ret.var);
	ret.zoom = 1.0;
	if (argc < 4)
	{
		ret.julia_x = 0.0;
		ret.julia_y = 0.0;
		return (ret);
	}
	ret.julia_x = atof(argv[2]);
	ret.julia_y = atof(argv[3]);
	return (ret);
}
