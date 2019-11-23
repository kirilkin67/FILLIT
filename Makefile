# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wrhett <wrhett@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/15 20:07:08 by wrhett            #+#    #+#              #
#    Updated: 2019/11/23 15:20:26 by wrhett           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = main.c \
		ft_fillit_validation.c ft_tetrimino_validation.c \
		ft_array_struct_create.c ft_puzzle.c ft_print_tetrimino.c \
		ft_puzzle_soluthion.c
		

OBJECTS = $(patsubst %.c, %.o, $(SRC))

HEADER = fillit.h

LIBFT = $(LIBFT_PATH)libft.a
LIBFT_PATH = libft/

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(LIBFT) $(OBJECTS)
		@gcc -o $(NAME) $(OBJECTS) -I $(LIBFT_PATH)includes -L $(LIBFT_PATH) -lft
		@echo "\033[32m$(NAME) was created\033[0m"

$(LIBFT): FAKE
		@$(MAKE) -C $(LIBFT_PATH)

%.o: %.c
		@gcc $(FLAGS) -I $(HEADER) -o $@ -c $<

test:	all
		@./fillit test4
clean:
		@/bin/rm -f $(OBJECTS)
		@$(MAKE) -C $(LIBFT_PATH) clean

fclean: clean
		@/bin/rm -f $(NAME)
		@$(MAKE) -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re FAKE
