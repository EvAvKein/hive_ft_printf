/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 08:40:17 by ekeinan           #+#    #+#             */
/*   Updated: 2024/11/20 08:40:19 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	recursive_until_write_last_digit(int n, int fd)
{
	int	digit_char;

	if (n > 9)
		recursive_until_write_last_digit(n / 10, fd);
	digit_char = (n % 10) + '0';
	write(fd, &digit_char, 1);
}

void	ft_putunbr_fd(int n, unsigned int fd)
{
	recursive_until_write_last_digit(n, fd);
}

