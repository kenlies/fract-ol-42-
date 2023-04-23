# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aotsala <aotsala@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/17 22:27:48 by aotsala           #+#    #+#              #
#    Updated: 2023/04/18 00:26:57 by aotsala          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
OBJ = $(SRC:.c=.o)
LIB = libft/libft.a
LINK = -lmlx -framework OpenGL -framework AppKit

SRC = fractol.c helper.c hooks.c calc.c

CC = cc
CFLAGS = -Wall -Werror -Wextra -Ofast

COMP = $(CC) $(CFLAGS) $(LIB) $(LINK)

RM = rm -f

all:	$(NAME)

$(NAME):	$(OBJ)
						$(MAKE) -C ./libft
						$(COMP) $(OBJ) -o $(NAME)
bonus: all

clean:
		$(RM) $(OBJ)
		$(MAKE) fclean -C ./libft
		
fclean:	clean
		$(RM) $(NAME)
		$(MAKE) fclean -C ./libft

re:		fclean all