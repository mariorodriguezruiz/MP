/*
    Escribir un programa que permita encriptar y desencriptar el contenido de un fichero de texto. Para encriptar
    sustituiremos cada letra (mayúsculas y minúsculas) por la letra que está p posiciones más adelante en el
    alfabeto (para las últimas letras ciclamos el alfabeto). Los caracteres que no sean letras se quedarán igual.
    Para desencriptar la sustitución será a la inversa. La llamada al programa se realizará con este esquema:
        codifica <ficheroE> <ficheroS> <p> <tipo>
*/

#include<iostream>
#include<fstream>
#include<string>

using namespace std ;

bool comparaCadenas(const char *cad1, const char *cad2){
    bool resultado = true ;

    for(int i = 0; (cad1[i] != '\0' || cad2[i] != '\0')&& resultado; i++)
        if(cad1[i] != cad2[i])
            resultado = false ;

    return resultado ;
}

int main(){
    ifstream fentrada1, fentrada2 ;
    string nombref1, nombref2, cadena1, cadena2 ;
    int num_linea = 1 ;
    bool iguales = true;

    cout << "\nFichero entrada 1: ";
	getline(cin, nombref1) ;
    fentrada1.open(nombref1.c_str()) ;

    cout << "\nFichero entrada 2: ";
	getline(cin, nombref2) ;
    fentrada2.open(nombref2.c_str()) ;

    if (!fentrada1){
	   cerr << "\nError de apertura del fichero " << nombref1 << endl ;
	   return 1;
    }
    else if (!fentrada2){
	   cerr << "\nError de apertura del fichero " << nombref2 << endl ;
	   return 1;
    }
    else{
        cadena1 = "" ;
        cadena2 = "" ;
        getline(fentrada1, cadena1) ;
        getline(fentrada2, cadena2) ;
        iguales = comparaCadenas(cadena1.c_str(), cadena2.c_str()) ;
        while((!fentrada1.eof() || cadena1.length() != 0 ||
            !fentrada2.eof() || cadena2.length() != 0) && iguales){
            num_linea++ ;
            cadena2 = "" ;
            cadena1 = "" ;
            getline(fentrada1, cadena1) ;
            getline(fentrada2, cadena2) ;
            iguales = comparaCadenas(cadena1.c_str(), cadena2.c_str()) ;
        }
        fentrada2.close() ;
        fentrada1.close() ;
    }

    if(!iguales){
        cout << "\n{" << num_linea << "}";
        cout << "\tFich1: " << cadena1 ;
        cout << "\n\tFich2: " << cadena2 << endl;
    }
    else
        cout << "\nLos ficheros son iguales." << endl ;


}
