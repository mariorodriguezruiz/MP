
SRC = src
INC = include
OBJ = obj
BIN = bin
LIB = lib
DOC = doc

CXX = g++
CPPFLAGS = -g -Wall -pedantic -ansi -std=c++11 -I$(INC)

all: $(BIN)/ejercicio23

$(BIN)/ejercicio23: $(OBJ)/ejercicio23.o $(LIB)/libimagen.a
	$(CXX) $(CPPFLAGS) -o $(BIN)/ejercicio23 $(OBJ)/ejercicio23.o -L$(LIB)/ -limagen

$(LIB)/libimagen.a: $(OBJ)/lista.o $(OBJ)/celda.o
	ar rsv $(LIB)/libimagen.a $(OBJ)/lista.o $(OBJ)/celda.o

$(OBJ)/ejercicio23.o: $(SRC)/ejercicio23.cpp $(INC)/lista.h
	$(CXX) $(CPPFLAGS) -c $(SRC)/ejercicio23.cpp -o $(OBJ)/ejercicio23.o -I$(INC)/

$(OBJ)/lista.o: $(SRC)/lista.cpp $(INC)/lista.h $(INC)/celda.h
	$(CXX) $(CPPFLAGS) -c $(SRC)/lista.cpp -o $(OBJ)/lista.o -I$(INC)/

$(OBJ)/celda.o: $(SRC)/celda.cpp $(INC)/celda.h
	$(CXX) $(CPPFLAGS) -c $(SRC)/celda.cpp -o $(OBJ)/celda.o -I$(INC)/

run:
	$(BIN)/ejercicio23

valgrind:
	valgrind --leak-check=full --track-origins=yes $(BIN)/ejercicio23

ddd:
	ddd $(BIN)/ejercicio23
	
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

