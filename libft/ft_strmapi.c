/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshigemu <hshigemu@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 21:35:04 by hshigemu          #+#    #+#             */
/*   Updated: 2020/11/22 21:09:43 by hshigemu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ans;
	int		i;

	if (s == NULL || f == NULL)
		return (NULL);
	ans = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (ans == NULL)
		return (ans);
	i = 0;
	while (s[i])
	{
		ans[i] = (*f)(i, s[i]);
		i++;
	}
	ans[i] = '\0';
	return (ans);
}
