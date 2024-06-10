# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/12 20:20:21 by gongarci          #+#    #+#              #
#    Updated: 2024/06/09 21:43:14 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
NAMEB = bonus

SRC = 	ft_pipex.c \
		main.c \

SRCB =	ft_pipex_bonus.c \
		get_path.c \
		ft_error.c \
		main_bonus.c \
		here_doc.c \
		
OBJ = $(SRC:.c=.o)
OBJB = $(SRCB:.c=.o)

CFLAGS = -Wall -Werror -Wextra
CC = gcc

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	$(CC) $(CFLAGS) $(OBJ) -L libft -lft -o pipex
	
bonus: 
$(NAMEB): $(OBJB)
	@make -C libft
	$(CC) $(CFLAGS) $(OBJB) -L libft -lft -o bonus
	
clean:
		rm -f $(NAME)
		rm -f $(NAMEB)
		@make fclean -C libft
	
fclean: clean
	rm -f $(OBJ)
	rm -f $(OBJB)
	@make clean -C libft

re: fclean all
	rm -f $(NAME)

re_bonus: fclean bonus
	rm -f $(NAMEB)

.PHONY: clean fclean re all 

# -C  aplica solo para ese directorio
# -L para las librerias