# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/14 14:43:36 by dkhoo             #+#    #+#              #
#    Updated: 2025/09/21 16:05:19 by dkhoo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
DEBUG_FLAGS = -g
CCFLAGS = -Wall -Wextra -Werror $(DEBUG_FLAGS)

LIBFT_DIR = libft
LIBFT = -L$(LIBFT_DIR) -lft
LIBFT_INCLUDE_DIR = $(LIBFT_DIR)/includes
LIBFT_HEADER = $(LIBFT_INCLUDE_DIR)/libft.h $(LIBFT_INCLUDE_DIR)/ft_printf.h $(LIBFT_INCLUDE_DIR)/get_next_line_bonus.h $(LIBFT_INCLUDE_DIR)/extra.h
LIBFT_LIB = $(LIBFT_DIR)/libft.a

PS_INCLUDE_DIR = includes
PS_HEADER = $(PS_INCLUDE_DIR)/push_swap.h
INCLUDES = -I$(PS_INCLUDE_DIR) -I$(LIBFT_INCLUDE_DIR)

SRCS_DIR = srcs
SRC_FILES = CBI_helper.c\
			CBI.c\
			create.c\
			free.c\
			instruct_comb.c\
			instruct_single.c\
			LIS_helper.c\
			LIS.c\
			log.c\
			main.c\
			normalize.c\
			preprocess.c\
			sort_big_helper.c\
			sort_big.c\
			sort_small.c\
			stack_ops_extra.c\
			stack_ops_std.c\
			utils.c\
			validate.c
SRCS = $(addprefix $(SRCS_DIR)/, $(SRC_FILES))
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_LIB)
	$(CC) $(CCFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c $(LIBFT_HEADER) $(PS_HEADER)
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