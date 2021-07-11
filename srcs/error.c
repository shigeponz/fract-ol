/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshigemu <hshigemu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 21:24:20 by hshigemu          #+#    #+#             */
/*   Updated: 2021/07/11 17:30:29 by hshigemu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_print_error(char *message)
{
	ft_putstr_fd(message, 2);
	exit(1);
}

void	ft_print_help()
{
	printf("%s", HELP_MESSAGE);
	printf("%s",COMMAND_EXAMPLE1);
	printf("%s",COMMAND_EXAMPLE2);
	exit(1);
}
