/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   increase_print_count.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:59:53 by ekeinan           #+#    #+#             */
/*   Updated: 2024/11/22 19:52:39 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>

void	increase_print_count(long long increase, long long *print_count)
{
	if (increase < 0)
	{
		*print_count = -1;
		return ;
	}
	if (*print_count >= 0)
		*print_count += increase;
}
