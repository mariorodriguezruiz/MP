#ifndef MENU_H
#define MENU_H

#include<iostream>
#include<string.h>
#include<fstream>

using namespace std ;

class Menu{
    private:
        char *titulo; // Encabezado que damos al menú (0 si no existe)
        char **opc;   // Cadenas de longitud variable que describen cada una de las opciones
        int nopc;

        void liberarMemoria() ;

        void copiarDatos(const Menu &otro) ;
    public:
        Menu() ;

        ~Menu() ;

        Menu(const Menu &otro) ;

        const Menu & operator = (const Menu &otro) ;

        void SetTitulo(char *nuevo) ;

        int GetNumeroOpciones() ;

        // Recibe una cadena de caracteres y la añade como una nueva opción después de la última.
        void AddOpcion(char *nueva) ;

        friend ostream & operator << (ostream &flujo, const Menu &objeto) ;

        void operator >> (int &entero) ;


    //.........
};

#endif /* MENU_H */
