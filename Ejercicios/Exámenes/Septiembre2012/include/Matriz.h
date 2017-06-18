#ifndef MATRIZ_H
#define MATRIZ_H

#include<iostream>
#include<string.h>
#include<fstream>

using namespace std ;

class Matriz{
    private:
        int nfilas;         // Número de filas de la matriz
        int *ncolumnas;     // Número de columnas de cada fila (ejemplo:
        double **datos;     // Datos de la matriz

        void liberarMemoria() ;

        void copiar(const Matriz &otra) ;

    public:
        Matriz() ;

        ~Matriz() ;

        Matriz(const Matriz &otra) ;

        // Debería estar privado, está aqui para utilizar el main.
        void reservarMemoria(const int filas, const int *columnas) ;

        const Matriz & operator= (const Matriz &otra) ;

        friend ostream & operator << (ostream &flujo, const Matriz &objeto) ;

        friend istream & operator >> (istream &flujo, Matriz &objeto) ;

        void escribirArchivo(const string nombreArchivo, string comentario) ;

        bool leerArchivoBin(const string nombreArchivo) ;

        bool leerArchivo(const string nombreArchivo) ;

        double get(const int fil, const int col) ;

        void set(const int fil, const int col, const double valor) ;

        // Devuelve una nueva matriz intercambiando las filas
        // (primera por la última, segunda por la penúltima...)
        Matriz & Vflip() ;

        // Devuelva la posición (fila y columna) donde se encuentra el // mayor valor de la matriz.
        void Max(int &fila, int &columna) ;

    //.........
};

#endif /* MATRIZ_H */
