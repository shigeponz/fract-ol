/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshigemu <hshigemu@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 00:44:42 by hshigemu          #+#    #+#             */
/*   Updated: 2021/04/12 22:53:36 by hshigemu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*lst_elem;

	if (f == NULL)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		lst_elem = ft_lstnew((*f)(lst->content));
		if (lst_elem == NULL)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, lst_elem);
		lst = lst->next;
	}
	return (new_lst);
}
