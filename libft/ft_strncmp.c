/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshigemu <hshigemu@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 00:14:49 by hshigemu          #+#    #+#             */
/*   Updated: 2021/04/12 22:42:54 by hshigemu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*sh1;
	unsigned char	*sh2;

	sh1 = (unsigned char *)s1;
	sh2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	i = 0;
	while (i < n - 1 && sh1[i] != '\0' && sh2[i] != '\0' && sh1[i] == sh2[i])
	{
		i++;
	}
	return (sh1[i] - sh2[i]);
}
