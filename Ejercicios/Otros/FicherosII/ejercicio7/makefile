
SRC = src
INC = include
OBJ = obj
BIN = bin
LIB = lib
DOC = doc

CXX = g++
CPPFLAGS = -g -Wall -pedantic -ansi -std=c++11 -I$(INC)

all: $(BIN)/ejercicio7

$(BIN)/ejercicio7: $(OBJ)/ejercicio7.o
	$(CXX) $(CPPFLAGS) -o $(BIN)/ejercicio7 $(OBJ)/ejercicio7.o

$(OBJ)/ejercicio7.o: $(SRC)/ejercicio7.cpp
	$(CXX) $(CPPFLAGS) -c $(SRC)/ejercicio7.cpp -o $(OBJ)/ejercicio7.o

run:
	$(BIN)/ejercicio7

valgrind:
	valgrind --leak-check=full --track-origins=yes $(BIN)/ejercicio7

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
