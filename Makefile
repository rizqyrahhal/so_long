# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rarahhal <rarahhal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/02 22:03:03 by rarahhal          #+#    #+#              #
#    Updated: 2022/06/02 22:06:24 by rarahhal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAME_BONUS = 
FLAGS = -Wall -Werror -Wextra
CC = CC

SRCS = Mandatory/so_long.c \

BONUS_SRCS = Bonus/

LIBFT = libft/

OBJS = $(SRCS:.c=.o)
OBJS_L = $(LIBFT:.c=.o)
OBJS_B = $(BONUS_SRCS:.c=.o)

$(NAME): $(OBJS) $(OBJS_L)
	$(CC) $(FLAGS) $(OBJS) $(OBJS_L) -o $(NAME)

$(NAME_BONUS): $(OBJS_B) $(OBJS_L)
	$(CC) $(FLAGS) $(OBJS_B) $(OBJS_L) -o $(NAME_BONUS)


all: $(NAME)

bonus: $(NAME_BONUS)

clean:
	@rm -f bonus/*.o
	@rm -f Mandatory/*.o
	@rm -f libft/*.o

fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAME_BONUS)

re: fclean
	@make all


.PHONY: all bonus clean fclean re
