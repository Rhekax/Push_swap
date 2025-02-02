/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdursun <mdursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:17:41 by mdursun           #+#    #+#             */
/*   Updated: 2024/12/15 21:23:11 by mdursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
// void trial(t_stack **a, t_stack **b, t_stack *ac, int num) {
// 	t_stack *temp = *a;
// 	t_stack *temp1 = *b;


// }
void print_stack(t_stack *stack, const char *name) {
    ft_printf("%s: ", name);
    while (stack) {
        ft_printf("%d ", stack->num);
        stack = stack->next;
    }
    ft_printf("\n");
}
int maxstack(t_stack *stack) {
	int max = stack->num;
	int i = 0;
	int j = 0;
	while (stack) {
		if (stack->num > max) {
			max = stack->num;
			j = i;
		}
		stack = stack->next;
		i++;
	}
	return j;
}
int checkPosition(t_stack *a, t_stack *b) {
	int i = 0;
	int position = -1;
	long long smallest_diff = 9223372036854775807;
	long long smallest_num = 9223372036854775807;
	t_stack *current = b;

	while (current) {
		// Check if current->num is greater than a->num
		if (current->num > a->num) {
			if (current->num < smallest_diff) {
				smallest_diff = current->num;
				position = i;
			}
		}
		// Track the smallest number in stack b
		if (current->num < smallest_num) {
			smallest_num = current->num;
			// Update position only if no greater number is found
			if (smallest_diff == 9223372036854775807) {
				position = i;
			}
		}
		current = current->next;
		i++;
	}
	return (position);
}
void checkOp(t_stack **a, t_stack **b, t_stack *a_count, t_stack *b_count) {
    int best_move = 2147483647; // Initialize to a large value
    int best_rotation_a = 0;
    int best_rotation_b = 0;
    int current_index = 0;
    int position_in_b = 0;

    // Find the best move for each element in stack A
    t_stack *current_a = *a;

    while (current_a) {
        position_in_b = checkPosition(current_a, *b);
        int rotations_a = current_index;
        int rotations_b = position_in_b;

        // Calculate the total moves required
        int total_moves = rotations_a + rotations_b;

        // Check if this is the best move so far
        if (total_moves < best_move) {
            best_move = total_moves;
            best_rotation_a = rotations_a;
            best_rotation_b = rotations_b;
        }

        current_a = current_a->next;
        current_index++;
    }

    printf("The best move is %d\n", best_move);
    print_stack((*a), "a");
    print_stack((*b), "b");
	printf("The best rotation is %d\n", position_in_b);
    if (position_in_b > -1) {


        // Determine if combined rotations can be used
        if (best_rotation_a <= a_count->num / 2 && best_rotation_b <= b_count->num / 2) {
            // Use rr (rotate both stacks forward)
            int min_rotations = (best_rotation_a < best_rotation_b) ? best_rotation_a : best_rotation_b;
            while (min_rotations--) {
                rr(a, b, a_count->num, b_count->num);
            }
            best_rotation_a -= min_rotations;
            best_rotation_b -= min_rotations;
        } else if (best_rotation_a > a_count->num / 2 && best_rotation_b > b_count->num / 2) {
            // Use rrr (rotate both stacks backward)
            int min_rotations = (a_count->num - best_rotation_a < b_count->num - best_rotation_b)
                                ? (a_count->num - best_rotation_a)
                                : (b_count->num - best_rotation_b);
            while (min_rotations--) {
                rrr(a, b, a_count->num, b_count->num);
            }
            best_rotation_a += min_rotations;
            best_rotation_b += min_rotations;
        }

        // Perform remaining rotations individually
        if (best_rotation_a <= a_count->num / 2) {
            while (best_rotation_a--) {
                ra(a, a_count->num);
            }
        } else {
            best_rotation_a = a_count->num - best_rotation_a;
            while (best_rotation_a--) {
                rra(a, a_count->num);
            }
        }

        if (best_rotation_b <= b_count->num / 2) {
            while (best_rotation_b--) {
                rb(b, b_count->num);
            }
        } else {
            best_rotation_b = b_count->num - best_rotation_b;
            while (best_rotation_b--) {
                rrb(b, b_count->num);
            }
        }
    }

    // Push the element from stack A to stack B
    pb(a, b, a_count, b_count);
}
int	checkSort(t_stack *a)
{
	int	tmp;

	tmp = a->num;
	while(a)
	{
		if (a->num < tmp)
			return(0);
		tmp = a->num;
		a = a->next;
	}
	return (1);
}

int	locationi(t_stack *a) {
	int location = 0;
	int min = a->num;
	int min_location = 0;

	while (a) {
		if (a->num < min) {
			min = a->num;
			min_location = location;
		}
		location++;
		a = a->next;
	}
	return (min_location);
}
void sort(t_stack **a, t_stack **b, t_stack *a_count, t_stack *b_count)
{
	pb(a,b,a_count,b_count);
	pb(a,b,a_count,b_count);
	while (a_count->num)
	{
		checkOp(a,b,a_count,b_count);
	}
	while (*b)
	{
		pa(a,b,a_count,b_count);
	// 		print_stack(*a,"a");
	// print_stack(*b,"b");
	}
	while (locationi(*a) != 0)
	{
		if (locationi(*a) <= a_count->num / 2)
			ra(a,a_count->num);
		else
			rra(a,a_count->num);
		print_stack(*a,"a");
		print_stack(*b,"b");
	}
}

int	dup_check(t_stack *a)
{
	t_stack	*iter;

	while (a -> next)
	{
          iter = a -> next;
		while (iter)
		{
			if (a->num == iter->num)
				exit(EXIT_FAILURE);
			iter = iter->next;
		}
		a = a -> next;
	}
	return (0);
}

t_stack	*fill_stack(char **arg)
{
	t_stack	*top;
	t_stack	*tmp;

	top = malloc (sizeof(t_stack));
	*top = (t_stack){};
	if (!top)
		return (0);
	tmp = top;
	while (*(++arg))
	{
		while (**arg)
		{
			while (**arg == 32 || (**arg >= 9 && **arg <= 13))
				(*arg)++;
			tmp -> num = ft_atoi (*(const char **)arg);
			while (ft_isdigit(**arg) || **arg == 43 || **arg == 45)
				(*arg)++;
			while (**arg == 32 || (**arg >= 9 && **arg <= 13) )
				(*arg)++;
			if (!**arg && !*(arg + 1))
				break ;
			ft_lstadd_back(&tmp, ft_lstnew(tmp->num));
			tmp = tmp -> next;
		}
	}
	return (top);
}

int	argument_check(char **args)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (args[j])
	{
		i = 0;
		if (!args[j][i])
			exit(EXIT_FAILURE);
		while (args[j][i])
		{
			if (args[j][i] != 32 && !ft_isdigit(args[j][i])
			&& (args[j][i] < 9 || args[j][i] > 13) &&
					args[j][i] != 43 && args[j][i] != 45)
				exit (EXIT_FAILURE);
			else if ((args[j][i + 1] == 43 || args[j][i + 1] == 45)
				&& ft_isdigit(args[j][i]))
				exit (EXIT_FAILURE);
			else if (((args[j][i + 1] == 43 || args[j][i + 1] == 45)
					&& (args[j][i] == 43 || args[j][i] == 45)))
				exit (EXIT_FAILURE);
			i++;
		}
		j++;
	}
	return (0);
}

int	main(int ac, char *av[])
{
	t_stack		*a;
	t_stack		*b;
	t_stack		*tracker;

	a = NULL;
	b = NULL;
	if (ac == 1)
		exit (EXIT_FAILURE);
	else if (argument_check(av))
		exit (EXIT_FAILURE);
	a = fill_stack(av);
	tracker = ft_lstnew(ft_lstsize(a));
	tracker -> next = ft_lstnew(0);
	if (dup_check(a))
		exit (EXIT_FAILURE);
	// print_stack(a,"a");
	// sortStack(&a,&b,&tracker);
	// pb(&a, &b, tracker, tracker -> next);
	// ft_printf("%d ",checkStacks(&a,&b,&tracker));
	sort(&a,&b,tracker,tracker->next);
	// while (a)
	// {
	// ft_printf("%d a ",a->num);
	// a = a->next;
	// }
	// ft_printf("\n");
	// while (b)
	// {
	// ft_printf("%d ",b->num);
	// b = b->next;
	// }
}
