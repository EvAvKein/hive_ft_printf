/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_arg_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:43:09 by ekeinan           #+#    #+#             */
/*   Updated: 2024/11/14 19:16:42 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

input_data parse_arg_data(const char *template, ...)
{
	size_t			t_i;
    va_list 		args;
    unsigned int 	arg_count;

	t_i = 0;
    va_start(args, count);
	while (template[t_i])
	{
		if (template[t_i] == '%' && (t_i && ))
		{
			
		}
	}

    va_end(args);
}

