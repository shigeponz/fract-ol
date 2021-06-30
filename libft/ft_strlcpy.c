/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshigemu <hshigemu@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 17:03:28 by hshigemu          #+#    #+#             */
/*   Updated: 2021/04/12 22:33:13 by hshigemu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	int		i;
	int		cnt;

	i = 0;
	cnt = 0;
	if (src == NULL)
		return (0);
	while (src[cnt])
		cnt++;
	if (dstsize == 0)
		return (cnt);
	while (dstsize > 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		dstsize--;
		i++;
	}
	dst[i] = '\0';
	return (cnt);
}
