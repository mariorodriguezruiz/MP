/*
    Escribir un programa que reciba los nombres de dos ficheros de texto de la línea de órdenes. El programa
    creará un fichero (cuyo nombre se especifica en el segundo argumento) a partir de un fichero existente (cuyo
    nombre se especifica en el primer argumento) copiando su contenido y añadiendo al principio de cada línea,
    su número.
*/

#include<iostream>
#include<fstream>
#include<string>

using namespace std ;

const int MAXLONG = 1000000;

/*void leelinea(char *s){
	do{
		cin.getline(s, MAXLONG);
	} while (s[0]=='\0');
}*/

int main(){
    ifstream fentrada ;
    ofstream fsalida ;
    string nombrefentrada, nombrefsalida, cadena ;
    int num_linea = 1 ;

    cout << "\nFichero entrada: ";
	getline(cin, nombrefentrada) ;
    fentrada.open(nombrefentrada.c_str()) ;

    cout << "\nFichero de salida: " ;
    getline(cin, nombrefsalida) ;

    if (!fentrada){
	   cerr << "\nError de apertura del fichero " << nombrefentrada << endl ;
	   return 1;
    }
    else{
        fsalida.open(nombrefsalida.c_str()) ;
        cadena = "" ;
        getline(fentrada, cadena) ;
        while(!fentrada.eof() || cadena.length() != 0){
            fsalida << num_linea << " " << cadena << endl;
            cadena = "" ;
            getline(fentrada, cadena) ;
            cout << "\nENTRO.." ;
            num_linea++ ;
        }
        fsalida.close() ;
        fentrada.close() ;
    }
}
