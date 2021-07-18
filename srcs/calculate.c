/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshigemu <hshigemu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 23:56:24 by hshigemu          #+#    #+#             */
/*   Updated: 2021/07/18 18:38:20 by hshigemu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	ft_mandelbrot_color(double x, double y, t_env *e)
{
	int		i;
	double	re;
	double	im;
	double	tmp_re;
	double	tmp_im;

	i = 0;
	tmp_re = x;
	tmp_im = y;
	while (i < PARTICLE_SIZE)
	{
		re = pow(tmp_re, 2) - pow(tmp_im, 2) + x;
		im = tmp_re * tmp_im * 2 + y;
		if (hypot(re, im) > 2)
			break ;
		tmp_re = re;
		tmp_im = im;
		i++;
	}
	return (e->color * i * 50);
}

int	ft_julia_color(double x, double y, t_env *e)
{
	int		i;
	double	re;
	double	im;
	double	tmp_re;
	double	tmp_im;

	i = 0;
	tmp_re = x;
	tmp_im = y;
	while (i < PARTICLE_SIZE)
	{
		re = pow(tmp_re, 2) - pow(tmp_im, 2) + e->param1;
		im = tmp_re * tmp_im * 2 + e->param2;
		if (hypot(re, im) > 2)
			break ;
		tmp_re = re;
		tmp_im = im;
		i++;
	}
	return (e->color * i * 5);
}

/*
int	ft_mandelbrot_bonus_color(double x, double y, t_env *e)
{
	int		i;
	double	re;
	double	im;
	double	tmp_re;
	double	tmp_im;

	i = 0;
	tmp_re = x;
	tmp_im = y;
	while (i < PARTICLE_SIZE)
	{
		re = pow(tmp_re, e->param1) - pow(tmp_im, e->param1) + x;
		im = tmp_re * tmp_im * 2 + y;
		if (hypot(re, im) > 2)
			return (0);
		tmp_re = re;
		tmp_im = im;
		i++;
	}
	return (100);
}
*/

int	ft_calculate(t_env *e, int x, int y)
{
	int		color;
	double	coordinate_x;
	double	coordinate_y;
	double	square_length;

	square_length = SQUARE_RANGE / e->zoom;
	coordinate_x = e->org_x + square_length *
		(x - e->pos_x) / WIN_WIDTH;
	coordinate_y = e->org_y + square_length *
		(y - e->pos_y) / WIN_HEIGHT;
	color = 0;
	if (e->frac_id == MANDELBROT_ID)
		color = ft_mandelbrot_color(coordinate_x, coordinate_y, e);
	if (e->frac_id == JULIA_ID)
		color = ft_julia_color(coordinate_x, coordinate_y, e);
	/*
	if (e->frac_id == MANDELBROT_BONUS_ID)
		color = ft_mandelbrot_bonus_color(coordinate_x, coordinate_y, e);
	*/
	return (color);
}
