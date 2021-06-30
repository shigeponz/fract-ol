/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshigemu <hshigemu@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 23:17:38 by hshigemu          #+#    #+#             */
/*   Updated: 2021/04/12 22:46:04 by hshigemu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	ch;
	char			*s2;
	int				i;

	ch = (unsigned char)c;
	s2 = (char *)s;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s2[i] == ch)
			return (&s2[i]);
		i--;
	}
	return (NULL);
}
