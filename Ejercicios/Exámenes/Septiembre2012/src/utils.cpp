#include<Matriz.h>


ostream & operator << (ostream &flujo, const Matriz &objeto){
    flujo << endl ;
    for(int i = 0 ; i < objeto.nfilas ; i++){
        for(int j = 0 ; j < objeto.ncolumnas[i] ; j++)
            flujo << objeto.datos[i][j] << " " ;
        flujo << endl ;
    }
    flujo << endl ;

    return flujo ;
}

istream & operator >> (istream &flujo, Matriz &objeto){
    for(int i = 0 ; i < objeto.nfilas ; i++)
        for(int j = 0 ; j < objeto.ncolumnas[i] ; j++)
            flujo >> objeto.datos[i][j] ;

    return flujo ;
}
