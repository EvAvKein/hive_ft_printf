/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 08:40:17 by ekeinan           #+#    #+#             */
/*   Updated: 2024/11/22 19:55:09 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>
#include "ft_printf.h"

static void	recursive_write_last_digit(int n, long long *print_count)
{
	char	digit_char;

	if (n > 9)
		recursive_write_last_digit(n / 10, print_count);
	if (*print_count < 0)
		return ;
	digit_char = (n % 10) + '0';
	increase_print_count(write(1, &digit_char, 1), print_count);
}

static void	recursive_write_last_udigit(unsigned int n, long long *print_count)
{
	char	digit_char;

	if (n > 9)
		recursive_write_last_digit(n / 10, print_count);
	if (*print_count < 0)
		return ;
	digit_char = (n % 10) + '0';
	increase_print_count(write(1, &digit_char, 1), print_count);
}

void	print_int(int n, long long *print_count)
{
	if (n == -2147483648)
	{
		increase_print_count(write(1, "-2147483648", 11), print_count);
		return ;
	}
	if (n < 0)
	{
		increase_print_count(write(1, "-", 1), print_count);
		if (*print_count < 0)
			return ;
		n = -n;
	}
	recursive_write_last_digit(n, print_count);
}

void	print_uint(unsigned int n, long long *print_count)
{
	recursive_write_last_udigit(n, print_count);
}
