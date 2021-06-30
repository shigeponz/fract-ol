/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshigemu <hshigemu@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 16:07:25 by hshigemu          #+#    #+#             */
/*   Updated: 2021/04/12 22:45:33 by hshigemu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	ch;
	unsigned char	*s_p;

	ch = (unsigned char)c;
	s_p = (unsigned char *)s;
	while (n > 0)
	{
		if (*s_p == ch)
			return (s_p);
		n--;
		s_p++;
	}
	return (NULL);
}
