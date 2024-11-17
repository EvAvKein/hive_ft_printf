/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 17:16:39 by ekeinan           #+#    #+#             */
/*   Updated: 2024/11/17 18:10:12 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

static void recursive_until_write_last_hex(long long n, int lowercase)
{
    int chr = 63;

	if (n > 15)
	{
        recursive_until_write_last_hex(n / 16, lowercase);
		n %= 16;
	}
	if (n < 10)
		chr = (n % 10) + '0';
	else if (lowercase)
		chr = (n % 10) + 'a';
	else
		chr = (n % 10) + 'A';
	
	//ft_printf("digit: %d, char: %c\n", n, chr);
    write(1, &chr, 1);
}

void ft_puthex(long long n, int lowercase)
{
	recursive_until_write_last_hex(n, lowercase);	
}
