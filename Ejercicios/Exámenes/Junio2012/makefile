
SRC = src
INC = include
OBJ = obj
BIN = bin
LIB = lib
DOC = doc

CXX = g++
CPPFLAGS = -g -Wall -pedantic -ansi -std=c++11 -I$(INC)

all: $(BIN)/main

$(BIN)/main: $(OBJ)/main.o $(LIB)/libPolilinea.a
	$(CXX) $(CPPFLAGS) -o $(BIN)/main $(OBJ)/main.o -L$(LIB)/ -lPolilinea

$(LIB)/libPolilinea.a: $(OBJ)/Polilinea.o $(OBJ)/utils.o
	ar rsv $(LIB)/libPolilinea.a $(OBJ)/Polilinea.o $(OBJ)/utils.o

$(OBJ)/main.o: $(SRC)/main.cpp $(INC)/Polilinea.h
	$(CXX) $(CPPFLAGS) -c $(SRC)/main.cpp -o $(OBJ)/main.o -I$(INC)/

$(OBJ)/Polilinea.o: $(SRC)/Polilinea.cpp $(INC)/Polilinea.h $(INC)/Punto.h
	$(CXX) $(CPPFLAGS) -c $(SRC)/Polilinea.cpp -o $(OBJ)/Polilinea.o -I$(INC)/

$(OBJ)/utils.o: $(SRC)/utils.cpp $(INC)/Polilinea.h
	$(CXX) $(CPPFLAGS) -c $(SRC)/utils.cpp -o $(OBJ)/utils.o -I$(INC)/

run:
	$(BIN)/main

valgrind:
	valgrind --leak-check=full --track-origins=yes $(BIN)/main datos.txt

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

