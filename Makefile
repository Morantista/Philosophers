# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cballet <cballet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/23 12:10:40 by cballet           #+#    #+#              #
#    Updated: 2024/10/17 18:56:43 by cballet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = gcc
FLAGS = -Wall -Wextra -Werror 
FSANITIZE	= -fsanitize=address -g3
HEADER = -I ./header
GREEN = \033[1;32m
RED = \033[1;91m
NC = \033[0m

SRC_DIR = ./src/
OBJ_DIR = ./obj/

SRC = init_struct main parsing monitoring parsing_utils routine threads utils

SRC_MANDATORY = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC)))
OBJ_MANDATORY = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC)))

mandatory: $(OBJ_DIR) $(NAME) 

$(OBJ_DIR):
	mkdir $(OBJ_DIR)
	
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) $(HEADER) -c $< -o $@ 

$(NAME): $(OBJ_MANDATORY) 
	$(CC) $(CFLAGS) $(OBJ_MANDATORY) $(LIBFT) -o $(NAME)
	@echo "$(GREEN) \n FILES COMPILED \n $(NC)"

clean: 
	rm -rf $(OBJ_DIR) 
	@echo "$(RED) \n FILES CLEANED \n $(NC)"

fclean: clean
	rm -f $(NAME) 

re: fclean mandatory bonus

.PHONY: clean fclean re bonus mandatory