/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshigemu <hshigemu@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 22:35:32 by hshigemu          #+#    #+#             */
/*   Updated: 2020/11/13 00:09:41 by hshigemu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int		i;
	char	c;

	i = 0;
	c = '\n';
	if (s == NULL)
		return ;
	while (s[i])
		write(fd, &s[i++], 1);
	write(fd, &c, 1);
}
