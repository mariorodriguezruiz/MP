/*
    Se desea una función que reciba un vector de números enteros junto con su longitud y
    que devuelva un puntero al elemento mayor.
    a) Devuelve el resultado como resultado de la función (return).
*/

#include<iostream>

using namespace std ;

int *punteroAlElementoMayor(int *vector, const int util){
    int *mayor ;
    mayor = vector ;

    for(int i = 1 ; i < util ; i++)
        if(*(vector + i) > *mayor)
            mayor = vector + i ;

    return mayor ;
}

int main(){
    const int MAX = 100;
    int v1[MAX] = {2, 3, 8, 22, 44, 1024, 99, 100, 101, 255, 665};
    int util_v1 = 11 ;

    cout << "\nEl elemento mayor es: " << *punteroAlElementoMayor(v1, util_v1) << endl ;
}
