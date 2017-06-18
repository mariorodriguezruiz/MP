/**/

void ordenacionPUnteros(int *array, int util, int *parray){
    int indice ;
    int *aux ;

    // Inicializa el array de punteros
    for(int i = 0 ; i < util ; i++)
        parray[i] = &array[i] ;

    // Ordenacion burbuja
    for(int i = 0 ; i < util-1 ; i++){
        indice = i ;
        for(int j = i+1 ; j < util ; j++)
            if(*parray[indice] > *parray[j])
                indice = j ;

        aux = parray[i] ;
        parray[i] = parray[indice] ;
        parray[indice] = aux ;
    }
}
