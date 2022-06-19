# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rarahhal <rarahhal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/02 22:03:03 by rarahhal          #+#    #+#              #
#    Updated: 2022/06/19 15:30:37 by rarahhal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAME_BONUS = so_long_bonus
FLAGS = -Wall -Werror -Wextra
CC = cc

SRCS = Mandatory/so_long.c \
		Mandatory/get_next_line.c \
		Mandatory/get_next_line_2.c \
		Mandatory/setting_map.c \
		Mandatory/map_error.c \
		Mandatory/ft_error.c \
		Mandatory/setting_img.c \
		Mandatory/hook.c \
		Mandatory/moving_player.c \
		Mandatory/ft_ckeck_file.c \

BONUS_SRCS = Bonus/so_long_bonus.c \
			Bonus/get_next_line.c \
			Bonus/get_next_line_2.c \
			Bonus/setting_map.c \
			Bonus/map_error.c \
			Bonus/ft_error.c \
			Bonus/setting_img.c \
			Bonus/moving_player.c \
			Bonus/hook.c \
			Bonus/ft_animation.c \
			Bonus/ft_enemy.c \
			Bonus/w_s_a_d_enemy.c \
			Bonus/ft_ckeck_file.c \

LIBFT = Libft/ft_calloc.c \
		Libft/ft_strchr.c \
		Libft/ft_strjoin.c \
		Libft/ft_strlen.c \
		Libft/ft_strdup.c \
		Libft/ft_putnbr.c \
		Libft/ft_itoa.c \

OBJS = $(SRCS:.c=.o)
OBJS_L = $(LIBFT:.c=.o)
OBJS_B = $(BONUS_SRCS:.c=.o)

$(NAME): $(OBJS) $(OBJS_L)
	$(CC) $(FLAGS) -lmlx -framework OpenGL -framework AppKit $(OBJS) $(OBJS_L) -o $(NAME)

$(NAME_BONUS): $(OBJS_B) $(OBJS_L)
	$(CC) $(FLAGS) -lmlx -framework OpenGL -framework AppKit $(OBJS_B) $(OBJS_L) -o $(NAME_BONUS)

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
