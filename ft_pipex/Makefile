# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gongarci <gongarci@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/12 20:20:21 by gongarci          #+#    #+#              #
#    Updated: 2024/06/25 22:55:02 by gongarci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
NAMEB = bonus

SRC = 	./src/ft_pipex.c \
		./src/main.c \

SRCB =	./srcb/ft_pipex_bonus.c \
		./srcb/get_path.c \
		./srcb/ft_error.c \
		./srcb/here_doc.c \
		./srcb/main_bonus.c \
		
OBJ = $(SRC:.c=.o)
OBJB = $(SRCB:.c=.o)

CFLAGS = -Wall -Werror -Wextra -no-pie -g3 -fsanitize=address,leak
#valgrind --track-fds=yes
#-g3 -fsanitize=address,leak
# valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes --trace-children=yes -s -q 
CC =  gcc

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	$(CC) $(CFLAGS) $(OBJ) -L libft -lft -o pipex
	
bonus: 
$(NAMEB): $(OBJB)
	@make -C libft
	$(CC) $(CFLAGS) $(OBJB) -L libft -lft -o pipex_bonus
	
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