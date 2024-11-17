/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:09:59 by ekeinan           #+#    #+#             */
/*   Updated: 2024/11/17 17:40:49 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// Print to terminal with a template and value conversions (simplified remake)
int		ft_printf(const char *format, ...);

// Write signed number to terminal
void    ft_putdec(long long n);

// Write unsigned number to terminal
void    ft_putudec(unsigned long long n);

// Write hexadecimal from number (lowercase or uppercase)
void	ft_puthex(long long n, int lowercase);

#endif
