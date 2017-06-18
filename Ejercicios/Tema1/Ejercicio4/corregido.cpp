void obtenerSecuenciaMonotonaCreciente(const int array[], int utilArray, int secuenciaCreciente[], int &utilSecuenciaCreciente){
    int longSecuenciaActual = 1 ;
    int posSecuenciaActual = 0 ;
    int posMaxSecuencia = 0 ;

    utilSecuenciaCreciente = 1 ;

    for(int i = 1 ; i < utilArray ; i++ ){
        if(array[i] > array [i-1]){
            longSecuenciaActual++ ;
            if(longSecuenciaActual > utilSecuenciaCreciente){
                utilSecuenciaCreciente = longSecuenciaActual ;
                posMaxSecuencia = posSecuenciaActual ;
            }

        }
        else{
            longSecuenciaActual = 1 ;
            posSecuenciaActual = i ;
        }
    }

    //Rellena el array resultado
    for(int i = 0 ; i< utilSecuenciaCreciente ; i++){
        secuenciaCreciente[i] = array[i+posMaxSecuencia] ;
    }

}
