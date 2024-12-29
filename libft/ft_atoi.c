/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdursun <mdursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:34:02 by mdursun           #+#    #+#             */
/*   Updated: 2024/12/15 21:07:10 by mdursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	checkOverflow(int tmp, int result, int sign)
{
	if (sign == -1 && tmp < result)
		exit(EXIT_FAILURE);
	else if (sign == 1 && tmp > result)
		exit(EXIT_FAILURE);
}

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;
	int	tmp;

	sign = 1;
	result = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == 45 || *str == 43)
	{
		if (*str == 45)
			sign = -1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		tmp = result;
		result = result * 10 + (*str - 48);
		checkOverflow(tmp, result, sign);
		str++;
	}
	return (result * sign);
}


