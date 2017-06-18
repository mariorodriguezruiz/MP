BIN = bin
SRC = src
LIB = lib
OBJ = obj
CXX = c++
CXXFLAGS = -g -O2 -Wall

$(BIN)/central : $(OBJ)/central.o $(LIB)/libformas.a
	$(CXX) $(CXXFLAGS) -o $(BIN)/central $(OBJ)/central.o -L$(LIB)/ -lformas

$(LIB)/libformas.a: $(OBJ)/punto.o $(OBJ)/circulo.o
	ar rsv $(LIB)/libformas.a $(OBJ)/punto.o $(OBJ)/circulo.o

$(OBJ)/central.o: $(SRC)/central.cpp include/circulo.h include/punto.h
	$(CXX) $(CXXFLAGS) -c $(SRC)/central.cpp -o $(OBJ)/central.o -Iinclude/

$(OBJ)/punto.o: $(SRC)/punto.cpp include/punto.h
	$(CXX) $(CXXFLAGS) -c $(SRC)/punto.cpp -o $(OBJ)/punto.o -Iinclude/
	
$(OBJ)/circulo.o: $(SRC)/circulo.cpp include/circulo.h include/punto.h
	$(CXX) $(CXXFLAGS) -c $(SRC)/circulo.cpp -o $(OBJ)/circulo.o -Iinclude/
	
run:
	bin/central

clean:
	@echo "Limpiando..." 
	rm $(OBJ)/*.o $(LIB)/$(LIB)*.a

mrproper: clean
	rm $(BIN)/central $(BIN)/main2

	
