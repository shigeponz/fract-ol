/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshigemu <hshigemu@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 14:49:28 by hshigemu          #+#    #+#             */
/*   Updated: 2021/04/12 22:55:19 by hshigemu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dst_p;
	unsigned char	*src_p;
	unsigned char	ch;
	int				i;

	dst_p = (unsigned char *)dst;
	src_p = (unsigned char *)src;
	ch = (unsigned char)c;
	i = 0;
	while (n > 0 && src_p[i] != ch)
	{
		dst_p[i] = src_p[i];
		n--;
		i++;
	}
	if (n == 0)
		return (NULL);
	else
	{
		dst_p[i] = src_p[i];
		i++;
		return (&dst_p[i]);
	}
}
