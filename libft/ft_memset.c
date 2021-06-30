/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshigemu <hshigemu@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 23:34:21 by hshigemu          #+#    #+#             */
/*   Updated: 2021/04/12 22:44:41 by hshigemu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	ch;
	unsigned char	*buf_p;

	ch = c;
	buf_p = (unsigned char *)b;
	while (len > 0)
	{
		*buf_p++ = ch;
		len--;
	}
	return (b);
}
