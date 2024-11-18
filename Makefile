# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/11 09:31:47 by ekeinan           #+#    #+#              #
#    Updated: 2024/11/18 10:26:37 by ekeinan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC_CORE = ft_printf.c \
		   ft_putdecimals.c \
		   ft_puthex.c

OBJ_CORE = $(SRC_CORE:.c=.o)

COMPILE_FLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c
	cc $(COMPILE_FLAGS) -c $< -o $@

$(NAME): $(OBJ_CORE)
	@cd libft && make
	ar -rcs $(NAME) $(OBJ_CORE)
	
clean:
	@cd libft && make $@
	rm -f $(OBJ_CORE) ${OBJ_BONUS} 

fclean: clean
	@cd libft && make $@
	rm -f $(NAME)

re: fclean all
	@cd libft && make $@

.PHONY: all bonus clean fclean re
