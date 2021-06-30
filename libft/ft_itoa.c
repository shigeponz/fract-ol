/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshigemu <hshigemu@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 19:00:57 by hshigemu          #+#    #+#             */
/*   Updated: 2021/04/12 22:37:54 by hshigemu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_digit(int n)
{
	int		cnt;

	if (n < 0)
		n = n * (-1);
	cnt = 1;
	while (n >= 10)
	{
		n = n / 10;
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

static char	*malloc_to_itoa(int n)
{
	char	*str;

	if (n < 0)
		str = malloc(sizeof(char) * (get_digit(n) + 2));
	else
		str = malloc(sizeof(char) * (get_digit(n) + 1));
	return (str);
}

static char	*ft_itoa_exception(int n)
{
	char	*str;
	int		i;
	int		j;

	n = (n + 8) * -1;
	str = malloc(sizeof(char) * (get_digit(n) + 2));
	if (str == NULL)
		return (NULL);
	i = 0;
	str[0] = '-';
	i++;
	j = get_digit(n);
	while (j > 1)
	{
		str[i++] = n / pow_10(j - 1) + '0';
		n = n % pow_10(j - 1);
		j--;
	}
	str[i] = '0' + 8;
	i++;
	str[i] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		j;

	if (n == -2147483648)
		return (ft_itoa_exception(n));
	str = malloc_to_itoa(n);
	if (str == NULL)
		return (str);
	i = 0;
	if (n < 0)
	{
		str[0] = '-';
		i++;
		n = -1 * n;
	}
	j = get_digit(n);
	while (j > 0)
	{
		str[i++] = n / pow_10(j - 1) + '0';
		n = n % pow_10(j - 1);
		j--;
	}
	str[i] = '\0';
	return (str);
}
