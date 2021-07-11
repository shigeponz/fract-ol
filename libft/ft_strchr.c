/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshigemu <hshigemu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 18:37:19 by hshigemu          #+#    #+#             */
/*   Updated: 2021/07/12 00:01:43 by hshigemu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	ch;
	char			*s2;
	int				i;

	ch = (unsigned char)c;
	s2 = (char *)s;
	i = 0;
	while (s2[i])
	{
		if (s2[i] == ch)
			return (&s2[i]);
		i++;
	}
	if (s2[i] == ch)
		return (&s2[i]);
	return (NULL);
}
