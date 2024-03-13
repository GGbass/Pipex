# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gongarci <gongarci@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/12 20:20:21 by gongarci          #+#    #+#              #
#    Updated: 2024/03/12 21:52:00 by gongarci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
SRC = main.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	gcc -Wall -Werror -Wextra -L libft -lft $(OBJ) -o pipex

clean:
	@make fclean -C libft
	rm -f $(NAME)

fclean: clean
	rm -f $(OBJ)

re: fclean all
	rm -f $(NAME)

.PHONY: clean fclean re all 

# -C  aplica solo para ese directorio
# -L para las librerias