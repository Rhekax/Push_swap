/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdursun <mdursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:43:05 by mdursun           #+#    #+#             */
/*   Updated: 2024/11/22 21:40:58 by mdursun          ###   ########.fr       */
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
void	pa(t_stack *a, t_stack *b, t_stack *b_count, t_stack *a_count)
{
	if (!b_count->num)
		return ;
	ft_lstadd_front(&a,b);
	b = b -> next;
	b_count->num--;
	a_count->num++;
}
void	pb(t_stack *a, t_stack *b, t_stack *b_count, t_stack *a_count)
{
	if (!a_count->num)
		return ;
	ft_lstadd_front(&a,b);
	b = b -> next;
	b_count->num++;
	a_count->num--;
}
void	ra(t_stack *a)
{
	a[ft_lstsize(a)].next = &a[0];
	a[ft_lstsize(a) - 1].next = NULL;
	a[0] = a[ft_lstsize(a)];
}