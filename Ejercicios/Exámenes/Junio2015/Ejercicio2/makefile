
SRC = src
INC = include
OBJ = obj
BIN = bin
LIB = lib
DOC = doc

CXX = g++
CPPFLAGS = -g -Wall -pedantic -ansi -std=c++11 -I$(INC)

all: $(BIN)/main

$(BIN)/main: $(OBJ)/main.o $(LIB)/libFrecuencias.a
	$(CXX) $(CPPFLAGS) -o $(BIN)/main $(OBJ)/main.o -L$(LIB)/ -lFrecuencias

$(LIB)/libFrecuencias.a: $(OBJ)/Frecuencias.o $(OBJ)/utils.o
	ar rsv $(LIB)/libFrecuencias.a $(OBJ)/Frecuencias.o $(OBJ)/utils.o

$(OBJ)/main.o: $(SRC)/main.cpp $(INC)/Frecuencias.h
	$(CXX) $(CPPFLAGS) -c $(SRC)/main.cpp -o $(OBJ)/main.o -I$(INC)/

$(OBJ)/Frecuencias.o: $(SRC)/Frecuencias.cpp $(INC)/Frecuencias.h
	$(CXX) $(CPPFLAGS) -c $(SRC)/Frecuencias.cpp -o $(OBJ)/Frecuencias.o -I$(INC)/

$(OBJ)/utils.o: $(SRC)/utils.cpp $(INC)/Frecuencias.h
	$(CXX) $(CPPFLAGS) -c $(SRC)/utils.cpp -o $(OBJ)/utils.o -I$(INC)/

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

