: **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nlorion <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/20 17:30:21 by nlorion           #+#    #+#              #
#    Updated: 2022/05/27 17:17:25 by nlorion          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

SRC	= get_next_line.c \
		get_next_line_utils.c \
		get_next_line_bonus.c \
		get_next_line_utils_bonus.c \

OBJ	= $(SRC:.c=.o)

COMPILER_COMMAND	= clang

RM	= rm -f

CFLAGS	= -Wall -Werror -Wextra

.c.o	= $(COMPILER_COMMAND) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

all:	$(NAME)

clean:	
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY : all clean fclean re
