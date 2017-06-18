
SRC = src
INC = include
OBJ = obj
BIN = bin
LIB = lib
DOC = doc

CXX = g++
CPPFLAGS = -g -Wall -pedantic -ansi -std=c++11 -I$(INC)

all: $(BIN)/main

$(BIN)/main: $(OBJ)/main.o $(LIB)/libMatrizBS.a
	$(CXX) $(CPPFLAGS) -o $(BIN)/main $(OBJ)/main.o -L$(LIB)/ -lMatrizBS

$(LIB)/libMatrizBS.a: $(OBJ)/MatrizBS.o
	ar rsv $(LIB)/libMatrizBS.a $(OBJ)/MatrizBS.o

$(OBJ)/main.o: $(SRC)/main.cpp $(INC)/MatrizBS.h
	$(CXX) $(CPPFLAGS) -c $(SRC)/main.cpp -o $(OBJ)/main.o -I$(INC)/

$(OBJ)/MatrizBS.o: $(SRC)/MatrizBS.cpp $(INC)/MatrizBS.h
	$(CXX) $(CPPFLAGS) -c $(SRC)/MatrizBS.cpp -o $(OBJ)/MatrizBS.o -I$(INC)/

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

