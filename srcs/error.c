/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshigemu <hshigemu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 21:24:20 by hshigemu          #+#    #+#             */
/*   Updated: 2021/07/27 23:14:27 by hshigemu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_print_error(char *message)
{
	ft_putstr_fd(message, 2);
	exit(1);
}

void	ft_print_help(void)
{
	printf("%s", HELP_MESSAGE1);
	printf("%s", HELP_MESSAGE2);
	printf("%s", HELP_MESSAGE3);
	printf("%s", HELP_MESSAGE4);
	printf("%s", HELP_MESSAGE6);
	exit(1);
}

int	ft_validate_float(char *obj)
{
	int		flg;
	int		i;

	flg = 0;
	i = 0;
	if (obj[i] == '-')
		i++;
	if (obj[i] == '\0')
		return (1);
	while (obj[i])
	{
		if (obj[i] == '.' && flg == 0)
		{
			flg = 1;
			i++;
			continue ;
		}
		if (ft_isdigit(obj[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}
