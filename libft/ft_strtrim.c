/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshigemu <hshigemu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 11:51:33 by hshigemu          #+#    #+#             */
/*   Updated: 2021/04/12 22:42:39 by hshigemu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	pre_not_match(char const *s1, char const *set)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (set[i])
	{
		if (s1[j] == set[i])
		{
			j++;
			i = 0;
		}
		else
			i++;
		if (s1[j] == '\0')
			return (j);
	}
	return (j);
}

static unsigned int	back_not_match(char const *s1, char const *set)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (ft_strlen(s1) == 0)
		return (0);
	j = ft_strlen(s1) - 1;
	while (set[i])
	{
		if (s1[j] == set[i])
		{
			j--;
			i = 0;
		}
		else
			i++;
		if (j == 0)
			return (j);
	}
	return (j);
}

static char	*return_emp_str(void)
{
	char	*str;

	str = malloc(sizeof(char) * 1);
	if (str == NULL)
		return (NULL);
	str[0] = '\0';
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;
	char			*str;

	if (s1 == NULL || set == NULL)
		return (NULL);
	i = pre_not_match(s1, set);
	j = back_not_match(s1, set);
	k = 0;
	if (i > j)
		str = return_emp_str();
	else
	{
		str = malloc(sizeof(char) * (j - i + 2));
		if (str == NULL)
			return (NULL);
		while (i < j + 1)
			str[k++] = s1[i++];
	}
	str[k] = '\0';
	return (str);
}
