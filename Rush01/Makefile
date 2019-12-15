# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/15 17:14:33 by bdeomin           #+#    #+#              #
#    Updated: 2019/12/15 19:08:23 by bdeomin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR	=		./src/
OBJ_DIR	=		./obj/

NAME	=		ft_gkrellm
SRC		=		main.cpp Part1.cpp mlx.cpp

O_FILES	=		$(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))
FLAGS	=		-Wall -Wextra -Werror -std=c++98
CXX		=		clang++

MINILIBX_DIR	= /usr/local/lib
MINILIBX_INC_DIR= /usr/local/include
MINILIBX_FLAGS	= -L $(MINILIBX_DIR) -lmlx -framework OpenGL -framework APPKit

NCURSES_FLAGS	= -lncurses

LINK_FLAGS		= $(NCURSES_FLAGS) $(MINILIBX_FLAGS)

.PHONY: all clean
.NOTPARALLEL: all $(NAME) clean fclean re

all:			$(NAME)

$(NAME):		$(O_FILES)
				@echo "\033[36mLinking...\033[0m"
				$(CXX) $(O_FILES) $(LINK_FLAGS)  -o $(NAME)
				@echo "\033[32m[ ✔ ] Binary \033[1;32m$(NAME)\033[1;0m\033[32m created.\033[0m"

$(O_FILES):		| $(OBJ_DIR)

$(OBJ_DIR):
				mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o:	$(SRC_DIR)%.cpp
				$(CXX) -c $< -o $@ $(FLAGS) -I $(MINILIBX_INC_DIR)
				@echo "\033[37mCompilation of \033[97m$(notdir $<) \033[0m\033[37mdone. \033[0m"

clean:
				rm -rf $(OBJ_DIR)
				@echo "\033[31m[ ✔ ] Objects files \033[91m$(O_FILES) \033[0m\033[31m removed. \033[0m"

fclean:			clean
				rm -rf $(NAME)
				@echo "\033[31m[ ✔ ] Binary \033[1;31m$(NAME) \033[1;0m\033[31mremoved.\033[0m"

re:				fclean all
