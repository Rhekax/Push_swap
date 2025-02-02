#include "push_swap.h"

int ft_find_index(t_stack *stack, int value)
{
	int index = 0;

	while (stack)
	{
		if (stack->num == value)
			return (index);
		stack = stack->next;
		index++;
	}
	return (-1); // Return -1 if the value is not found (should not happen)
}

void ft_sort_two_nodes(t_stack **stack_a)
{
	if ((*stack_a)->num > (*stack_a)->next->num)
		sa(*stack_a);
}

void ft_sort_three_nodes(t_stack **stack_a,int size)
{
	int a = (*stack_a)->num;
	int b = (*stack_a)->next->num;
	int c = (*stack_a)->next->next->num;

	if (a > b && b < c && a < c)
		sa(*stack_a); // Case: 2 1 3 → 1 2 3
	else if (a > b && b > c)
	{
		sa(*stack_a);
		rra(stack_a,size); // Case: 3 2 1 → 1 2 3
	}
	else if (a > b && b < c)
		ra(stack_a,size); // Case: 2 3 1 → 3 1 2
	else if (a < b && b > c && a < c)
	{
		sa(*stack_a);
		ra(stack_a,size); // Case: 1 3 2 → 2 3 1
	}
	else if (a < b && b > c)
		rra(stack_a,size); // Case: 3 1 2 → 1 2 3
}

void ft_sort_four_five_nodes(t_stack **stack_a, t_stack **stack_b,t_stack *tracker)
{
	int size = ft_lstsize(*stack_a);

	while (ft_lstsize(*stack_a) > 3) // Move smallest to stack_b
	{
		t_stack *smallest = *stack_a;
		t_stack *current = *stack_a;
		int min_value = smallest->num;

		while (current) // Find the smallest number
		{
			if (current->num < min_value)
			{
				smallest = current;
				min_value = current->num;
			}
			current = current->next;
		}

		while ((*stack_a)->num != min_value) // Rotate to top
		{
			if (ft_find_index(*stack_a, min_value) < size / 2)
				ra(stack_a, size);
			else
				rra(stack_a,size);
		}
		pb(stack_a, stack_b,tracker,tracker->next); // Push smallest to stack_b
	}

	ft_sort_three_nodes(stack_a,size); // Sort remaining three

	while (*stack_b) // Push elements back to stack_a
		pa(stack_a, stack_b,tracker,tracker->next);
}
