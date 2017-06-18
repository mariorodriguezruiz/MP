
SRC = src
INC = include
OBJ = obj
BIN = bin
LIB = lib
DOC = doc

CXX = g++
CPPFLAGS = -g -Wall -std=c++11 -I$(INC)

all: $(BIN)/arteASCII $(BIN)/testplano $(BIN)/testimagen $(BIN)/testimagen $(BIN)/testarteASCII

$(BIN)/arteASCII: $(OBJ)/arteASCII.o $(LIB)/libimagen.a
	$(CXX) $(CPPFLAGS) -o $(BIN)/arteASCII $(OBJ)/arteASCII.o -L$(LIB)/ -limagen

$(BIN)/testimagen: $(OBJ)/testimagen.o $(LIB)/libimagen.a
	$(CXX) $(CPPFLAGS) -o $(BIN)/testimagen $(OBJ)/testimagen.o -L$(LIB)/ -limagen

$(BIN)/testarteASCII: $(OBJ)/testarteASCII.o $(LIB)/libimagen.a
	$(CXX) $(CPPFLAGS) -o $(BIN)/testarteASCII $(OBJ)/testarteASCII.o -L$(LIB)/ -limagen

$(BIN)/testplano: $(OBJ)/testplano.o $(LIB)/libimagen.a
	$(CXX) $(CPPFLAGS) -o $(BIN)/testplano $(OBJ)/testplano.o -L$(LIB)/ -limagen

$(LIB)/libimagen.a: $(OBJ)/imagen.o $(OBJ)/pgm.o $(OBJ)/byte.o
	ar rsv $(LIB)/libimagen.a $(OBJ)/imagen.o $(OBJ)/pgm.o $(OBJ)/byte.o

$(OBJ)/testimagen.o: $(SRC)/testimagen.cpp include/imagen.h
	$(CXX) $(CPPFLAGS) -c $(SRC)/testimagen.cpp -o $(OBJ)/testimagen.o -Iinclude/

$(OBJ)/testarteASCII.o: $(SRC)/testarteASCII.cpp include/imagen.h
	$(CXX) $(CPPFLAGS) -c $(SRC)/testarteASCII.cpp -o $(OBJ)/testarteASCII.o -Iinclude/

$(OBJ)/arteASCII.o: $(SRC)/arteASCII.cpp include/imagen.h
	$(CXX) $(CPPFLAGS) -c $(SRC)/arteASCII.cpp -o $(OBJ)/arteASCII.o -Iinclude/

$(OBJ)/testplano.o: $(SRC)/testplano.cpp include/imagen.h
	$(CXX) $(CPPFLAGS) -c $(SRC)/testplano.cpp -o $(OBJ)/testplano.o -Iinclude/

$(OBJ)/imagen.o: $(SRC)/imagen.cpp include/imagen.h include/byte.h
	$(CXX) $(CPPFLAGS) -c $(SRC)/imagen.cpp -o $(OBJ)/imagen.o -Iinclude/

$(OBJ)/pgm.o: $(SRC)/pgm.cpp include/pgm.h
	$(CXX) $(CPPFLAGS) -c $(SRC)/pgm.cpp -o $(OBJ)/pgm.o -Iinclude/

$(OBJ)/byte.o: $(SRC)/byte.cpp include/byte.h
	$(CXX) $(CPPFLAGS) -c $(SRC)/byte.cpp -o $(OBJ)/byte.o -Iinclude/

run:
	$(BIN)/testimagen
	$(BIN)/testplano
	#$(BIN)/testarteASCII > gio.txt
	$(BIN)/arteASCII

	
# ************ documentación *******

documentacion:
	doxygen $(DOC)/doxys/Doxyfile

# ************ Limpieza ************
clean:
	@echo "Limpiando..."
	rm $(OBJ)/*.o
	rm *.pgm
	@echo "Borra ficheros .txt que no sirven..."
	rm *ascii*.txt

mrproper: clean
	rm $(BIN)/*
