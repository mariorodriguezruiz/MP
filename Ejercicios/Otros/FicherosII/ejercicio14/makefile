
SRC = src
INC = include
OBJ = obj
BIN = bin
LIB = lib
DOC = doc

CXX = g++
CPPFLAGS = -g -Wall -pedantic -ansi -std=c++11 -I$(INC)

all: $(BIN)/ejercicio14

$(BIN)/ejercicio14: $(OBJ)/ejercicio14.o
	$(CXX) $(CPPFLAGS) -o $(BIN)/ejercicio14 $(OBJ)/ejercicio14.o

$(OBJ)/ejercicio14.o: $(SRC)/ejercicio14.cpp
	$(CXX) $(CPPFLAGS) -c $(SRC)/ejercicio14.cpp -o $(OBJ)/ejercicio14.o

run:
	$(BIN)/ejercicio14

valgrind:
	valgrind --leak-check=full --track-origins=yes $(BIN)/ejercicio14

# ************ documentación *******

documentacion:
	doxygen $(DOC)/doxys/Doxyfile

# ************ Limpieza ************
clean:
	@echo "Limpiando..."
	rm $(OBJ)/*.o

borra:
	@echo "Borra imágenes y ficheros .txt que no sirven..."
	rm salida.txt

mrproper: clean borra
	rm $(BIN)/*
