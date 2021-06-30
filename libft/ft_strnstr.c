/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshigemu <hshigemu@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 23:32:16 by hshigemu          #+#    #+#             */
/*   Updated: 2021/04/12 22:29:36 by hshigemu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int		i;
	unsigned int		j;
	char				*s;

	i = 0;
	s = (char *)haystack;
	if (needle[0] == '\0')
		return (s);
	if (len == 0)
		return (0);
	while (i < len)
	{
		j = 0;
		while (s[i] == needle[j] && i < len)
		{
			if (needle[j + 1] == '\0')
				return (&s[i - j]);
			i++;
			j++;
		}
		i = i - j;
		i++;
	}
	return (NULL);
}
