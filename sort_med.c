#include "push_swap.h"

int	find_min(t_stack *stack)
{
	int min = stack -> num;

	while (stack)
	{
		if (stack -> num < min)
			min = stack -> num;
		stack = stack -> next;
	}
	return (min);
}
void	push_smallest_to_b(t_stack **stack_a, t_stack **stack_b, t_stack *tracker)
{
	int min_value = find_min(*stack_a);

	while ((*stack_a) -> num != min_value)
	{
		if (find_index(*stack_a, min_value) < tracker -> num / 2)
			ra(stack_a, tracker -> num);
		else
			rra(stack_a, tracker -> num);
	}
	pb(stack_a, stack_b, tracker, tracker -> next);
}

void	sort_four_five_nodes(t_stack **stack_a, t_stack **stack_b, t_stack *tracker)
{
	while (tracker -> num > 3)
		push_smallest_to_b(stack_a, stack_b, tracker);
	sort_three_nodes(stack_a,ft_lstsize(*stack_a));
	while (*stack_b)
		pa(stack_a, stack_b, tracker, tracker -> next);
}