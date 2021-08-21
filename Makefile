# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: klever <klever@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/13 13:36:25 by klever            #+#    #+#              #
#    Updated: 2021/08/21 04:48:36 by klever           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= pipex.a
SRC= ./srcs/search_path.c ./srcs/utils.c ./pipex.c ./srcs/ft_split.c ./srcs/ft_strchr.c ./srcs/ft_strlen.c \
	./srcs/ft_strlcpy.c ./srcs/ft_putstr_fd.c ./srcs/ft_putendl_fd.c ./srcs/ft_putchar_fd.c ./srcs/ft_strlcat.c ./srcs/ft_strjoin.c ./srcs/ft_strncmp.c
FLAGS= gcc -Wextra -Werror -Wall
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)

$(NAME):	$(OBJ)
	@clear
	@echo "\n\033[36m"****************\\nCompiled...\\n****************\\n"\033[0m\n"
	@ar -rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@clear
	@echo "\n\033[36m"****************\\nStart...\\n****************\\n"\033[0m\n"
	@$(FLAGS) $(SRC) -o pipex

all: $(NAME)

clean:
	@clear
	@echo "\n\033[36m"****************\\nDeleted files...\\n****************\\n"\033[0m\n"
	@rm -f $(OBJ)

fclean: clean
		@rm -rf $(NAME)
		@rm -rf pipex

re: fclean all

.PHONY: all clean re run