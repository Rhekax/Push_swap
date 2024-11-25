/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdursun <mdursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:17:41 by mdursun           #+#    #+#             */
/*   Updated: 2024/11/22 19:37:41 by mdursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	dup_check(t_stack *a)
{
	t_stack	*iter;

	iter = a->next;
	while (a->next)
	{
		while(iter)
		{
			if (a->num  == iter->num)
				exit(EXIT_FAILURE);
			iter = iter->next;
		}
		a = a->next;
	}
	return (0);
}

t_stack	*fill_array(char **arg)
{
	t_stack	*top;

	top = malloc (sizeof(t_stack));
	if (!top)
		return (0);
	top->next = NULL;
	arg++;
	while (*arg)
	{
		while (**arg)
		{
			while (**arg == 32 || (**arg >= 9 && **arg <= 13))
				(*arg)++;
			top->num = ft_atoi (*(const char **)arg);
			while (ft_isdigit(**arg) || **arg == 43 || **arg == 45)
				(*arg)++;
			while (**arg == 32 || (**arg >= 9 && **arg <= 13))
				(*arg)++;
			if (!**arg && !*(arg + 1))
				break ;
			ft_lstadd_front(&top, ft_lstnew(ft_atoi(*(const char **)arg)));
		}
		arg++;
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
		while (args[j][i])
		{
			if (args[j][i] != 32 && !ft_isdigit(args[j][i])
			&& (args[j][i] < 9 || args[j][i] > 13) &&
					args[j][i] != 43 && args[j][i] != 45)
				exit (ft_printf("Error\n"));
			else if (args[j][i + 1] == 43
			|| args[j][i + 1] == 45
				&& ft_isdigit(args[j][i]))
				exit (ft_printf("Error\n"));
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
	t_stack		*a_tracker;
	t_stack		*b_tracker;

	a = NULL;
	if (ac == 1)
		exit (EXIT_FAILURE);
	else if (argument_check(av))
		exit (EXIT_FAILURE);
	a = fill_array(av);
	a_tracker = ft_lstnew(ft_lstsize(a));
	b_tracker = ft_lstnew(0);
	a_tracker -> next = b_tracker;
	if (dup_check(a))
		exit (EXIT_FAILURE);
	b = ft_lstmap (a, free);
	
	while (a)
	{
	ft_printf("%d ",a->num);
	a = a->next;
	}
}
