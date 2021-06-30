/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshigemu <hshigemu@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 15:28:44 by hshigemu          #+#    #+#             */
/*   Updated: 2021/04/12 22:42:07 by hshigemu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst_p;
	unsigned char	*src_p;

	dst_p = (unsigned char *)dst;
	src_p = (unsigned char *)src;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (dst_p > src_p)
	{
		while (len > 0)
		{
			dst_p[len - 1] = src_p[len - 1];
			len--;
		}
	}
	else
	{
		while (len > 0)
		{
			*dst_p++ = *src_p++;
			len--;
		}
	}
	return (dst);
}
