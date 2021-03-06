# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mplutarc <mplutarc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/08 20:23:00 by mplutarc          #+#    #+#              #
#    Updated: 2019/10/08 20:50:59 by mplutarc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
FILES = main.c
SRC = $(addprefix src/, $(FILES))
INC = incudes/ft_ls.h
OBJ = $(addprefix obj/, $(FILES:.c=.o))
LIBFT = libft/libft.a
FLAGS = -Wall -Wextra -Werror


all: lib ft_ls

lib:
	@make -C libft

ft_ls: $(OBJ)
	gcc $(FLAGS) $(OBJ) $(LIBFT) -o $(NAME) 

obj/%.o: src/%.c | obj
	gcc -c -I./libft $< -o $@

clean:
	/bin/rm -rf ./obj
	make -C libft clean

obj:
	mkdir -p obj

fclean: clean
	/bin/rm -rf $(NAME) ./obj
	make -C libft fclean

re: fclean all