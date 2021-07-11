/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshigemu <hshigemu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 07:05:26 by hshigemu          #+#    #+#             */
/*   Updated: 2021/07/12 00:24:53 by hshigemu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	main(int argc, char *argv[])
{
	t_fractol	frac;

	if (argc < 2)
		ft_print_error(INVALID_COMMANDLINE_NUM_ERR);
	frac = ft_frac_init(argc, argv);
	mlx_put_image_to_window(frac.var.mlx, frac.var.win, frac.img.img, 0, 0);
//	mlx_hook(frac.var.win, 4, (1L << 2), mlx_mouse_hook, &frac);
	mlx_hook(frac.var.win, X_EVENT_KEY_PRESS, 1L << 0, &ft_keypress, &frac);
	mlx_hook(frac.var.win, X_EVENT_KEY_EXIT, 0, &ft_close, &frac);
	mlx_loop(frac.var.mlx);
}
