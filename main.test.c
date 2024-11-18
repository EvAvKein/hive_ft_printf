/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 15:50:06 by ekeinan           #+#    #+#             */
/*   Updated: 2024/11/18 10:56:26 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	char				*str = "string";
	long long			deci = 23847223423;
	unsigned long long	udeci = 23847223423;

	ft_printf("
			ft_printing:\n
			\n
			char: %c, \n
			string: %s, \n
			pointer: %p, \n
			decimal: %d, \n", 
			&str[3],
			str,
			str,
			deci,
			udeci);

	return (0);
}
