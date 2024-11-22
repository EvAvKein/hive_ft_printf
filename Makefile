# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/11 09:31:47 by ekeinan           #+#    #+#              #
#    Updated: 2024/11/21 12:06:50 by ekeinan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIB = libft.a

SRC_CORE = ft_printf.c \
		   increase_print_count.c \
		   print_chars.c \
		   print_int.c \
		   print_ptr.c \
		   print_hex.c

OBJ_CORE = $(SRC_CORE:.c=.o)

COMPILE_FLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c
	cc $(COMPILE_FLAGS) -c $< -o $@

$(NAME): $(OBJ_CORE) $(LIB)
	@mv $(LIB) $(NAME)
	ar -rcs $(NAME) $(OBJ_CORE)

libft.a:
	@make -C ./libft
	cp ./libft/$(LIB) ./

clean:
	@cd libft && make $@
	rm -f $(OBJ_CORE) ${OBJ_BONUS} 

fclean: clean
	@cd libft && make $@
	rm -f $(NAME) $()

re: fclean all
	@cd libft && make $@

.PHONY: all bonus clean fclean re
