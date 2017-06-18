#include<Menu.h>

ostream & operator << (ostream &flujo, const Menu &objeto){
    flujo << objeto.titulo ;

    for(int i = 0 ; i < objeto.nopc ; i++)
        flujo << "\n\tOpción " << i+1 << ": " << objeto.opc[i] ;


    return flujo ;
}


