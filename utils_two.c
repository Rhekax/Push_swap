#include "push_swap.h"

void arg_check(const char *args)
{
	if (*args != 32 && !ft_isdigit(*args)
		&& (*args < 9 || *args > 13) &&
		*args != 43 && *args != 45)
	{
		ft_printf("Error: Invalid Input\n");
		exit (EXIT_FAILURE);
	}
	else if ((*(args + 1) == 43 || *(args + 1) == 45)
			&& ft_isdigit(*args))
	{
		ft_printf("Error: Invalid Input\n");
		exit (EXIT_FAILURE);
	}
	else if ((*(args + 1) == 43 || *(args + 1)== 45)
			&& (*args == 43 || *args == 45))
	{
		ft_printf("Error: Invalid Input\n");
		exit (EXIT_FAILURE);
	}
}

void	pb(t_stack **a, t_stack **b, t_stack *a_count, t_stack *b_count)
{
	t_stack	*tmp;

	if (a_count -> num <= 0)
		return ;
	tmp = *a;
	*a = (*a) -> next;
	ft_lstadd_front(b,tmp);
	(b_count -> num)++;
	(a_count -> num)--;
	ft_printf("pb\n");
}

void	ra(t_stack **a, int size)
{
	t_stack	*first;
	t_stack	*newFirst;

	if (size < 2)
		return ;
	first = *a;
	newFirst = (*a) -> next;
	while (first -> next)
		first = first -> next;
	first -> next = *a;
	(*a) -> next = NULL;
	*a = newFirst;
	ft_printf("ra\n");
}

void	rrb(t_stack **b, int size)
{
	t_stack	*last;
	t_stack	*newLast;

	if (size < 2)
		return ;
	last = *b;
	newLast = *b;
	while (last -> next)
	{
		newLast = last;
		last = last -> next;
	}
	newLast -> next = NULL;
	last -> next = *b;
	*b = last;
	ft_printf("rrb\n");
}
void	skip_whitespace(char ***arg)
{
	while ((***arg == 32) || (***arg >= 9 && ***arg <= 13))
		(**arg)++;
}