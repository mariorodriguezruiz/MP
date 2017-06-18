#ifndef LISTA_H
#define LISTA_H

#include<celda.h>

class Lista{
    private:
        Celda * contenido;
        int longitud ;

        void liberarMemoria() ;

        Celda * obtenerCelda(const int indice) const ;
    public:
        Lista() ;

        ~Lista() ;

        inline int getLongitud() const{
            return longitud ;
        }

        void aniadeCeldaAlfinal(const double valor) ;

        void eliminaUltimaCelda() ;

        void imprimeObjeto() ;

        void insertaCeldaDetras(const int indice, Celda *nueva) ;

        void insertaCeldaDelante(const int indice, Celda *nueva) ;

        double obtenerElemento(const int indice) const ;

        void eliminaCelda(const int indice) ;
};

#endif /* LISTA_H */
