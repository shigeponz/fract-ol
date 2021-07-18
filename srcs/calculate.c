/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshigemu <hshigemu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 23:56:24 by hshigemu          #+#    #+#             */
/*   Updated: 2021/07/17 22:13:21 by hshigemu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_calculate_mandelbrot(t_env *e)
{
	e = NULL;
	return ;
}

void	ft_calculate_julia(t_env *e)
{
	e = NULL;
	return ;
}

void	ft_calculate_bonus(t_env *e)
{
	e = NULL;
	return ;
}

void	ft_calculate(t_env *e)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < WIN_HEIGHT)
	{
		while (x < WIN_WIDTH)
		{
			if (e->frac_id == MANDELBROT_ID)
				e->buf[y][x] = ft_caluculate_mandelbrot(e, x, y);
			if (e->frac_id == JULIA_ID)
				e->buf[y][x] = ft_calculate_julia(e, x, y);
			if (e->frac_id == MANDELBROT_BONUS_ID)
				e->buf[y][x] = ft_calculate_bonus(e, x, y);
		}
	}
}