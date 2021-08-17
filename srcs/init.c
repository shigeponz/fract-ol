/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshigemu <hshigemu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 19:10:36 by hshigemu          #+#    #+#             */
/*   Updated: 2021/08/17 23:19:24 by hshigemu         ###   ########.fr       */
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

int	ft_validate_argv(int argc, char *argv[])
{
	if (argc < 2)
		ft_print_help();
	if (ft_strncmp(argv[1], "M", 2) == 0)
		return (MANDELBROT_ID);
	if (ft_strncmp(argv[1], "J", 2) == 0)
	{
		if (argc < 4)
			ft_print_help();
		if (ft_validate_float(argv[2]) == 1 || ft_validate_float(argv[3]) == 1)
			ft_print_help();
		return (JULIA_ID);
	}
	ft_print_help();
	return (0);
}

t_env	ft_env_init(int argc, char *argv[])
{
	t_env	ret;

	ret.frac_id = ft_validate_argv(argc, argv);
	if (ret.frac_id == 0)
		ret.var = ft_var_init("mandelbrot");
	if (ret.frac_id == 1)
		ret.var = ft_var_init("julia");
	ret.img = ft_img_init(ret.var);
	ret.zoom = 1.0;
	ret.org_x = 0.0;
	ret.org_y = 0.0;
	ret.pos_x = 400;
	ret.pos_y = 400;
	ret.color = 1;
	if (argc == 2)
		return (ret);
	if (argc == 3)
	{
		ret.param1 = atoi(argv[2]);
		return (ret);
	}
	ret.param1 = atof(argv[2]);
	ret.param2 = atof(argv[3]);
	return (ret);
}
