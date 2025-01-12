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

void	checkOverflow(long digit, long result, long sign)
{
	if (sign == -1 && result > (2147483648 - digit) / 10)
		exit(EXIT_FAILURE);
	else if (sign == 1 && result > (2147483647 - digit) / 10)
		exit(EXIT_FAILURE);
}

int	ft_atoi(const char *str)
{
	long	result;
	long	sign;
	long	digit;

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
	if (!ft_isdigit(*str))
		exit(EXIT_FAILURE);
	while (*str >= 48 && *str <= 57)
	{
		digit = *str - 48;
		checkOverflow(digit, result, sign);
		result = result * 10 + digit;
		str++;
	}
	return (result * sign);
}


