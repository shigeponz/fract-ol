/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshigemu <hshigemu@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 21:56:23 by hshigemu          #+#    #+#             */
/*   Updated: 2021/04/16 22:47:13 by hshigemu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	cnt_str(char const *s, char c)
{
	int		cnt;
	int		i;
	int		flg;

	cnt = 0;
	i = 0;
	flg = 0;
	if (s[i] == '\0')
		return (0);
	while (s[i])
	{
		if (s[i] != c && flg == 0)
		{
			cnt++;
			flg = 1;
		}
		if (s[i] == c && flg == 1)
			flg = 0;
		i++;
	}
	return (cnt);
}

static int	len_element(char const *s, char c)
{
	int		cnt;

	cnt = 0;
	while (s[cnt] != c && s[cnt] != '\0')
		cnt++;
	return (cnt);
}

static char	**free_null(char **strs)
{
	int		i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		strs[i] = NULL;
		i++;
	}
	free(strs);
	strs = NULL;
	return (strs);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		i;
	int		j;

	if (s == NULL)
		return (NULL);
	strs = malloc(sizeof(char *) * (cnt_str(s, c) + 1));
	if (strs == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (i < cnt_str(s, c))
	{
		if (s[j] == c)
			j++;
		else
		{
			strs[i] = ft_substr(&s[j], 0, len_element(&s[j], c));
			if (strs[i++] == NULL)
				return (free_null(strs));
			j = j + len_element(&s[j], c);
		}
	}
	strs[i] = NULL;
	return (strs);
}
