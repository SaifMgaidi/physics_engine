NAME = engine

SRC_DIR = ./src
INC_DIR = ./inc
OBJ_DIR = ./obj


CC = c++
CFLAGS = -std=c++98 -Wall -Wextra -Werror -I$(INC_DIR)
LFLAGS = -lX11

RM = rm -rf


SRC =	$(SRC_DIR)/main.cpp \
		$(SRC_DIR)/MyWindow.cpp \
		$(SRC_DIR)/Vector2D.cpp \
		$(SRC_DIR)/Shape.cpp

OBJ =	$(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)


all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LFLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re