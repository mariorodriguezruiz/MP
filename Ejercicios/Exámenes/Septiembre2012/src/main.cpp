/*
    Examen septiembre 2012.

 */

#include<Matriz.h>

int main(int argc, char **argv){
    Matriz una, otra ;

    if(una.leerArchivo(argv[1])){
        cout << "\nÉxito. " ;
    }
    else{
        cerr << "\nError en la apertura del fichero. " ;
    }

    cout << una ;
    otra = una.Vflip() ;
    cout << otra ;

    int fila, columna ;

    una.Max(fila, columna) ;
    cout << "\nMax se encuentra en: " << fila << " " << columna << endl;

    return 0 ;
}

