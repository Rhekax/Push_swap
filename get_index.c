#include "push_swap.h"
void get_index(t_stack **a,int size)
{
	t_stack	*smallest_node;
	t_stack	*tmp;
	int index;
	int smallest;

	index = 0;
	tmp = *a;
	while (index < size)
	{
		smallest = 2147483647;
		tmp = *a;
		while (tmp != NULL)
		{
			if (tmp->num < smallest && !tmp->assigned)
			{
				smallest_node = tmp;
				smallest = tmp->num;
			}
			tmp = tmp->next;
		}
		smallest_node->index = index;
		smallest_node->assigned = 1;
		index++;
	}

}
int	check_if_sorted(t_stack *stack_a)
{
	while (stack_a->next != NULL && stack_a->num < stack_a->next->num)
	{
		stack_a = stack_a->next;
	}
	if (stack_a->next == NULL)
		return (1);
	else
		return (0);
}

void sort_big_list(t_stack **stack_a, t_stack **stack_b, t_stack *tracker)
{
	int bit_pos;
	int count;
	int max_bits;
	int size;

	size = tracker->num; // Number of elements in stack
	max_bits = 0;

	// Find the max bits needed (log2 of max index)
	while ((size - 1) >> max_bits)
		max_bits++;

	bit_pos = 0;
	while (bit_pos < max_bits && !check_if_sorted(*stack_a))
	{
		count = 0;
		while (count++ < size)
		{
			if ((((*stack_a)->index >> bit_pos) & 1) == 0)
				pb(stack_a, stack_b, tracker, tracker->next); // Push to B if bit is 0
			else
				ra(stack_a, tracker->num); // Rotate A if bit is 1
		}

		while (*stack_b)
			pa(stack_a, stack_b, tracker, tracker->next); // Push everything back to A

		bit_pos++; // Move to the next bit position
	}
}