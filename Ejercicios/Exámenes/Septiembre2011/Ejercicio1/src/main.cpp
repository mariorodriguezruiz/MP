/*
    Examen septiembre 2012.

 */

#include<Lista.h>

int main(int argc, char **argv){
    Lista una ;

    una.aniadirCelda(1) ;
    una.aniadirCelda(3) ;
    una.aniadirCelda(5) ;

    una.eliminaEnteroRepetido(5) ;

    cout << "\nNAAA " << una.obtenerDato(2) << endl;
}

