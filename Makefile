CC = g++
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/main.o $(OBJ)/evaluate.o $(OBJ)/node.o $(OBJ)/binaryTree.o $(OBJ)/satisfiability.o
HDRS = $(INC)/stack.h $(INC)/evaluate.h $(INC)/node.h $(INC)/binaryTree.h $(INC)/satisfiability.h
CFLAGS = -Wall -g -c -I$(INC)

EXE = $(BIN)/main

.PHONY: all clean

run: all
	$(EXE)

all: $(EXE)

$(BIN)/main: $(OBJS)
	$(CC) -g -o $(BIN)/main $(OBJS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp

$(OBJ)/evaluate.o: $(HDRS) $(SRC)/evaluate.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/evaluate.o $(SRC)/evaluate.cpp

$(OBJ)/node.o: $(HDRS) $(SRC)/node.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/node.o $(SRC)/node.cpp

$(OBJ)/binaryTree.o: $(HDRS) $(SRC)/binaryTree.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/binaryTree.o $(SRC)/binaryTree.cpp

$(OBJ)/satisfiability.o: $(HDRS) $(SRC)/satisfiability.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/satisfiability.o $(SRC)/satisfiability.cpp

clean:
	rm -f $(EXE) $(OBJS) gmon.out