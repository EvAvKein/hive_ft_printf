/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2224/11/14 15:00:24 by ekeinan           #+#    #+#             */
/*   Updated: 2024/11/20 21:26:02 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdint.h>
#include <unistd.h>
#include "libft/libft.h"
#include "ft_printf.h"

static void convert(const char *str, va_list args, size_t *print_count)
{
	str++;

	if (!str)
		return ;
	else if (*str == 'c')
		print_char(va_arg(args, int), print_count);
	else if (*str == 's')
		print_str(va_arg(args, char *), print_count);
	else if (*str == 'p')
		print_ptr(va_arg(args, uintptr_t), print_count);
	else if (*str == 'd')
		print_int(va_arg(args, int), print_count);
	else if (*str == 'i')
		print_int(va_arg(args, int), print_count);
	else if (*str == 'u')
		print_uint(va_arg(args, unsigned int), print_count);
	else if (*str == 'x')
		print_lowercase_hex(va_arg(args, unsigned long long), print_count);
	else if (*str == 'X')
		print_uppercase_hex(va_arg(args, unsigned long long), print_count);
	else if (*str == '%')
		increase_print_count(write(1, "%", 1), print_count);
	else
		increase_print_count(write(1, --str, 2), print_count);
}

static size_t	segment_length(const char *s)
{
	char	*pointer_to_next_sep;

	pointer_to_next_sep = ft_strchr(s, '%');
	if (pointer_to_next_sep)
		return pointer_to_next_sep - s;
	else
		return ft_strlen(s);
}

int	ft_printf(const char *format, ...)
{
	size_t	f_i;
	va_list args;
	size_t	curr_seg_len;
	size_t	print_count;

	va_start(args, format);

	f_i = 0;
	print_count = 0;
	while (format[f_i])
	{
		if (print_count < 0)
			return (print_count);
		if (format[f_i] == '%' && format[f_i + 1])
		{
			convert(&format[f_i], args, &print_count);
			f_i += 2;
			continue ;
		}
		curr_seg_len = segment_length(&format[f_i]);
		increase_print_count(write(1, &format[f_i], curr_seg_len), &print_count);
		f_i += curr_seg_len;
	}

	va_end(args);

	return (print_count);
}
