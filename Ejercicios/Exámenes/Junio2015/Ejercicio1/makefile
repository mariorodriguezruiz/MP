
SRC = src
INC = include
OBJ = obj
BIN = bin
LIB = lib
DOC = doc

CXX = g++
CPPFLAGS = -g -Wall -pedantic -ansi -std=c++11 -I$(INC)

all: $(BIN)/main

$(BIN)/main: $(OBJ)/main.o $(LIB)/libLista.a
	$(CXX) $(CPPFLAGS) -o $(BIN)/main $(OBJ)/main.o -L$(LIB)/ -lLista

$(LIB)/libLista.a: $(OBJ)/Lista.o
	ar rsv $(LIB)/libLista.a $(OBJ)/Lista.o

$(OBJ)/main.o: $(SRC)/main.cpp $(INC)/Lista.h
	$(CXX) $(CPPFLAGS) -c $(SRC)/main.cpp -o $(OBJ)/main.o -I$(INC)/

$(OBJ)/Lista.o: $(SRC)/Lista.cpp $(INC)/Lista.h
	$(CXX) $(CPPFLAGS) -c $(SRC)/Lista.cpp -o $(OBJ)/Lista.o -I$(INC)/

run:
	$(BIN)/main

valgrind:
	valgrind --leak-check=full --track-origins=yes $(BIN)/main

ddd:
	ddd $(BIN)/main
	
# ************ documentación *******

documentacion:
	doxygen $(DOC)/doxys/Doxyfile

# ************ Limpieza ************
clean:
	@echo "Limpiando..."
	rm $(OBJ)/*.o
	rm $(LIB)/*
	rm $(BIN)/*

borra:
	@echo "Borra imágenes y ficheros .txt que no sirven..."
	rm *ascii*.txt
	rm *.pgm

mrproper: clean borra

