#ifndef BIGINT_H
#define BIGINT_H

#include <iostream>
#include<string.h>

using namespace std ;

class BigInt{
    private:
        int *datos;
        int numeroDigitos ;

        void liberarMemoria() ;

        void reservarMemoria(const int tamanio) ;

        void copiarDatos(const BigInt &otro) ;

        bool compruebaSiRestoSonNueves(const int indice) const;


    public:
        BigInt() ;

        ~BigInt() ;

        BigInt(const char *cadena) ;

        BigInt(const unsigned int numero) ;

        BigInt(const BigInt & otro) ;

        const BigInt &operator = (const BigInt &otro) ;

        /*
            A partir de dos objetos BigInt, se obtiene un nuevo
            objeto que corresponde al entero largo resultado de su suma.

        */
        const BigInt & operator + (const BigInt &otro) const ;

        /*
            Permite escribir el entero largo en un flujo de salida.
            Tenga en cuenta que deberá presentar todos los dı́gitos desde el más
            significativo al menos significativo (escritura habitual de enteros).
        */
        friend ostream &operator << (ostream &flujo, const BigInt &objeto) ;
        /*
            Nos permite leer el entero largo desde un flujo de entrada.
            Tenga en cuenta que deberá leer todos los dı́gitos desde el más
            significativo al menos significativo. El operador de entrada
            debe comportarse de forma similar al caso del tipo int, es decir,
            asumiendo que cada BigInt -secuencia de dı́gitos consecutivos- se
            encuentra separado de otros datos por “espacios blancos” (espacios,
            tabuladores, saltos de lı́nea, etc.).

        */
        friend istream &operator >> (istream &flujo, BigInt &objeto) ;

        void imprimeEntero() ;
    //.........
};

#endif /* BIGINT_H */
