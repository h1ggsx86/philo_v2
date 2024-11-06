# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnedel <tnedel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/24 19:27:15 by tnedel            #+#    #+#              #
#    Updated: 2024/11/06 14:24:17 by tnedel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc
CFLAGS	= -Wall -Wextra -Werror -g -O0

NEWLINE	= \033[2K\r

INC_DIR	= includes
NAME	= philo

SRC_DIR	= srcs
OBJ_DIR = obj
SRC		= $(SRC_DIR)/philo.c $(SRC_DIR)/error_handler.c \
			$(SRC_DIR)/utils.c $(SRC_DIR)/utils2.c \
			$(SRC_DIR)/philo_action.c $(SRC_DIR)/set_up.c
SRC_OBJ	= $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(SRC_OBJ)
		@$(CC) $(CFLAGS) -I $(INC_DIR) -o $@ $^
		@echo "$(NEWLINE)Compilation Done !"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
		@echo -n "$(NEWLINE)--> $< "
		@$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@
		@sleep 1

$(OBJ_DIR):
		@mkdir -p $@

clean:
		@echo -n "$(NEWLINE)Cleaning..."
		@rm -f $(BON_OBJ) $(SRC_OBJ)
		@rm -rf $(OBJ_DIR)
		@sleep 1
		@echo "$(NEWLINE)All clean"

fclean: clean
		@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
