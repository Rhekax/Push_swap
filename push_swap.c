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

static int	dup_check(t_stack *a)
{
	t_stack	*iter;

	while (a -> next)
	{
          iter = a -> next;
		while (iter)
		{
			if (a->num == iter -> num)
				return (1);
			iter = iter -> next;
		}
		a = a -> next;
	}
	return (0);
}

static t_stack	*fill_stack(char **arg)
{
	t_stack	*top;
	t_stack	*tmp;

	top = malloc (sizeof(t_stack));
	if (!top)
		return (0);
	*top = (t_stack){};
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
			skip_whitespace(&arg);
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
		{
			ft_printf("Error\n");
			exit (EXIT_FAILURE);
		}

		while (args[j][i])
		{
			arg_check(&args[j][i]);
			i++;
		}
		j++;
	}
	return (0);
}

void	sort(t_stack **a, t_stack **b, t_stack *tracker)
{
	if (tracker -> num == 2)
		sort_two_nodes(a);
	else if (tracker -> num == 3)
		sort_three_nodes(a,tracker -> num);
	else if (tracker -> num<= 5)
		sort_four_five_nodes(a, b,tracker);
	else
		sort_big_list(a,b,tracker);
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
	argument_check(av);
	a = fill_stack(av);
	tracker = ft_lstnew(ft_lstsize(a));
	tracker -> next = ft_lstnew(0);
	if (dup_check(a))
		list_error(a, b, tracker);
	get_index(&a,tracker -> num);
	if (check_if_sorted(a))
		return (0);
	else if (tracker -> num == 1)
		return (0);
	sort(&a,&b,tracker);
	return (0);
}
