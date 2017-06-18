/*
    Escribir un trozo de código para mezclar, de manera ordenada, los valores de v1 y v2 en
    el vector res. No se debe usar el operador [], es decir, se debe resolver usando aritmética
    de punteros.
*/

#include<iostream>

using namespace std ;

void muestraVector(const float *vector, const int total_utilizados){
    for(int i = 0 ; i < total_utilizados ; i++){
        cout << *(vector + i) << ", " ;
    }
    cout << "\n" ;
}

void aniadeSegunPosicion(float *vector, int &util, const int valor, const int pos){
    util++ ;

    for(int i = util ; i > pos ; i--)
        *(vector + i) = *(vector + i-1) ;


    *(vector + pos) = valor ;


}

int main(){
    const int Max = 100;
    float v1 [Max] = {2, 3, 8, 22, 44, 88, 99, 100, 101, 255, 665};
    float v2 [Max] = {1, 3, 4, 5, 6, 25, 87, 89, 99, 100, 500, 1000};
    float res [2*Max];
    int tam_v1=11, tam_v2=12; // 0 <= tam_v1, tam_v2 < Max
    int tam_res = tam_v1+tam_v2; // 0 <= tam_res < 2*Max
    int util_res = 0, pos_lect_v1 = 0, pos_lect_v2 = 0 ;

    cout << "\nVector v1 original: " << endl ;
    muestraVector(v1, tam_v1) ;
    cout << "\nVectores v2 original: " << endl ;
    muestraVector(v2, tam_v2) ;

    // Copia v1 directamente en res
    for(int i = 0 ; i < tam_v1 ; i++){
        *(res + i) = *(v1 + i) ;
        util_res++ ;
    }

    bool continua ;
    while(pos_lect_v2 < tam_v2){
        continua = true ;
        for(int j = 0 ; j < util_res && continua; j++){
            if(*(res + j-1) == *(v2 + pos_lect_v2))
                continua = false ;
            else if(*(res + j) > *(v2 + pos_lect_v2)){
                aniadeSegunPosicion(res, util_res, *(v2 + pos_lect_v2), j) ;
                continua = false ;
            }
            else if(j == util_res-1){
                aniadeSegunPosicion(res, util_res, *(v2 + pos_lect_v2), util_res) ;
                continua = false ;
            }
        }

        pos_lect_v2++ ;

    }

    cout << "\nVector mezclado: " << endl ;
    muestraVector(res, util_res) ;

}
