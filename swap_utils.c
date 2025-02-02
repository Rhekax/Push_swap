/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdursun <mdursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:43:05 by mdursun           #+#    #+#             */
/*   Updated: 2024/12/01 12:56:02 by mdursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **a, int size)
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
	ft_printf("rra\n");
}

void	rb(t_stack **b, int size)
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
	ft_printf("rb\n");
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
