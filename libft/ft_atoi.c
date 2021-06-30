/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshigemu <hshigemu@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 00:33:38 by hshigemu          #+#    #+#             */
/*   Updated: 2021/04/12 22:41:35 by hshigemu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int						i;
	int						flg;
	unsigned long long		num;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	flg = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			flg = -1;
		i++;
	}
	while (str[i] == '0')
		i++;
	num = 0;
	while (str[i] >= '0' && str[i] <= '9')
		num = num * 10 + (str[i++] - '0');
	return (num * flg);
}
