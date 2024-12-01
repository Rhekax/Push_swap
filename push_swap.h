/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdursun <mdursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:17:39 by mdursun           #+#    #+#             */
/*   Updated: 2024/12/01 13:43:42 by mdursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"

void	rrr(t_stack **a, t_stack **b, int asize, int bsize);
void	rr(t_stack **a, t_stack **b, int asize, int bsize);
void	rrb(t_stack **b, int bsize);
void	rra(t_stack **a, int asize);
void	rb(t_stack **b, int bsize);
void	ra(t_stack **a, int size);
void	pb(t_stack **a, t_stack **b, t_stack *b_count, t_stack *a_count);
void	pa(t_stack **a, t_stack **b, t_stack *b_count, t_stack *a_count);
void	sb(t_stack *top);
void	sa(t_stack *top);
void	ss(t_stack *a, t_stack *b);
void	sortStack(t_stack **a, t_stack **b, t_stack **tracker);
int		checkStacks(t_stack **a, t_stack **b, t_stack **tracker);
#endif