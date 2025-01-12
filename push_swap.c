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

void print_stack(t_stack *stack, const char *name) {
    ft_printf("%s: ", name);
    while (stack) {
        ft_printf("%d ", stack->num);
        stack = stack->next;
    }
    ft_printf("\n");
}

void mergeSort(t_stack **a, t_stack **b, t_stack *a_count, t_stack *b_count) {
    if (a_count->num <= 1) {
        return;  // Base case: single element is trivially sorted
    }
    // Step 1: Divide the stack into two halves by moving half of a to b
    int mid = a_count->num / 2;

    while (mid--) 
	{
        pb(a, b, b_count, a_count);
    }
    ft_printf("----------first half---------\n");
    mergeSort(a, b, a_count, b_count); 
    ft_printf("----------second half---------\n");
    mergeSort(a, b, a_count, b_count); 

    ft_printf("----------last---------\n");
    while (b_count->num > 0) {
        if ((*a)->num <= (*b)->num) {
            pa(a, b, b_count, a_count); 
        } else {
            pb(a, b, b_count, a_count);  
        }
    }
}


// int	checkSort(t_stack *a)
// {
// 	int	tmp;

// 	tmp = a->num;
// 	while(a)
// 	{
// 		if (a->num < tmp)
// 			return(0);
// 		tmp = a->num;
// 		a = a->next;
// 	}
// 	return (1);
// }
// void	sortStack(t_stack **a, t_stack **b, t_stack **tracker)
// {
// 	int	i;

// 	i = 0;
// 	while (i < (*tracker)->num / 2)
// 		pb(a,b,(*tracker)->next,(*tracker));
// 	while(!checkSort(*a))
// 	{
// 		if ((*b)->num > (*a)->num)
			
// 	}
// }


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
	// sortStack(&a,&b,&tracker);
	// pb(&a, &b, tracker, tracker -> next);
	// ft_printf("%d ",checkStacks(&a,&b,&tracker));
	mergeSort(&a,&b,tracker,tracker->next);
	while (a)
	{
	ft_printf("%d a ",a->num);
	a = a->next;
	}
	ft_printf("\n");
	while (b)
	{
	ft_printf("%d ",b->num);
	b = b->next;
	}
}
