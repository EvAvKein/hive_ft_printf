# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/11 09:31:47 by ekeinan           #+#    #+#              #
#    Updated: 2024/11/13 17:32:15 by ekeinan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC_CORE = 

OBJ_CORE = $(SRC_CORE:.c=.o)

COMPILE_FLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c
	cc $(COMPILE_FLAGS) -c $< -o $@

$(NAME): $(OBJ_CORE)
	ar -rcs $(NAME) $(OBJ_CORE)
	
clean:
	rm -f $(OBJ_CORE) ${OBJ_BONUS} 

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
