# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlana <dlana@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/29 20:20:15 by dlana             #+#    #+#              #
#    Updated: 2021/10/02 14:12:24 by dlana            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap

NAME_BONUS	=	checker

CC			=	gcc
RM			=	rm -f 

CFLAGS		=	-Wall -Wextra -Werror

SRCS		=	push_swap.c \
				ft_parser.c ft_error.c ft_create_a.c \
				ft_swap_a.c ft_swap_b.c ft_swap_a_and_b.c \
				ft_push_a.c ft_push_b.c \
				ft_rotate_a.c ft_rotate_b.c ft_rotate_a_and_b.c \
				ft_reverse_rotate_a.c ft_reverse_rotate_b.c ft_reverse_rotate_a_and_b.c \
				ft_cut_list.c ft_paste_list.c \
				ft_sort_array.c ft_sort_short_list.c ft_sort_long_list.c \

SRCS_BONUS	=	checker.c \
				ft_parser.c ft_error.c ft_create_a.c \
				ft_swap_a.c ft_swap_b.c ft_swap_a_and_b.c \
				ft_push_a.c ft_push_b.c \
				ft_rotate_a.c ft_rotate_b.c ft_rotate_a_and_b.c \
				ft_reverse_rotate_a.c ft_reverse_rotate_b.c ft_reverse_rotate_a_and_b.c \
				ft_cut_list.c ft_paste_list.c \
				ft_read_and_make_instructions.c ft_make_instructions.c \
				ft_sort_array_to_check.c \
				ft_check_instructions.c \

OBJS_BONUS	=	${SRCS_BONUS:.c=.o}

OBJS		=	${SRCS:.c=.o}

.c.o:		=
				${CC} ${CFLAGS} -c $< -o $@

${NAME}:		Makefile push_swap.h ${OBJS}
			${CC} ${CFLAGS} ${OBJS} -o ${NAME} 

${NAME_BONUS}:	Makefile checker.h ${OBJS_BONUS}
			${CC} ${CFLAGS} ${OBJS_BONUS} -o ${NAME_BONUS} 

all:			${NAME}
	
bonus:			${NAME_BONUS}

clean:	
				${RM} ${OBJS} ${OBJS_BONUS}
			
fclean:			clean
				${RM} ${NAME} ${NAME_BONUS}

re:				fclean all

rebonus: 		fclean bonus

.PHONY: 		all clean fclean re bonus rebonus