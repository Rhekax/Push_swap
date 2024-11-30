/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdursun <mdursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:43:05 by mdursun           #+#    #+#             */
/*   Updated: 2024/11/30 14:07:23 by mdursun          ###   ########.fr       */
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

void	pb(t_stack **a, t_stack **b, t_stack *a_count, t_stack *b_count)
{
	t_stack	*tmp;

	if (a_count -> num == 0)
		return ;
	tmp = *a;
	tmp = tmp->next;
	ft_lstadd_front(b,*a);
	*a = tmp;
	b_count->num++;
	a_count->num--;
	ft_printf("pb\n");
}

void	ra(t_stack **a, int size)
{
    t_stack	*last;
    t_stack	*newLast;

	if (size < 2)
		return ;
    last = *a;
    newLast = *a;
    while (last -> next)
    {
      newLast = last;
      last = last -> next;
    }
    newLast -> next = NULL;
    last -> next = *a;
    *a = last;
	ft_printf("ra\n");
}

void	rb(t_stack **b, int size)
{
	t_stack	*last;
	t_stack	*newLast;

	if (size < 2)
		return ;
	last = *b;
	newLast = *b;
	while (last -> next)
	{
		newLast = last;
		last = last -> next;
	}
	newLast -> next = NULL;
	last -> next = *b;
	*b = last;
	ft_printf("rb\n");
}

void	rra(t_stack **a, int size)
{
	t_stack	*first;
	t_stack	*newFirst;

	if (size < 2)
		return ;
	first = *a;
    newFirst = (*a) -> next;
    while (first -> next)
      first = first -> next;
    first -> next = *a;
    (*a) -> next = NULL;
    *a = newFirst;
	ft_printf("rra\n");
}

void	rrb(t_stack **b, int size)
{
	t_stack	*first;
	t_stack	*newFirst;

	if (size < 2)
		return ;
	first = *b;
	newFirst = (*b) -> next;
	while (first -> next)
		first = first -> next;
	first -> next = *b;
	(*b) -> next = NULL;
	*b = newFirst;
	ft_printf("rrb\n");
}

void	rr(t_stack **a, t_stack **b, int asize, int bsize)
{
	t_stack	*last;
	t_stack	*newLast;

	if (asize < 2 && bsize < 2)
		return ;
	last = *a;
	newLast = *a;
	while (last -> next -> next)
		last = last -> next;
	newLast = last;
    last = last -> next;
	newLast -> next = NULL;
	last -> next = *a;
	*a = last;
	last = *b;
	newLast = *b;
    bsize--;
	while (--bsize)
		last = last -> next;
	newLast = last;
    last = last -> next;
	newLast -> next = NULL;
	last -> next = *b;
	*b = last;
	ft_printf("rr\n");
}

void	rrr(t_stack **a, t_stack **b, int asize, int bsize)
{
	t_stack	*first;
	t_stack	*newFirst;
    int		i;

	if (asize < 2 && bsize < 2)
		return ;
    i = 0;
	first = *a;
    newFirst = (*a) -> next;
    while (first -> next)
      first = first -> next;
    first -> next = *a;
    (*a) -> next = NULL;
    *a = newFirst;
    first = *b;
	newFirst = (*b) -> next;
	while (++i < bsize)
		first = first -> next;
	first -> next = *b;
	(*b) -> next = NULL;
	*b = newFirst;
	ft_printf("rrr\n");
}
