/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshigemu <hshigemu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 07:05:26 by hshigemu          #+#    #+#             */
/*   Updated: 2021/07/18 18:36:55 by hshigemu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	main(int argc, char *argv[])
{
	t_env	env;

	env = ft_env_init(argc, argv);
	ft_put_image(&env);
	mlx_hook(env.var.win, 4, 1L << 2, ft_mouse_move, &env);
	mlx_hook(env.var.win, X_EVENT_KEY_PRESS, 1L << 0, ft_keypress, &env);
	mlx_hook(env.var.win, X_EVENT_KEY_EXIT, 0, ft_close, &env);
	mlx_loop(env.var.mlx);
}
