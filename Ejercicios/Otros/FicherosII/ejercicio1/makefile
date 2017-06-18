
SRC = src
INC = include
OBJ = obj
BIN = bin
LIB = lib
DOC = doc

CXX = g++
CPPFLAGS = -g -Wall -pedantic -ansi -std=c++11 -I$(INC)

all: $(BIN)/ejercicio1

$(BIN)/ejercicio1: $(OBJ)/ejercicio1.o
	$(CXX) $(CPPFLAGS) -o $(BIN)/ejercicio1 $(OBJ)/ejercicio1.o

$(OBJ)/ejercicio1.o: $(SRC)/ejercicio1.cpp
	$(CXX) $(CPPFLAGS) -c $(SRC)/ejercicio1.cpp -o $(OBJ)/ejercicio1.o

run:
	$(BIN)/ejercicio1

# ************ documentación *******

documentacion:
	doxygen $(DOC)/doxys/Doxyfile

# ************ Limpieza ************
clean:
	@echo "Limpiando..."
	rm $(OBJ)/*.o

borra:
	@echo "Borra imágenes y ficheros .txt que no sirven..."
	rm *ascii*.txt
	rm *.pgm

mrproper: clean borra
	rm $(BIN)/*
