
SRC = src
INC = include
OBJ = obj
BIN = bin
LIB = lib
DOC = doc

CXX = g++
CPPFLAGS = -g -Wall -pedantic -ansi -std=c++11 -I$(INC)

all: $(BIN)/ejercicio3

$(BIN)/ejercicio3: $(OBJ)/ejercicio3.o
	$(CXX) $(CPPFLAGS) -o $(BIN)/ejercicio3 $(OBJ)/ejercicio3.o

$(OBJ)/ejercicio3.o: $(SRC)/ejercicio3.cpp
	$(CXX) $(CPPFLAGS) -c $(SRC)/ejercicio3.cpp -o $(OBJ)/ejercicio3.o

run:
	$(BIN)/ejercicio3

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
