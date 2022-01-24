# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdavis <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/03 14:39:58 by jdavis            #+#    #+#              #
#    Updated: 2022/01/19 13:30:17 by jdavis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

INCLUDES = libft/includes/ 

CC = clang -Wall -Wextra -Werror

SRC = fillit.c
SRC += tetri_init.c
SRC += tetri_check.c
SRC += collect.c
SRC += square.c
SRC += assemble.c
SRC += error.c

all: $(NAME)

$(NAME):
	@make -C libft/ fclean && make -C libft/
	$(CC) -o $(NAME) $(SRC) -I fillit.h -I $(INCLUDES) -L libft/ -lft

clean:
	@make -C libft/ clean
	rm -f *.o

fclean: clean
	@rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all
