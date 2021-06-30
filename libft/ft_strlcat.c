/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshigemu <hshigemu@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 17:40:04 by hshigemu          #+#    #+#             */
/*   Updated: 2021/04/12 22:41:54 by hshigemu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		dst_len;
	size_t		src_len;
	int			i;
	int			j;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = dst_len;
	j = 0;
	if (dst_len >= dstsize)
		return (src_len + dstsize);
	if (dst_len + src_len >= dstsize)
	{
		while (dstsize - i - 1 > 0)
			dst[i++] = src[j++];
	}
	else
	{
		while (src[j])
			dst[i++] = src[j++];
	}
	dst[i] = '\0';
	return (dst_len + src_len);
}
