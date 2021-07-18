/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshigemu <hshigemu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 21:24:20 by hshigemu          #+#    #+#             */
/*   Updated: 2021/07/16 23:42:31 by hshigemu         ###   ########.fr       */
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
	printf("%s", HELP_MESSAGE1);
	printf("%s", HELP_MESSAGE2);
	printf("%s", HELP_MESSAGE3);
	printf("%s", HELP_MESSAGE4);
	printf("%s", HELP_MESSAGE5);
	exit(1);
}
