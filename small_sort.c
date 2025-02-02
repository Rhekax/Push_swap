#include "push_swap.h"

int	find_index(t_stack *stack, int value)
{
	int	index = 0;

	while (stack)
	{
		if (stack->num == value)
			return (index);
		stack = stack->next;
		index++;
	}
	return (-1);
}

void	sort_two_nodes(t_stack **stack_a)
{
	if ((*stack_a)->num > (*stack_a)->next->num)
		sa(*stack_a);
}

void	sort_three_nodes(t_stack **stack_a,int size)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->num;
	b = (*stack_a)->next->num;
	c = (*stack_a)->next->next->num;
	if (a > b && b < c && a < c)
		sa(*stack_a);
	else if (a > b && b > c)
	{
		sa(*stack_a);
		rra(stack_a,size);
	}
	else if (a > b && b < c)
		ra(stack_a,size);
	else if (a < b && b > c && a < c)
	{
		sa(*stack_a);
		ra(stack_a,size);
	}
	else if (a < b && b > c)
		rra(stack_a,size);
}

