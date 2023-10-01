CC = g++
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/main.o $(OBJ)/evaluate.o
HDRS = $(INC)/stack.h $(INC)/evaluate.h
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
#
#$(OBJ)/fibonacci.o: $(HDRS) $(SRC)/fibonacci.cpp
#	$(CC) $(CFLAGS) -o $(OBJ)/fibonacci.o $(SRC)/fibonacci.cpp

clean:
	rm -f $(EXE) $(OBJS) gmon.out