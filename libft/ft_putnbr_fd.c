/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshigemu <hshigemu@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 22:43:00 by hshigemu          #+#    #+#             */
/*   Updated: 2021/04/12 22:36:26 by hshigemu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digit(int i)
{
	int		cnt;

	cnt = 1;
	if (i < 0)
	{
		i *= -1;
	}
	while (i >= 10)
	{
		i /= 10;
		cnt++;
	}
	return (cnt);
}

static int	pow_10(int i)
{
	int		j;

	j = 1;
	while (i > 0)
	{
		j = j * 10;
		i--;
	}
	return (j);
}

void	write_int_fd(int i, int fd)
{
	i = '0' + i;
	write(fd, &i, 1);
}

void	write_min_fd(int i, int fd)
{
	char	c;
	int		digit;
	int		quo;

	c = '-';
	if (i == -2147483648)
	{
		write(fd, &c, 1);
		i = (i + 1) * (-1);
		digit = count_digit(i);
		while (digit >= 2)
		{
			quo = i / (pow_10(digit - 1));
			write_int_fd(quo, fd);
			i -= quo * (pow_10(digit - 1));
			digit--;
		}
		write_int_fd(i + 1, fd);
	}
	return ;
}

void	ft_putnbr_fd(int n, int fd)
{
	int		digit;
	int		quo;
	char	c;

	c = '-';
	digit = count_digit(n);
	if (n != -2147483648)
	{
		if (n < 0)
		{
			write(fd, &c, 1);
			n *= -1;
		}
		while (digit >= 1)
		{
			quo = n / (pow_10(digit - 1));
			write_int_fd(quo, fd);
			n -= quo * (pow_10(digit - 1));
			digit--;
		}
	}
	write_min_fd(n, fd);
}
