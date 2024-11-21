/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:09:59 by ekeinan           #+#    #+#             */
/*   Updated: 2024/11/20 22:01:28 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdint.h>
# include <stddef.h>

// Print to terminal with a template and value conversions (simplified remake)
int		ft_printf(const char *format, ...);

// Increase print count if it's still a valid count, or set to invalid if new is
void	increase_print_count(size_t increase, size_t *print_count);

// Print a character and increase print count
void	print_char(char c, size_t *print_count);

// Print a string and increase print count
void	print_str(char *s, size_t *print_count);

// Print a pointer address and increase print count
void	print_ptr(uintptr_t ptr_as_num, size_t *print_count);

// Print an integer and increase print count
void	print_int(int n, size_t *print_count);

// Print an unsigned integer and increase print count
void	print_uint(unsigned int n, size_t *print_count);

// Print a lowercase hexadecimal by number and increase print count
void	print_lowercase_hex(unsigned long long n, size_t *print_count);

// Print a uppercase hexadecimal by number and increase print count
void	print_uppercase_hex(unsigned long long n, size_t *print_count);

#endif
