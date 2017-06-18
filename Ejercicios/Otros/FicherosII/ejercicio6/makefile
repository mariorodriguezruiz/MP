
SRC = src
INC = include
OBJ = obj
BIN = bin
LIB = lib
DOC = doc

CXX = g++
CPPFLAGS = -g -Wall -pedantic -ansi -std=c++11 -I$(INC)

all: $(BIN)/ejercicio6

$(BIN)/ejercicio6: $(OBJ)/ejercicio6.o
	$(CXX) $(CPPFLAGS) -o $(BIN)/ejercicio6 $(OBJ)/ejercicio6.o

$(OBJ)/ejercicio6.o: $(SRC)/ejercicio6.cpp
	$(CXX) $(CPPFLAGS) -c $(SRC)/ejercicio6.cpp -o $(OBJ)/ejercicio6.o

run:
	$(BIN)/ejercicio6

valgrind:
	valgrind --leak-check=full --track-origins=yes $(BIN)/ejercicio6

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
