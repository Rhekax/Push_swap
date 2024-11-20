/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdursun <mdursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:17:41 by mdursun           #+#    #+#             */
/*   Updated: 2024/11/20 14:17:01 by mdursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*copy_stack(void *c)
{
	return (0);
}
t_stack	*fill_array(char **arg)
{
	t_stack	*top;

	top = malloc (sizeof(t_stack));
	if (!top)
		return ;
	top->next = NULL;
	arg++;
	while (*arg)
	{
		while (**arg)
		{
			while (**arg == 32 || (**arg >= 9 && **arg <= 13))
				(*arg)++;
			top->num = ft_atoi (*(const char **)arg);
			while (ft_isdigit(**arg) || **arg == 43
				|| **arg == 45)
				(*arg)++;
			if (!**arg && !*(arg+1))
				break ;
			ft_lstadd_front(&top, ft_lstnew
				(ft_atoi(*(const char **)arg)));
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
				return (ft_printf("Error\n"), 1);
			i++;
		}
		j++;
	}
	return (0);
}

int	main(int ac, char *av[])
{
	t_stack	*a;
	t_stack *b;

	a = NULL;
	if (ac == 1)
		return (0);
	else if (argument_check(av))
		return (0);
	a = fill_array(av);
	b = ft_lstmap (a,copy_stack,free);
}
