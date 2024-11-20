/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdursun <mdursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 18:06:38 by mdursun           #+#    #+#             */
/*   Updated: 2024/11/20 11:46:00 by mdursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_stack	*ft_lstmap(t_stack *lst, void *(*f)(void*), void (*del)(void*))
{
	t_stack	*result;
	t_stack	*node;
	int	*content;

	if (!f || !del || !lst)
		return (NULL);
	result = NULL;
	while (lst)
	{
		content = f(&lst->num);
		node = ft_lstnew(*content);
		if (!node)
		{
			ft_lstclear(&result, del);
			del(content);
			return (NULL);
		}
		ft_lstadd_back(&result, node);
		lst = lst->next;
	}
	return (result);
}
