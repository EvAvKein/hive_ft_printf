/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdecimals.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 20:27:38 by ekeinan           #+#    #+#             */
/*   Updated: 2024/11/16 20:58:17 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	recursive_until_write_last_digit(int n)
{
	int	digit_char;

	if (n > 9)
		recursive_until_write_last_digit(n / 10, fd);
	digit_char = (n % 10) + '0';
	write(1, &digit_char, 1);
}

void	ft_putudec(long long n)
{
	if (n == -9223372036854775807)
	{
		write(fd, "-9223372036854775807", 20);
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	recursive_until_write_last_digit(n);
}

void	ft_putdec(unsigned long long n)
{
	ft_putudec(n);
}
