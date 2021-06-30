/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshigemu <hshigemu@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 00:31:08 by hshigemu          #+#    #+#             */
/*   Updated: 2020/11/15 19:55:12 by hshigemu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ca;

	ca = malloc(count * size);
	if (ca == NULL)
		return (NULL);
	ft_bzero(ca, count * size);
	return (ca);
}
