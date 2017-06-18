/*
    Escribir un programa similar a grep que busque una cadena en una serie de ficheros de texto. La cadena a
    buscar y los ficheros en los que buscar se proporcionan en la línea de órdenes.
    Por ejemplo:
        busca Olga fich1 fich2 fich3
        busca la cadena Olga en los ficheros fich1, fich2 y fich3.
    Cada vez que encuentre la cadena buscada, debe indicar el fichero en el que es localizada, el número de línea
    y la línea completa que la contiene.


*/

#include<iostream>
#include<fstream>
#include<string.h>

using namespace std ;

void imprimeResultadoBusqueda(string nombreF, bool encontrado, string linea, int numLi){
    if(encontrado){
        cout << nombreF << " (linea " << numLi << "): " << linea << endl;
    }
    else
        cout << "\nNo se han encontrado coincidencias en " << nombreF << endl ;

}

void encuentraCadenaEnUnaLinea(ifstream &fichero, string nombreF, string texto){
    int numLinea = 0 ;
    bool encontrado = false;
    string linea ;
    unsigned posLinea = 0, posTexto = 0;

    linea = "" ;
    getline(fichero, linea) ;
    while(!fichero.eof() && !encontrado){
        numLinea++ ;
        while(posLinea < linea.length() && posTexto < texto.length()
            && !encontrado){
            if(linea[posLinea] == texto[posTexto]){
                posLinea++ ;
                posTexto++ ;
            }
            else{
                posTexto = 0 ;
                posLinea++ ;
            }
        }
        if(posTexto == texto.length())
            encontrado = true ;
        else{
            linea = "" ;
            getline(fichero, linea) ;
            posLinea = 0 ;
        }
    }

    imprimeResultadoBusqueda(nombreF, encontrado, linea, numLinea) ;

}


int main(){
    ifstream fentrada1, fentrada2, fentrada3 ;
    string nombrefich1,nombrefich2, nombrefich3, busqueda ;

    //Entrada.
    cout << "\nFichero 1: " ;
    getline(cin, nombrefich1) ;
    fentrada1.open(nombrefich1.c_str()) ;

    if(!fentrada1){
        cerr << "\nError en la apertura del fichero " << nombrefich1 << endl ;
        return 1 ;
    }

    /*cout << "\nFichero 2: " ;
    getline(cin, nombrefich2) ;
    fentrada2.open(nombrefich2.c_str()) ;

    if(!fentrada2){
        cerr << "\nError en la apertura del fichero " << nombrefich2 << endl ;
        return 1 ;
    }

    cout << "\nFichero 3: " ;
    getline(cin, nombrefich3) ;
    fentrada3.open(nombrefich3.c_str()) ;

    if(!fentrada3){
        cerr << "\nError en la apertura del fichero " << nombrefich3 << endl ;
        return 1 ;
    }*/

    cout << "\nTexto a buscar: " ;
    getline(cin, busqueda) ;

    encuentraCadenaEnUnaLinea(fentrada1,nombrefich1, busqueda) ;

    //Liberación de memoria y cierre de ficheros.
    fentrada1.close() ;
    /*fentrada2.close() ;
    fentrada3.close() ;*/

}
