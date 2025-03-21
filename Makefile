# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/11 09:31:47 by ekeinan           #+#    #+#              #
#    Updated: 2024/12/05 12:10:53 by ekeinan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIB = libft.a

SRC = ft_printf.c \
	  increase_print_count.c \
	  print_chars.c \
	  print_int.c \
	  print_ptr.c \
	  print_hex.c

OBJ = $(SRC:.c=.o)

COMPILE_FLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c
	cc $(COMPILE_FLAGS) -c $< -o $@

$(NAME): $(OBJ) $(LIB)
	@mv $(LIB) $(NAME)
	ar -rcs $(NAME) $(OBJ)

libft.a:
	@make -C ./libft
	cp ./libft/$(LIB) ./

clean:
	@cd libft && make $@
	rm -f $(OBJ)

fclean: clean
	@cd libft && make $@
	rm -f $(NAME)

re: fclean all
	@cd libft && make $@

.PHONY: all clean fclean re
