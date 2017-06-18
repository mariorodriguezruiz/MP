/*
    Se desea una función que reciba un vector de números enteros junto con su longitud y
    que devuelva un puntero al elemento mayor.
    b) Devuelve el resultado a través de un parámetro (función void).
*/

#include<iostream>

using namespace std ;

void punteroAlElementoMayor(int *vector, const int util, int **mayor){
    mayor = vector ;

    for(int i = 1 ; i < util ; i++)
        if(*(vector + i) > *mayor)
            mayor = vector + i ;
}

int main(){
    const int MAX = 100;
    int v1[MAX] = {2, 3, 8, 22, 44, 1024, 99, 100, 101, 255, 665};
    int util_v1 = 11 ;
    int *mayor ;

    punteroAlElementoMayor(v1, util_v1, *mayor) ;
    cout << "\nEl elemento mayor es: " << *mayor << endl ;
}
