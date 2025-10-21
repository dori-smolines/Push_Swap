# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smolines <smolines@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/15 09:42:50 by smolines          #+#    #+#              #
#    Updated: 2024/06/04 20:36:12 by smolines         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= push_swap

BONUS			= push_swap_bonus

CC          	= cc

CFLAGS      	= -Wall -Wextra -Werror -g3

HEADER_FILES	= pushswap.h

HEADER			= -I./include

SRC_PATH		= src/

OBJ_PATH		= obj/

RM 				= rm -rf

SRCS = cost.c \
	create_lst.c \
	error_free.c \
	ft_split.c \
	index_position.c \
	move_stack.c \
	parsing.c \
	parsing_util.c \
	parsing_util2.c \
	push_swap.c \
	rotate.c \
	reverse_rotate.c \
	push.c \
	swap.c \
	util.c \

SRCS_BONUS = 

SRCS_ALL = ${SRCS_BONUS} ${SRCS} 

OBJS = $(addprefix ${OBJ_PATH}, ${SRCS:.c=.o})

OBJS_BONUS = ${SRCS_BONUS:.c=.o}

OBJS_ALL = ${SRCS_ALL:.c=.o}

all: $(NAME)

bonus: ${BONUS}

$(NAME) : ${OBJS}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS}  ${HEADER}

${OBJ_PATH}%.o:	${SRC_PATH}%.c
	@mkdir -p $(dir $@)
	${CC} ${CFLAGS} ${HEADER} -c $< -o $@

clean:
	rm -rf ${OBJS}

fclean: clean
	rm -rf $(NAME)

re: fclean all
