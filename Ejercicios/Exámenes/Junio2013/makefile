
SRC = src
INC = include
OBJ = obj
BIN = bin
LIB = lib
DOC = doc

CXX = g++
CPPFLAGS = -g -Wall -pedantic -ansi -std=c++11 -I$(INC)

all: $(BIN)/suma

$(BIN)/suma: $(OBJ)/suma.o $(LIB)/libBigInt.a
	$(CXX) $(CPPFLAGS) -o $(BIN)/suma $(OBJ)/suma.o -L$(LIB)/ -lBigInt

$(LIB)/libBigInt.a: $(OBJ)/BigInt.o $(OBJ)/utils.o
	ar rsv $(LIB)/libBigInt.a $(OBJ)/BigInt.o $(OBJ)/utils.o

$(OBJ)/suma.o: $(SRC)/suma.cpp $(INC)/BigInt.h
	$(CXX) $(CPPFLAGS) -c $(SRC)/suma.cpp -o $(OBJ)/suma.o -I$(INC)/

$(OBJ)/BigInt.o: $(SRC)/BigInt.cpp $(INC)/BigInt.h
	$(CXX) $(CPPFLAGS) -c $(SRC)/BigInt.cpp -o $(OBJ)/BigInt.o -I$(INC)/

$(OBJ)/utils.o: $(SRC)/utils.cpp $(INC)/BigInt.h
	$(CXX) $(CPPFLAGS) -c $(SRC)/utils.cpp -o $(OBJ)/utils.o -I$(INC)/

run:
	$(BIN)/suma

valgrind:
	valgrind --leak-check=full --track-origins=yes $(BIN)/suma datos.txt

ddd:
	ddd $(BIN)/suma
	
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

