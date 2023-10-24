# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgiovana <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/10 14:29:18 by mgiovana          #+#    #+#              #
#    Updated: 2023/10/20 12:41:00 by mgiovana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC = actions.c init_args.c time.c utils.c routine.c threads.c main.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror -fPIE -g -pthread

all: $(NAME)
	
$(NAME): $(OBJ)
	@echo "\033[32mCompiling $(NAME)"
	@gcc $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "Compiled\033[0;37m"

clean:
	@echo "\033[0;31mCleaning objects"
	@rm -rf $(OBJ)

fclean: clean
	@echo "\033[0;31mRemoving $(NAME)\033[0;37m"
	@rm -rf $(NAME)

re: fclean all

.SILENT: $(OBJ)
