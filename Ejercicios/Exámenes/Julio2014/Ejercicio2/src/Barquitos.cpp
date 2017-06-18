
#include<Barquitos.h>

Barquitos::Barquitos(){
    datos = 0 ;
    nfil = 0 ;
    ncol = 0 ;
}

Barquitos::Barquitos(const int filas, const int columnas){
    nfil = filas ;
    ncol = columnas ;
    reservarMemoria(nfil, ncol) ;

    for(int i = 0 ; i < nfil ; i++)
        for(int j = 0 ; j < ncol ; j++)
            datos[i][j] = agua ;
}

Barquitos::~Barquitos(){
    liberarMemoria() ;
}


void Barquitos::liberarMemoria(){
    if(datos != 0){
        for(int i = 0 ; i < nfil ; i++)
            delete []datos[i] ;

        delete []datos ;
        nfil = 0 ;
        ncol = 0 ;
    }
}

void Barquitos::reservarMemoria(const int filas, const int columnas){
    datos = new int *[nfil] ;

    for(int i = 0 ; i < nfil ; i++)
        datos[i] = new int[ncol] ;
}

void Barquitos::copiarDatos(const Barquitos &otra){
    nfil = otra.nfil ;
    ncol = otra.ncol ;

    for(int i = 0 ; i < nfil ; i++)
        for(int j = 0 ; j < ncol ; j++)
            datos[i][j] = otra.datos[i][j] ;
}

const Barquitos & Barquitos::operator = (const Barquitos &otro){
    if(this != &otro){
        liberarMemoria() ;
        reservarMemoria(otro.nfil, otro.ncol) ;
        copiarDatos(otro) ;
    }

    return *this ;
}

bool Barquitos::compruebaBordesDeCasilla(const int fila, const int columna){
    bool resultado = true ;

    for(int i = fila-1 ; i < fila+1 && resultado; i++)
        for(int j = columna-1 ; j < columna+1 && resultado; j++ )
            if(i >= 0 && i < nfil && j >= 0 && j <= ncol
                && i != fila && j != columna)
                resultado = datos[i][j] == agua ;

    return resultado ;
}

bool Barquitos::esPosibleColocarBarco(const char fila, const int columna, const int tamBarco, const char dibujo){
    bool resultado = true ;
    int numFila = fila - 'A' ;

    if (tamBarco <= 0 || tamBarco >= 9) {
        throw out_of_range("Tamaño de barco fuera de rango");
    }

    if (numFila < 0 || numFila > nfil) {
        throw out_of_range("Número de fila fuera de rango");
    }

    if (dibujo != 'H' || dibujo != 'V') {
        throw out_of_range("Dirección del dibujo fuera de rango");
    }

    // Comprueba horizontalmente que se pueda o verticalmente.
    if(dibujo == 'H'){
        int tope = tamBarco + columna - 2;
        if(tope > ncol)
            resultado = false ;
        else{
            for(int i = columna ; i <= tope && resultado; i++)
                resultado = compruebaBordesDeCasilla(numFila, i) ;
        }
    }
    else{
        int tope = tamBarco + numFila - 1;
        if(tope > nfil)
            resultado = false ;
        else{
            for(int i = fila ; i <= tope && resultado; i++)
                resultado = compruebaBordesDeCasilla(i, columna-1) ;
        }
    }

    return resultado ;
}

int Barquitos::Aleatorio(const int min, const int max){
    return rand() % max + min ;
}

void Barquitos::insertarBarco(const int tamBarco){
    int numFila, columna, numDibujo ;
    char fila, dibujo ;

    do{
        numFila = Aleatorio(0, nfil) ;
        fila = numFila + 'A' ;
        columna = Aleatorio(0, ncol) ;
        numDibujo = Aleatorio(1,2) ;

        if(numDibujo == 1)
            dibujo = 'H' ;
        else
            dibujo = 'V' ;
    }while(!esPosibleColocarBarco(fila, columna, tamBarco, dibujo)) ;
}

bool Barquitos::Leer(const char *nombre){
    ifstream input ;
    string magica ;
    int filas, columnas ;
    int valor ;

    input.open(nombre, ios::in | ios::binary) ;

    if(!input){
        cerr << "\nError en la apertura de " << nombre ;
        return false ;
    }

    input >> magica ;

    if(magica.compare("MP-BARQ-V1.0") != 0){
        cerr << "\nIdentificador incorrecto." << endl ;
        return false ;
    }
    else{
        input >> filas >> columnas ;

        input.ignore(1) ;

        liberarMemoria() ;
        reservarMemoria(filas,columnas) ;

        nfil = filas ;
        ncol = columnas ;

        for(int i = 0 ; i < nfil ; i++)
            for(int j = 0 ; j < ncol ; j++){
                input.read((char*) (&valor), sizeof (int));
                datos[i][j] = valor ;
            }

    }

    input.close() ;
    return true ;
}
