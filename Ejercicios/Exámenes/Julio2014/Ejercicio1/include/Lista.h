#ifndef LISTA_H
#define LISTA_H

#include<iostream>
#include<string.h>
#include<assert.h>
#include<fstream>

using namespace std ;

class Celda{
    private:
        Celda *siguiente ;
        int dato ;

    public:
        Celda(){
            siguiente = 0 ;
            dato = 0 ;
        }

        Celda(int valor){
            siguiente = 0 ;
            dato = valor ;
        }

        inline Celda * getSiguiente()const{
            return siguiente ;
        }

        inline int getDato(const int indice) const{
            return dato ;
        }

        inline void setSiguiente(Celda *nueva){
            siguiente = nueva ;
        }

        inline void setDato(const int valor){
            dato = valor ;
        }
};


class Lista{
    private:
        Celda *contenido ;
        int longitud ;

    public:

        Lista() ;

        void aniadirCelda(const int valor) ;

        inline Celda *getContenido()const {
            return contenido ;
        }

        inline void setContenido(Celda * nueva){
            contenido = nueva ;
        }

        inline int getLongitud()const {
            return longitud ;
        }

        inline void setLongitud(const int valor){
            longitud = valor ;
        }

        Celda * obtenerCelda(const int indice) ;

        friend Lista * devuelveVectorListas(Lista &una, const int t) ;
};

#endif /* LISTA_H */
