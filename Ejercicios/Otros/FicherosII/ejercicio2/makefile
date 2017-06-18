
SRC = src
INC = include
OBJ = obj
BIN = bin
LIB = lib
DOC = doc

CXX = g++
CPPFLAGS = -g -Wall -pedantic -ansi -std=c++11 -I$(INC)

all: $(BIN)/ejercicio2

$(BIN)/ejercicio2: $(OBJ)/ejercicio2.o
	$(CXX) $(CPPFLAGS) -o $(BIN)/ejercicio2 $(OBJ)/ejercicio2.o

$(OBJ)/ejercicio2.o: $(SRC)/ejercicio2.cpp
	$(CXX) $(CPPFLAGS) -c $(SRC)/ejercicio2.cpp -o $(OBJ)/ejercicio2.o

run:
	$(BIN)/ejercicio2

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
