# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/05 08:59:33 by dkhoo             #+#    #+#              #
#    Updated: 2025/08/24 09:40:44 by dkhoo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CCFLAGS = -Wall -Wextra -Werror
DEBUG = -g -O0
MATH = -lm

# libft
LIBFT_DIR = libft
LIBFT = -L$(LIBFT_DIR) -lft
LIBFT_INCLUDE_DIR = $(LIBFT_DIR)/includes
LIBFT_HEADER = $(LIBFT_INCLUDE_DIR)/libft.h $(LIBFT_INCLUDE_DIR)/ft_printf.h $(LIBFT_INCLUDE_DIR)/get_next_line_bonus.h $(LIBFT_INCLUDE_DIR)/extra.h
LIBFT_LIB = $(LIBFT_DIR)/libft.a

# push_swap
PS_INCLUDE_DIR = includes
PS_HEADER = $(PS_INCLUDE_DIR)/push_swap.h
INCLUDES = -I$(PS_INCLUDE_DIR) -I$(LIBFT_INCLUDE_DIR)

SRCS_DIR = srcs
SRC_FILES = error.c\
			init.c\
			instruct-push.c\
			instruct-revrotate.c\
			instruct-rotate.c\
			instruct-swap.c\
			log.c\
			main.c\
			sort-big-utils.c\
			sort-big.c\
			sort-small.c\
			stack-read.c\
			stack-write.c\
			validate-input.c
SRCS = $(addprefix $(SRCS_DIR)/, $(SRC_FILES))
OBJS = $(SRCS:.c=.o)

debug: $(OBJS) $(LIBFT_LIB)
	$(CC) $(CCFLAGS) $(DEBUG) $(OBJS) $(LIBFT) $(MATH) -o $(NAME)

all: $(OBJS) $(LIBFT_LIB)
	$(CC) $(CCFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(SRCS_DIR)/%.o: $(SRCS_DIR)/%.c $(LIBFT_HEADER) $(PS_HEADER)
	$(CC) $(CCFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT_LIB):
	make -C $(LIBFT_DIR) all

clean:
	rm -rf $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re