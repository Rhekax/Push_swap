/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdursun <mdursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 13:39:43 by mdursun           #+#    #+#             */
/*   Updated: 2024/12/01 12:32:55 by mdursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	if (!*lst)
	{
		*lst = new;
		new -> next = NULL;
		return ;
	}
	while ((*lst) -> next)
	{
		*lst = (*lst) -> next;
	}
	(*lst) -> next = new;
	new -> next = NULL;
}
