# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/06 11:43:21 by mshpakov          #+#    #+#              #
#    Updated: 2019/12/08 22:58:47 by bdeomin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC       := clang++ 
FLAGS	 := -Wall -Wextra -Werror -std=c++98 -pedantic  
OBJ_DIR  := objs
SRC_DIR  := $(CURDIR)
NAME	 := ft_retro
INC 	 := -I $(CURDIR)
SRC      := main.cpp Character.class.cpp Player.class.cpp Enemy.class.cpp Bullet.class.cpp Level.class.cpp Thing.class.cpp Menu.cpp

OBJ      := $(SRC:.cpp=.o)

OBJ := $(addprefix $(OBJ_DIR)/, $(OBJ))
SRC := $(addprefix $(SRC_DIR)/, $(SRC))

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -lncurses -o  $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CC) $(FLAGS) -c $<  -o $@

clean:
	/bin/rm -rf $(OBJ)
	/bin/rm -rf $(OBJ_DIR)

fclean: clean
	/bin/rm -rf $(NAME)

re: fclean all
