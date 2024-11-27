/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdursun <mdursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:43:05 by mdursun           #+#    #+#             */
/*   Updated: 2024/11/27 18:20:22 by mdursun          ###   ########.fr       */
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
	ft_printf("sa\n");
}
void	sb(t_stack *top)
{
	int	tmp;
	
	if (!top || !top->next)
		return ;
	tmp = top->num;
	top->num = top->next->num;
	top->next->num = tmp;
	ft_printf("sb\n");
}
void	ss(t_stack *a, t_stack *b)
{
	int	tmp;
	
	if (!a || !a->next)
		return ;
	tmp = a->num;
	a->num = a->next->num;
	a->next->num = tmp;
	if (!b || !b->next)
		return ;
	tmp = b->num;
	b->num = b->next->num;
	b->next->num = tmp;
	ft_printf("ss\n");
}
void	pa(t_stack **a, t_stack **b, t_stack *b_count, t_stack *a_count)
{
	t_stack	*tmp;
	
	if (!b_count->num)
		return ;
	tmp = *b;
	tmp = tmp -> next;
	ft_lstadd_front(a,*b);
	*b = tmp;
	b_count->num--;
	a_count->num++;
	ft_printf("pa\n");
}
void	pb(t_stack **a, t_stack **b, t_stack *b_count, t_stack *a_count)
{
	t_stack	*tmp;
	
	if (a_count->num == 0)
		return ;
	tmp = *a;
	tmp = tmp->next;
	ft_lstadd_front(b,*a);
	*a = tmp;
	b_count->num++;
	a_count->num--;
	ft_printf("pb\n");
}
void	ra(t_stack *a, int asize)
{
	if (asize < 2)
		return ;
	a[asize].next = a;
	a[0] = a[asize];
	a[asize].next = NULL;
	ft_printf("ra\n");
}
void	rb(t_stack *b, int bsize)
{
	if (bsize < 2)
		return ;
	b[bsize].next = b;
	b[0] = b[bsize];
	b[bsize].next = NULL;
	ft_printf("rb\n");
}
void	rra(t_stack *a, int asize)
{
	if (asize < 2)
		return ;
	a[asize].next = &a[0];
	a[0] = a[1];
	a[asize].next = NULL;
	ft_printf("rra\n");
}
void	rrb(t_stack *b, int bsize)
{
	if (bsize < 2)
		return ;
	b[bsize].next = &b[0];
	b[0] = b[1];
	b[bsize].next = NULL;
	ft_printf("rrb\n");
}

void	rr(t_stack *a, t_stack *b, int bsize, int asize)
{
	while (1)
	{
		if (asize < 2)
			break ;
		a[asize].next = a;
		a[0] = a[asize];
		a[asize].next = NULL;
		break ;
	}
	if (bsize < 2)
		return ;
	b[bsize].next = b;
	b[0] = b[bsize];
	b[bsize].next = NULL;
	ft_printf("rr\n");
}
void	rrr(t_stack *a, t_stack *b, int bsize, int asize)
{
	while (1)
	{
		if (asize < 2)
			break ;
		a[asize].next = &a[0];
		a[0] = a[1];
		a[asize].next = NULL;
		break ;
	}
	if (bsize < 2)
		return ;
	b[bsize].next = &b[0];
	b[0] = b[1];
	b[bsize].next = NULL;
	ft_printf("rrr\n");
}
