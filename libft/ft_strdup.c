/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshigemu <hshigemu@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 00:59:12 by hshigemu          #+#    #+#             */
/*   Updated: 2020/12/13 13:18:28 by hshigemu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		cnt;
	char	*dest;

	cnt = 0;
	while (s1[cnt])
		cnt++;
	dest = (char *)malloc(sizeof(char) * (cnt + 1));
	if (dest == NULL)
		return (NULL);
	cnt = 0;
	while (s1[cnt])
	{
		dest[cnt] = s1[cnt];
		cnt++;
	}
	dest[cnt] = '\0';
	return (dest);
}
