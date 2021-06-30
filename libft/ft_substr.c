/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshigemu <hshigemu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 19:15:46 by hshigemu          #+#    #+#             */
/*   Updated: 2021/04/12 22:44:06 by hshigemu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*return_nc(void)
{
	char	*str;

	str = malloc(1);
	if (str == NULL)
		return (NULL);
	str[0] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s) || len == 0)
	{
		str = return_nc();
		return (str);
	}
	if (ft_strlen(s) < start + len)
		str = malloc(sizeof(char) * (ft_strlen(s) - start + 1));
	else
		str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < len && ft_strlen(s) > start + i)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
