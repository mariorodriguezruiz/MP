BIN = bin
SRC = src
LIB = lib
OBJ = obj
DOC = doc
CXX = c++
CXXFLAGS = -g -O2 -Wall -std=c++11

$(BIN)/main : $(OBJ)/main.o $(OBJ)/bloqueLed.o
	$(CXX) $(CXXFLAGS) -o $(BIN)/main $(OBJ)/main.o $(OBJ)/bloqueLed.o

$(OBJ)/main.o: $(SRC)/main.cpp include/bloqueLed.h
	$(CXX) $(CXXFLAGS) -c $(SRC)/main.cpp -o $(OBJ)/main.o -Iinclude/

$(OBJ)/bloqueLed.o: $(SRC)/bloqueLed.cpp include/bloqueLed.h
	$(CXX) $(CXXFLAGS) -c $(SRC)/bloqueLed.cpp -o $(OBJ)/bloqueLed.o -Iinclude/

run:
	bin/main

clean:
	@echo "Limpiando..." 
	rm $(OBJ)/*.o

mrproper: clean
	rm $(BIN)/main

documentacion:
	doxygen $(DOC)/doxys/Doxyfile
