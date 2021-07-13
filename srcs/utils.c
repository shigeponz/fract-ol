/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshigemu <hshigemu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 23:06:56 by hshigemu          #+#    #+#             */
/*   Updated: 2021/07/12 21:29:35 by hshigemu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	ft_close(t_fractol *frac)
{
	mlx_destroy_window(frac->var.mlx, frac->var.win);
	mlx_destroy_image(frac->var.mlx, frac->img.img);
//	mlx_destroy_display(frac->var.mlx);
	free(frac->var.mlx);
	exit(0);
}

int	ft_keypress(int key, t_fractol *frac)
{
	if (key == K_ESC)
		ft_close(frac);
	return (0);
}

int	ft_mouse_move(int key, t_fractol *frac)
{
	if (key == SCROLL_UP)
		ft_close(frac);
	if (key == SCROLL_DOWN)
		ft_close(frac);
	return (0);
}
