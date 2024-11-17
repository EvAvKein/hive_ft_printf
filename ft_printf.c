/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2224/11/14 15:00:24 by ekeinan           #+#    #+#             */
/*   Updated: 2024/11/17 17:40:34 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "libft/libft.h"
#include "ft_printf.h"

static int conv_match(const char *str, char *conv)
{
	return (!ft_strncmp(str, conv, 2));
}
static void process_conversion(const char *str, va_list args)
{
	if (!str)
		return ;
	else if (conv_match(str, "%c"))
		ft_putchar_fd(va_arg(args, int), 1);
	else if (conv_match(str, "%s"))
		ft_putstr_fd((char *) va_arg(args, int *), 1);
	else if (conv_match(str, "%p"))
		write(1, "<\"%p\" NOT IMPLEMENTED>", 22);
	else if (conv_match(str, "%d"))
		ft_putdec(va_arg(args, long long));
	else if (conv_match(str, "%i"))
		ft_putnbr_fd(va_arg(args, int), 1);
	else if (conv_match(str, "%u"))
		ft_putudec(va_arg(args, unsigned long long));
	else if (conv_match(str, "%x"))
		ft_puthex(va_arg(args, long long), 1);
	else if (conv_match(str, "%X"))
		ft_puthex(va_arg(args, long long), 0);
	else if (conv_match(str, "%%"))
		write(1, "%%", 2);
	else
		write(1, str, 2);
}

int	ft_printf(const char *format, ...)
{
	size_t	f_i;
	va_list args;
	//char	*next_section;

	va_start(args, format);

	f_i = 0;
	while (format[f_i])
	{
		if (format[f_i] == '%' && format[f_i + 1])
		{
			process_conversion(&format[f_i], args);
			f_i += 2;
			continue ;
		}
		write(1, &format[f_i++], 1);
	}

	va_end(args);

	return (1);
}
