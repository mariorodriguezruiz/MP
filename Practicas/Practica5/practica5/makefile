
SRC = src
INC = include
OBJ = obj
BIN = bin
LIB = lib
DOC = doc

CXX = g++
CPPFLAGS = -g -Wall -pedantic -ansi -std=c++11 -I$(INC)

all: $(BIN)/arteASCII $(BIN)/arteASCII2 $(BIN)/testplano $(BIN)/testimagen $(BIN)/testimagen $(BIN)/testarteASCII

$(BIN)/arteASCII2: $(OBJ)/arteASCII2.o $(LIB)/libimagen.a
	$(CXX) $(CPPFLAGS) -o $(BIN)/arteASCII2 $(OBJ)/arteASCII2.o -L$(LIB)/ -limagen

$(BIN)/arteASCII: $(OBJ)/arteASCII.o $(LIB)/libimagen.a
	$(CXX) $(CPPFLAGS) -o $(BIN)/arteASCII $(OBJ)/arteASCII.o -L$(LIB)/ -limagen

$(BIN)/testimagen: $(OBJ)/testimagen.o $(LIB)/libimagen.a
	$(CXX) $(CPPFLAGS) -o $(BIN)/testimagen $(OBJ)/testimagen.o -L$(LIB)/ -limagen

$(BIN)/testarteASCII: $(OBJ)/testarteASCII.o $(LIB)/libimagen.a
	$(CXX) $(CPPFLAGS) -o $(BIN)/testarteASCII $(OBJ)/testarteASCII.o -L$(LIB)/ -limagen

$(BIN)/testplano: $(OBJ)/testplano.o $(LIB)/libimagen.a
	$(CXX) $(CPPFLAGS) -o $(BIN)/testplano $(OBJ)/testplano.o -L$(LIB)/ -limagen

$(LIB)/libimagen.a: $(OBJ)/imagen.o $(OBJ)/pgm.o $(OBJ)/byte.o $(OBJ)/lista.o
	ar rsv $(LIB)/libimagen.a $(OBJ)/imagen.o $(OBJ)/pgm.o $(OBJ)/byte.o $(OBJ)/lista.o

$(OBJ)/testimagen.o: $(SRC)/testimagen.cpp $(INC)/imagen.h
	$(CXX) $(CPPFLAGS) -c $(SRC)/testimagen.cpp -o $(OBJ)/testimagen.o -I$(INC)/

$(OBJ)/testarteASCII.o: $(SRC)/testarteASCII.cpp $(INC)/imagen.h
	$(CXX) $(CPPFLAGS) -c $(SRC)/testarteASCII.cpp -o $(OBJ)/testarteASCII.o -I$(INC)/

$(OBJ)/arteASCII2.o: $(SRC)/arteASCII2.cpp $(INC)/imagen.h $(INC)/lista.h
	$(CXX) $(CPPFLAGS) -c $(SRC)/arteASCII2.cpp -o $(OBJ)/arteASCII2.o -I$(INC)/

$(OBJ)/arteASCII.o: $(SRC)/arteASCII.cpp $(INC)/imagen.h
	$(CXX) $(CPPFLAGS) -c $(SRC)/arteASCII.cpp -o $(OBJ)/arteASCII.o -I$(INC)/

$(OBJ)/testplano.o: $(SRC)/testplano.cpp $(INC)/imagen.h
	$(CXX) $(CPPFLAGS) -c $(SRC)/testplano.cpp -o $(OBJ)/testplano.o -I$(INC)/

$(OBJ)/imagen.o: $(SRC)/imagen.cpp $(INC)/imagen.h $(INC)/byte.h $(INC)/lista.h
	$(CXX) $(CPPFLAGS) -c $(SRC)/imagen.cpp -o $(OBJ)/imagen.o -I$(INC)/

$(OBJ)/lista.o: $(SRC)/lista.cpp $(INC)/lista.h
	$(CXX) $(CPPFLAGS) -c $(SRC)/lista.cpp -o $(OBJ)/lista.o -I$(INC)/

$(OBJ)/pgm.o: $(SRC)/pgm.cpp $(INC)/pgm.h
	$(CXX) $(CPPFLAGS) -c $(SRC)/pgm.cpp -o $(OBJ)/pgm.o -I$(INC)/

$(OBJ)/byte.o: $(SRC)/byte.cpp $(INC)/byte.h
	$(CXX) $(CPPFLAGS) -c $(SRC)/byte.cpp -o $(OBJ)/byte.o -I$(INC)/

run:
	$(BIN)/testimagen
	#$(BIN)/testplano
	$(BIN)/testarteASCII
	#$(BIN)/arteASCII
	$(BIN)/arteASCII2

	
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
