#ifndef LISTA_H
#define LISTA_H

#include<iostream>
#include<string.h>
#include<fstream>
#include<assert.h>

using namespace std ;

struct Celda{
    int dato ;
    Celda *siguiente ;
} ;

class Lista{
    private:
        Celda *contenido ;
        int longitud ;

        void liberarMemoria() ;

        void eliminaUltimaCelda() ;

        Celda *obtenerCelda(const int indice) const ;

        void insertarCelda(const int indice, Celda *nueva) ;

        void eliminaCelda(const int indice) ;

    public:
        Lista() ;

        ~Lista() ;

        void aniadirCelda(const int valor) ;

        int obtenerLongitud() const ;

        //  Función que recibe un entero y una lista y modifica dicha
        //  lista ordenada insertando el entero en la posición correspondiente

        void insertaCeldaOrdenada(const int entero) ;

        int obtenerDato(const int indice) const ;

        // Defina una función que recibe un entero y una lista y
        // modifica dicha lista eliminando la primera aparición de ese entero en la lista.
        void eliminaEnteroRepetido(const int entero) ;




    //.........
};

#endif /* LISTA_H */
