#ifndef LISTA_H
#define LISTA_H

#include<iostream>
#include<string.h>
#include<assert.h>
#include<fstream>
#include<stdlib.h>

using namespace std ;

class Celda{
    private:
        double dato ;
        Celda *siguiente ;
    public:
        Celda(){
            dato = 0 ;
            siguiente = 0 ;
        }

        Celda(const double valor){
            dato = valor ;
            siguiente = 0 ;
        }

        inline double obtenerDato()const {
            return dato ;
        }

        inline Celda * obtenerSiguiente(){
            return siguiente ;
        }

        inline void setSiguiente(Celda *nueva){
            siguiente = nueva ;
        }

        inline void setDato(const double valor){
            dato = valor ;
        }
};

class Lista{
    private:
        Celda *contenido  ;
        int longitud ;

        void liberarMemoria() ;

        void eliminaUltimaCelda() ;

        void copiarDatos(const Lista &otra) ;

        Celda * reservarCeldas(const int tamanio) ;

    public:

        Lista() ;

        Lista(const Lista &otra) ;

        ~Lista() ;

        inline int obtenerLongitud()const {
            return longitud ;
        }

        const Lista & operator = (const Lista &otra) ;

        void aniadirCelda(const double valor) ;

        Celda *obtenerCelda(const int indice) const;

        friend void imprimeLista(Lista &una);

};



#endif /* LISTA_H */
