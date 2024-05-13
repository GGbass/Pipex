# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gongarci <gongarci@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/12 20:20:21 by gongarci          #+#    #+#              #
#    Updated: 2024/05/13 20:10:04 by gongarci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRC = 	ft_pipex_bonus.c \
		main_bonus.c \

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	print($(GREEN) done)
	#gcc -Wall -Werror -Wextra -L libft -lft $(OBJ) -o pipex
	gcc $(CFLAGS) $(OBJ) -L libft -lft -o pipex
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