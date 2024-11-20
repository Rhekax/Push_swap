/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdursun <mdursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 13:03:19 by mdursun           #+#    #+#             */
/*   Updated: 2024/11/20 11:31:49 by mdursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_stack	*ft_lstnew(int content)
{
	t_stack	*new;

	new = (t_stack *) malloc (sizeof(t_stack));
	if (!new)
		return (NULL);
	new -> num = content;
	new -> next = NULL;
	return (new);
}
