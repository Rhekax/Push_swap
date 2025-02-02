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
# include <stdlib.h>

void	rrr(t_stack **a, t_stack **b, int asize, int bsize);
void	rr(t_stack **a, t_stack **b, int asize, int bsize);
void	rrb(t_stack **b, int bsize);
void	rra(t_stack **a, int asize);
void	rb(t_stack **b, int bsize);
void	ra(t_stack **a, int size);
void	pb(t_stack **a, t_stack **b, t_stack *a_count, t_stack *b_count);
void	pa(t_stack **a, t_stack **b, t_stack *a_count, t_stack *b_count);
void	sb(t_stack *top);
void	sa(t_stack *top);
void	ss(t_stack *a, t_stack *b);
int		find_min(t_stack *stack);
void	list_error(t_stack *a, t_stack *b, t_stack *tracker);
void	push_smallest_to_b(t_stack **stack_a, t_stack **stack_b, t_stack *tracker);
void	sortStack(t_stack **a, t_stack **b, t_stack **tracker);
int		find_index(t_stack *stack, int value);
void	get_index(t_stack **a, int size);
int		check_if_sorted(t_stack *stack_a);
void	sort_big_list(t_stack **stack_a, t_stack **stack_b, t_stack *tracker);
void	sort_two_nodes(t_stack **stack_a);
void	sort_three_nodes(t_stack **stack_a,int size);
void	sort_four_five_nodes(t_stack **stack_a, t_stack **stack_b,t_stack *tracker);
#endif