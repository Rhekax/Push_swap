/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdursun <mdursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:43:05 by mdursun           #+#    #+#             */
/*   Updated: 2024/11/20 17:10:34 by mdursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *top)
{
	int	tmp;
	
	if (!top || !top->next)
		return ;
	tmp = top->num;
	top->num = top->next->num;
	top->next->num = tmp;
}
void	sb(t_stack *top)
{
	int	tmp;
	
	if (!top || !top->next)
		return ;
	tmp = top->num;
	top->num = top->next->num;
	top->next->num = tmp;
}
void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
}
void	pa(t_stack *a, t_stack *b)
{
	if (!b || b->num == 0)
	{
		
	}
}