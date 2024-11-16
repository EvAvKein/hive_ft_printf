/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:00:24 by ekeinan           #+#    #+#             */
/*   Updated: 2024/11/16 21:05:17 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "libft.h"
#include "ft_printf.h"

static int conv_match(char *str, char *conv)
{
	return (!ft_strncmp(str, conv, 2));
}

static int process_conversion(const char *str, va_list args)
{
	void *arg_val;

	if (!str)
		return (0);
	else if (conv_match(str, "%c"))
		ft_putchar_fd(va_arg(args, char), 1);
	else if (conv_match(str, "%s"))
		ft_putstr_fd(va_arg(args, char *), 1);
	else if (conv_match(str, "%p"))
		// write(1, va_args(args, *), 8);
	else if (conv_match(str, "%d"))
		ft_putdec(va_arg(args, long long));
	else if (conv_match(str, "%i"))
		ft_putnbr_fd(va_arg(args, int), 1);
	else if (conv_match(str, "%u"))
		ft_putudec(va_arg(args, unsigned long long));
	else if (conv_match(str, "%x"))

	else if (conv_match(str, "%X"))

	else if (conv_match(str, "%%"))
		write(1, "%%", 2);
	else
	{

	}
}

int	ft_printf(const char *format, ...)
{
	size_t	f_i;
	va_list args;
	char	*next_section;

	va_start(args, format);
	
	while (format[f_i])
	{
		if (format[f_i] == '%')
		{
			f_i += process_conversion(&format[f_i], args);
			continue ;
		}
		write(1, &format[f_i++], 1);
	}


	va_end(args);
}
