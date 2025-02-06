#include "push_swap.h"

void	list_error(t_stack *a, t_stack *b, t_stack *tracker)
{
	free(tracker -> next);
	free(tracker);
	free(a);
	if (b)
		free(b);
	ft_printf("Error\n");
	exit (EXIT_FAILURE);
}

void	sa(t_stack *top)
{
	int	tmp;

	if (!top || !top -> next)
		return ;
	tmp = top->num;
	top -> num = top -> next -> num;
	top -> next -> num = tmp;
	ft_printf("sa\n");
}

void	sb(t_stack *top)
{
	int	tmp;

	if (!top || !top -> next)
		return ;
	tmp = top->num;
	top -> num = top -> next -> num;
	top -> next -> num = tmp;
	ft_printf("sb\n");
}

void	ss(t_stack *a, t_stack *b)
{
	int	tmp;

	if (!a || !a -> next)
		return ;
	tmp = a -> num;
	a -> num = a -> next -> num;
	a -> next -> num = tmp;
	if (!b || !b -> next)
		return ;
	tmp = b -> num;
	b -> num = b -> next -> num;
	b -> next -> num = tmp;
	ft_printf("ss\n");
}

void	pa(t_stack **a, t_stack **b, t_stack *a_count, t_stack *b_count)
{
	t_stack	*tmp;

	if (b_count -> num <= 0)
		return ;
	tmp = *b;
	*b = (*b) -> next;
	ft_lstadd_front(a,tmp);
	b_count -> num--;
	a_count -> num++;
	ft_printf("pa\n");
}