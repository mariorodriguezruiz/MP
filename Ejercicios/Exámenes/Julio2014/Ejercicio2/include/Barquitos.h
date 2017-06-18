#ifndef LISTA_H
#define LISTA_H

#include<iostream>
#include<string.h>
#include<assert.h>
#include<fstream>
#include<stdlib.h>

using namespace std ;

class Barquitos{
    private:
        const static int agua = 9 ;
        int **datos ;
        int nfil, ncol ;

        void liberarMemoria() ;

        void reservarMemoria(const int filas, const int columnas) ;

        void copiarDatos(const Barquitos &otra) ;

        bool compruebaBordesDeCasilla(const int fila, const int columna) ;

        int Aleatorio(const int min, const int max) ;
    public:
        Barquitos() ;

        Barquitos(const int filas, const int columnas) ;

        ~Barquitos() ;

        const Barquitos & operator = (const Barquitos &otro) ;

        /*
         * El barco se puede poner si las casillas no están ocupadas y
         * no hay ningún barco con el que “se toque”.
         */
        bool esPosibleColocarBarco(const char fila, const int columna, const int tamBarco, const char dibujo) ;


        void insertarBarco(const int tamBarco) ;

        bool Leer(const char *nombre) ;


};

#endif /* LISTA_H */
