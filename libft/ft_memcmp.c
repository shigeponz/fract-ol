/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshigemu <hshigemu@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 16:33:56 by hshigemu          #+#    #+#             */
/*   Updated: 2021/04/12 22:34:43 by hshigemu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_p;
	unsigned char	*s2_p;

	s1_p = (unsigned char *)s1;
	s2_p = (unsigned char *)s2;
	while (n > 0)
	{
		if (*s1_p != *s2_p)
			return (*s1_p - *s2_p);
		s1_p++;
		s2_p++;
		n--;
	}
	return (0);
}
