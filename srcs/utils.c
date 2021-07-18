/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshigemu <hshigemu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 23:06:56 by hshigemu          #+#    #+#             */
/*   Updated: 2021/07/17 21:52:21 by hshigemu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	ft_close(t_env *e)
{
	mlx_destroy_window(e->var.mlx, e->var.win);
	mlx_destroy_image(e->var.mlx, e->img.img);
//	mlx_destroy_display(e->var.mlx);
	free(e->var.mlx);
	exit(0);
}

int	ft_keypress(int key, t_env *e)
{
	if (key == K_ESC)
		ft_close(e);
	return (0);
}

int	ft_mouse_move(int key, int x, int y, t_env *e)
{
	printf("x = %d\n",x);
	printf("y = %d\n",y);
	if (key == SCROLL_UP)
		e->zoom *= 1.1;
	if (key == SCROLL_DOWN)
		e->zoom /= 1.1;
	return (0);
}

void	ft_put_image(t_env *e)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < WIN_HEIGHT)
	{
		while (x < WIN_WIDTH)
		{
			e->img.addr[y * (e->img.line_length / 4) + x] = e->buf[y][x];
			x++;
		}
		y++;
		x = 0;
	}
	mlx_put_image_to_window(e->var.mlx, e->var.win, e->img.img, 0, 0);
}
