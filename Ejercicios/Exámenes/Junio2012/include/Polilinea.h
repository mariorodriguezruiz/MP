#ifndef POLILINEA_H
#define POLILINEA_H

#include<iostream>
#include<string.h>
#include<Punto.h>
#include<assert.h>
#include<fstream>

using namespace std ;


class Polilinea{
    private:
        Punto *p ;  // Vector de puntos
        int num ;   // Número de puntos

        void liberarMemoria() ;

        void copiarDatos(const Polilinea &otro) ;

        void reservarMemoria(const int tamanio) ;

        bool igualesMismoOrden(const Polilinea & otra) const ;

        bool igualesOrdenINverso(const Polilinea & otra)const ;

        void aniadePunto(const Punto &nuevo) ;

        void aniadePuntoCoordenadas(const int x, const int y) ;
    public:
        Polilinea() ;

        Polilinea(const Polilinea &otro) ;

        ~Polilinea() ;

        const Polilinea & operator = (const Polilinea & otro) ;

        /*
            El operador de acceso [], que permite acceder (tanto para
            lectura como para escritura) a un dato de tipo Punto en una PoliLinea.
         */

        //Punto & operator [](int indice) ;

        Punto & operator [](int indice) const;

        /*
             Dos datos PoliLinea son iguales si tienen el mismo número de
             puntos, éstos son iguales y están dispuestos en el mismo
             orden o en orden inverso

         */

        bool operator == (const Polilinea &otra) const ;

        // Polilı́nea + punto. Se crea una nueva polilı́nea
        // añadiendo un punto al final de la misma.

        Polilinea & operator + (const Punto &punto) ;

        // punto + polilı́nea. Se crea una nueva polilı́nea
        // añadiendo un punto al inicio de la misma.

        friend Polilinea & operator + (const Punto &punto, const Polilinea &poli) ;


        void LeerPolilinea(const char *nombre);

        void EscribirPolilinea (const char *nombre, const char *comentario = 0) ;


        friend ostream & operator << (ostream &flujo, const Polilinea &objeto) ;
};

#endif /* POLILINEA_H */
