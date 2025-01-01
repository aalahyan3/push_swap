# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aalahyan <aalahyan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/21 17:41:33 by aalahyan          #+#    #+#              #
#    Updated: 2025/01/01 15:54:13 by aalahyan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_DIR=libft
LIBFT=$(LIBFT_DIR)/libft.a
CC=cc
CFLAGS= -Wall -Wextra -Werror
NAME=push_swap
MANDATORY_DIR=mandatory
BONUS_DIR=bonus
BIN_DIR=bin
HEADERFILE=$(MANDATORY_DIR)/push_swap.h
MANDATORY_SRCS=	$(MANDATORY_DIR)/main.c \
				$(MANDATORY_DIR)/parse_arguments.c \
				$(MANDATORY_DIR)/free_memory.c \
				$(MANDATORY_DIR)/booleans.c \
				$(MANDATORY_DIR)/assets.c \
				$(MANDATORY_DIR)/init_stack.c \
				$(MANDATORY_DIR)/stack_manipulation.c \
				$(MANDATORY_DIR)/push_swap.c \
				$(MANDATORY_DIR)/phase_1.c \
				$(MANDATORY_DIR)/phase_2.c \
				$(MANDATORY_DIR)/sorting_helpers.c \
				$(MANDATORY_DIR)/init_positions.c
MANDATORY_OBJS = $(addprefix $(BIN_DIR)/, $(notdir $(MANDATORY_SRCS:.c=.o)))

BONUS_SRCS= later


all: $(NAME)
	@echo "\033[1;32mPush_swap is up to date!\033[0m"

inform:
	@echo "\033[1;33mCompiling mandatory...\033[0m"

$(NAME): $(LIBFT) $(BIN_DIR) inform $(MANDATORY_OBJS) $(HEADERFILE)
	@$(CC) $(CFLAGS) $(MANDATORY_OBJS) -L$(LIBFT_DIR) -lft -o $@

$(BIN_DIR):
	@mkdir $(BIN_DIR)
$(LIBFT):
	@make -C $(LIBFT_DIR)

$(BIN_DIR)/%.o: $(MANDATORY_DIR)/%.c $(HEADERFILE)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(BIN_DIR)
	@make clean -C $(LIBFT_DIR)
	@echo "\033[1;31mcleaned!\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C $(LIBFT_DIR)
	@echo "\033[1;31mfull cleaned!\033[0m"



	