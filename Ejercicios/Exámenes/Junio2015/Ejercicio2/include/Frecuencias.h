#ifndef FRECUENCIAS_H
#define FRECUENCIAS_H

#include<iostream>
#include<string.h>
#include<assert.h>
#include<fstream>
#include<stdlib.h>

using namespace std ;

struct Pareja {
    int dato;
    int nveces;
};

class Frecuencias{
    private:
        Pareja *parejas; // "npares" datos de tipo "Pareja" ordenados por "dato". 0 si no hay parejas.
        int npares;

        void liberarMemoria() ;

        void copiarDatos(const Frecuencias &otro) ;

        void reservarMemoria(const int tam) ;

        int devuelvePosicionDeInsertado(const int entero) ;

        bool compruebaSiEstaAniadido(const int entero, int &posicion) ;
    public:
        Frecuencias() ;

        ~Frecuencias() ;

        Frecuencias(const Frecuencias &otro) ;

        inline int getNpares() const{
            return npares ;
        }

        const Frecuencias & operator = (const Frecuencias &otro) ;

        /*
         * Recibe un entero y lo añade a la clase. Si el entero ya se habı́a añadido
         * anteriormente, deberá incrementar el contador correspondiente.
         * Si no, deberá añadir una nueva pareja con dicho entero y el contador con valor 1.
         */
        void Add(const int entero) ;

        const Frecuencias & operator+=(const int entero) ;

        friend ostream & operator << (ostream &flujo, Frecuencias &objeto) ;

};

#endif /* FRECUENCIAS_H */
