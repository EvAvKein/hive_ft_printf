/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:23:06 by ekeinan           #+#    #+#             */
/*   Updated: 2024/11/20 22:01:50 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

void	print_ptr(uintptr_t ptr_as_num, size_t *print_count)
{
	if (!ptr_as_num)
	{
		increase_print_count(write(1, "(nil)", 5), print_count);
		return ;
	}
	increase_print_count(write(1, "0x", 2), print_count);
	if (*print_count < 0)
		return ;
	print_lowercase_hex(ptr_as_num, print_count);
}
