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
	t_stack *current = b;

	while (current) {
		if (current->num >a->num) {
			if (current->num < smallest_diff) {
				smallest_diff = current->num;
				position = i;
			}
		}
		current = current->next;
		i++;
	}
	return (position);
}

void	checkOp(t_stack **a, t_stack **b, t_stack *a_count, t_stack *b_count)
{
	int	i[4];
	int flag = 0;
	int mreverse;
	int ireverse = 0;
	// 0 hamle dolaşan b deki indexi yani buluyo gelmesi gereken 1 a da dolaşan index  2 a nın üstündeykenki hamle  3 en az hamlelinin adaki indexi 2+3 toplam gereken hamle
	i[0] = 0;
	i[1] = 0;
	i[2] = 2147483647; // ireverse index from half to count the max move count correctly in the if statement
	i[3] = 0;
	flag = 0;
	ireverse = 0;
	while (i[1] < a_count->num)
	{
		i[0] = checkPosition((*a),(*b));
			if (i[0] < i[2] + ireverse)
			{
				i[2] = i[0];
				if (i[1] > a_count->num / 2)
				{
					mreverse = a_count->num / 2 - flag;
					flag += 1;
				}
				i[3] = i[1]; // eğer flag varsa mreverse artık hamle sayısı ve artık rra
				ireverse = i[3];
				if (flag)
					ireverse = mreverse;
			}
		if (i[3] == i[2] && i[1] + 1 == a_count->num)
		{
			break;
		}
			i[1]++;  // burdan çıkarken i 3 benim en az hamle gerektiren numaram
	}
	 /*printf("0: %d   1 : %d 2 : %d 3 : %d \n",i[0],i[1],i[2],ireverse);*/
	if (i[2] == 0)
	{
		pb(a,b,a_count,b_count);
		/*print_stack(*a,"a");
		print_stack(*b,"b");*/
		sb(*b);
		/*print_stack(*a,"a");
		print_stack(*b,"b");*/
	}
	else if (i[2] == -1 || i[0] == -1)
	{
		if (b_count->num > 2) {
			i[2] = maxstack(*b);
			while (i[2]--)
				rb(b,b_count->num);
		}

		pb(a,b,a_count,b_count);
		/*print_stack(*a,"a");
		print_stack(*b,"b");*/
	}
	else if(ireverse == i[2])
	{
		while (ireverse++ != 0)
		{
			rrr(a, b, a_count->num, b_count->num);
			if ( ireverse == a_count->num)
				ireverse = 0;
			/*print_stack(*a,"a");
			print_stack(*b,"b");*/
		}
		checkOp(a,b,a_count,b_count);
	}
	else if (ireverse)
	{
		while (!flag && ireverse--)
		{
			ra(a,a_count->num);
			/*print_stack(*a,"a");
			print_stack(*b,"b");*/
		}
		while (flag && ireverse++)
		{
			rra(a,a_count->num);
			if (ireverse == a_count->num)
				ireverse = 0;
			/*print_stack(*a,"a");
			print_stack(*b,"b");*/
		}
		checkOp(a,b,a_count,b_count);
	}
	else
	{
		if (i[2] > b_count->num / 2) {
			while (i[2]++)
			{
				rrb(b,b_count->num);
				if (b_count->num == i[2])
					i[2] = 0;
				/*print_stack(*a,"a");
				print_stack(*b,"b");*/
			}
		}
		else {
			while (i[2]--) {
				rb(b,b_count->num);
				/*print_stack(*a,"a");
				print_stack(*b,"b");*/
			}
		}
		checkOp(a,b,a_count,b_count);
	}
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
	while (!checkSort(*a))
	{
		if (locationi(*a) < a_count->num / 2)
			ra(a,a_count->num);
		else
			rra(a,a_count->num);
		/*print_stack(*a,"a");
		print_stack(*b,"b");*/
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
