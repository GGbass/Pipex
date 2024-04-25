# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gongarci <gongarci@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/12 20:20:21 by gongarci          #+#    #+#              #
#    Updated: 2024/04/25 18:46:49 by gongarci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRC = 	main.c \
		path.c \
		ft_error.c \
		ft_pipex.c \


OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	#gcc -Wall -Werror -Wextra -L libft -lft $(OBJ) -o pipex
	gcc -Wall	-Werror -Wextra $(OBJ) -L libft -lft -o pipex
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