OBJ = src/Game.cpp src/GameManager.cpp src/Board.cpp src/Food.cpp src/Snake.cpp

CC = g++

COMPILER_FLAGS = -w -Wall

LINKER_FLAGS = -lncurses

OUT_FILE = snake

all : $(OBJ)
	$(CC) $(OBJ) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OUT_FILE)