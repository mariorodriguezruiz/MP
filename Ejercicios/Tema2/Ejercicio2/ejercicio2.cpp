/*
    Dado un vector de 10 elementos, haz un bucle que busque el máximo y el mı́nimo
    (sin usar el operador []). Al acabar el bucle tendremos un puntero apuntando a cada uno de ellos.
*/

#include<iostream>

using namespace std ;

int main(){
    const int TAM = 10 ;
    int vector[TAM] ;
    int tam_usr, total_utilizados = 0 ;
    int *ptrMax, *ptrMin ;

    do{
        cout << "\nTamaño: " ;
        cin >> tam_usr ;
    }while((tam_usr < 0) || (tam_usr > TAM)) ;

    for(int i = 0 ; i < tam_usr ; i++){
        cin >> *(vector + i) ;
        total_utilizados++ ;
    }

    ptrMax = (vector + 1) ;
    ptrMin = (vector + 1) ;

    for(int i = 0 ; i < total_utilizados ; i++){
        if(*ptrMin > *(vector + i))
            ptrMin = (vector + i) ;

        if(*ptrMax < *(vector + i))
            ptrMax = (vector + i) ;
    }

    cout << "\nMáximo: " << *ptrMax ;
    cout << "\nMínimo: " << *ptrMin << endl;

}
