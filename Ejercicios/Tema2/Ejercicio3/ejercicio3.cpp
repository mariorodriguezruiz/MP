/*
    Dado un vector de 10 elementos, escribe un programa que invierta el vector (sin usar el
    operador []).

*/

#include<iostream>

using namespace std ;

void muestraVector(const int *vector, const int total_utilizados){
    for(int i = 0 ; i < total_utilizados ; i++){
        cout << *(vector + i) << ", " ;
    }
}

int main(){
    const int TAM = 10 ;
    int vector[TAM] ;
    int tam_usr, total_utilizados = 0 ;
    int aux, tope ;

    do{
        cout << "\nTamaño: " ;
        cin >> tam_usr ;
    }while((tam_usr < 0) || (tam_usr > TAM)) ;

    for(int i = 0 ; i < tam_usr ; i++){
        cin >> *(vector + i) ;
        total_utilizados++ ;
    }

    cout << "\nVector original: " << endl ;
    muestraVector(vector, total_utilizados) ;

    tope = total_utilizados - 1 ;
    for(int i = 0 ; i < total_utilizados/2 ; i++){
        aux = *(vector + tope - i) ;
        *(vector + tope - i) = *(vector + i) ;
        *(vector + i) = aux ;
    }

    cout << "\nVector invertido: " << endl ;
    muestraVector(vector, total_utilizados) ;

}
