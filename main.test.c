/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 15:50:06 by ekeinan           #+#    #+#             */
/*   Updated: 2024/11/20 21:25:09 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft/libft.h"
#include "ft_printf.h"

int	main(void)
{
	char				*str = "some characters";
	long long			digits = -2384423;
	int					inte = 320742;
	unsigned long long	udigits = 2384742423;
	size_t				chars;
	char 				format[] = "ft_printing:\n\nchar: %c, \nstring: %s, \npointer: %p, \ndigits: %d, \ninteger: %i, \nunsigned digits: %u, \nhexadecimal (lowercase): %x, \nhexadecimal (uppercase): %X\n";
	
	chars = ft_printf(
		format, 
		str[5],
		str,
		str,
		digits,
		inte,
		udigits,
		inte,
		inte
	);
	
	ft_printf("format len: %i, printed len: %i\n", ft_strlen(format), chars);

	ft_printf("---------\n");

	char				*printf = "ft_printing:\ninvalid %y conversion";

	ft_printf(printf);

	return (0);
}
