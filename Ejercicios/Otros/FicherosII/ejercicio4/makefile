
SRC = src
INC = include
OBJ = obj
BIN = bin
LIB = lib
DOC = doc

CXX = g++
CPPFLAGS = -g -Wall -pedantic -ansi -std=c++11 -I$(INC)

all: $(BIN)/ejercicio4

$(BIN)/ejercicio4: $(OBJ)/ejercicio4.o
	$(CXX) $(CPPFLAGS) -o $(BIN)/ejercicio4 $(OBJ)/ejercicio4.o

$(OBJ)/ejercicio4.o: $(SRC)/ejercicio4.cpp
	$(CXX) $(CPPFLAGS) -c $(SRC)/ejercicio4.cpp -o $(OBJ)/ejercicio4.o

run:
	$(BIN)/ejercicio4

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
