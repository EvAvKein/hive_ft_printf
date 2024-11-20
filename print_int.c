/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 08:40:17 by ekeinan           #+#    #+#             */
/*   Updated: 2024/11/20 19:38:22 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>
#include "ft_printf.h"

static void	recursive_until_write_last_digit(int n, size_t *print_count)
{
	char	digit_char;

	if (n > 9)
		recursive_until_write_last_digit(n / 10, print_count);
	if (*print_count < 0)
		return;
	digit_char = (n % 10) + '0';
	increase_print_count(write(1, &digit_char, 1), print_count);
}
static void	recursive_until_write_last_udigit(unsigned int n, size_t *print_count)
{
	char	digit_char;

	if (n > 9)
		recursive_until_write_last_digit(n / 10, print_count);
	if (*print_count < 0)
		return;
	digit_char = (n % 10) + '0';
	increase_print_count(write(1, &digit_char, 1), print_count);
}

void	print_int(int n, size_t *print_count)
{
	if (n < 0)
	{
		increase_print_count(write(1, "-", 1), print_count);
		n = -n;
	}
	recursive_until_write_last_digit(n, print_count);
}

void	print_uint(unsigned int n, size_t *print_count)
{
	recursive_until_write_last_udigit(n, print_count);
}
