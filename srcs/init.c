/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshigemu <hshigemu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 19:10:36 by hshigemu          #+#    #+#             */
/*   Updated: 2021/07/16 23:33:49 by hshigemu         ###   ########.fr       */
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
	if (ft_strncmp(argv[1], "M", 2) == 0)
		return (MANDELBROT_ID);
	if (ft_strncmp(argv[1], "J", 2) == 0)
		return (JULIA_ID);
	if (ft_strncmp(argv[1], "M2", 3) == 0)
		return (MANDELBROT_BONUS_ID);
	ft_print_help();
	return (0);
}

t_env	ft_env_init(int argc, char *argv[])
{
	t_env	ret;

	ret.frac_id = ft_validate_argv(argv);
	if (ret.frac_id == 0)
		ret.var = ft_var_init("mandelbrot");
	if (ret.frac_id == 1)
		ret.var = ft_var_init("julia");
	if (ret.frac_id == 2)
		ret.var = ft_var_init("mandelbrot option");
	ret.img = ft_img_init(ret.var);
	ret.zoom = 1.0;
	ret.org_x = 0.0;
	ret.org_y = 0.0;
	if (argc < 4)
	{
		ret.param1 = 0.0;
		ret.param2 = 0.0;
		return (ret);
	}
	ret.param1 = atof(argv[2]);
	ret.param2 = atof(argv[3]);
	return (ret);
}
