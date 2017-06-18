/*
    Escriba un programa alreves que recibe en la lı́nea de órdenes el nombre de un fichero, y escribe
    en la salida estándar el mismo flujo de caracteres, pero en orden inverso. Por ejemplo, si el archivo abecedario.txt
    contiene los caracteres:
        abcdefghijklmñ
        nopqrstuvwxyz
    una posible ejecución del programa obtendrı́a lo que sigue:
        % alreves abecedario.txt
        zyxwvutsrqpoñ
        nmlkjihgfedcba

*/

#include<iostream>
#include<fstream>

using namespace std ;

void aniadeCaracterAcadena(char *&cadena, int &util, char valor){
    char *nueva ;

    nueva = new char[util+1] ;

    for(int i = 0 ; i < util ; i++)
        nueva[i] = cadena[i] ;

    nueva[util] = valor ;
    util++ ;

    delete []cadena ;
    cadena = nueva ;
}

void imprimeCadenaAlReves(const char *cadena, const int util){
    for(int i = util-1 ; i >= 0 ; i--)
        cout << cadena[i] ;

    cout << "\n" ;
}

int main(int argc, char **argv){
    ifstream fichero ;
    char *cadena = 0;
    int utilCadena = 0 ;
    char c ;

    if(argc != 2){
        cerr << "\nNúmero de parámetros incorrecto. Pruebe: % alreves abecedario.txt" << endl ;
        return 1 ;
    }

    fichero.open(argv[1]) ;

    if(!fichero){
        cerr << "\nError al abrir el fichero " << argv[1] << endl ;
        return 1 ;
    }
    else{
        c = fichero.get() ;

        while(!fichero.eof()){
            aniadeCaracterAcadena(cadena, utilCadena, c) ;
            c = fichero.get() ;
        }

        imprimeCadenaAlReves(cadena, utilCadena) ;
    }

    fichero.close() ;
    delete []cadena ;

    return 0 ;
}
