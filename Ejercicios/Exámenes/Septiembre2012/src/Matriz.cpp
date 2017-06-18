/*
 Implementación de los métodos de la clase Matriz.

 */
#include<Matriz.h>

// constructor sin parámetros (crea una matriz vacı́a)
Matriz::Matriz(){
    nfilas = 0 ;
    ncolumnas = 0 ;
    datos = 0 ;
}

Matriz::~Matriz(){
    liberarMemoria() ;
}

Matriz::Matriz(const Matriz &otra){
    reservarMemoria(otra.nfilas, otra.ncolumnas) ;
    copiar(otra) ;
}

const Matriz &Matriz::operator = (const Matriz &otra){
    if(this != &otra){
        liberarMemoria() ;
        reservarMemoria(otra.nfilas, otra.ncolumnas) ;
        copiar(otra) ;
    }
    return *this ;
}

void Matriz::copiar(const Matriz &otra){
    for(int i = 0 ; i < nfilas ; i++){
        for(int j = 0 ; j < ncolumnas[i] ; j++){
            datos[i][j] = otra.datos[i][j] ;
        }
    }
}

void Matriz::reservarMemoria(const int filas, const int *columnas){
    nfilas = filas ;
    ncolumnas = new int[nfilas] ;
    datos = new double *[nfilas] ;

    for(int i = 0 ; i < nfilas ; i++){
        ncolumnas[i] = columnas[i] ;
        datos[i] = new double[columnas[i]] ;
    }
}

void Matriz::liberarMemoria(){
    if(datos != 0){
        for(int i = 0 ; i < nfilas ; i++)
            delete []datos[i] ;

        delete []datos ;
        delete []ncolumnas ;

        nfilas = 0 ;
    }
}

void Matriz::escribirArchivo(const string nombreArchivo, string comentario){
    ofstream fichero(nombreArchivo.c_str(), ios::out | ios::binary) ;

    if(fichero.is_open()){
        fichero << "MP" << endl ;
        if(comentario.compare("") != 0)
            fichero << "# " << comentario << endl ;


        fichero << nfilas << endl ;

        for(int i = 0 ; i < nfilas ; i++){
            fichero.write((char *)(&ncolumnas[i]), sizeof(int) );
            fichero.write((char *)(datos[i]), sizeof(double)) ;
        }
    }

    fichero.close() ;
}

bool Matriz::leerArchivoBin(const string nombreArchivo){
    char linea[100] ;
    char marcaComentario ;
    int tamFila ;
    bool resultado = true ;

    liberarMemoria() ;
    ifstream fichero(nombreArchivo.c_str(), ios::in | ios::binary) ;

    if(fichero){
        fichero.getline(linea, 100) ;
        if(strcmp(linea, "MP") == 0){
            marcaComentario = fichero.peek() ;
            if(marcaComentario == '#')
                fichero.getline(linea,100) ;

            fichero >> nfilas ;
            fichero.ignore() ; // Salta el carácter '\n'

            // Reserva
            ncolumnas = new int[nfilas] ;
            datos = new double *[nfilas] ;

            for(int i = 0 ; i < nfilas ; i++){
                fichero.read((char *) &tamFila, sizeof(int)) ;
                ncolumnas[i] = tamFila ;
                datos[i] = new double [tamFila] ;
                fichero.read((char *)datos[i], sizeof(double)*tamFila) ;
            }
        }
        else
            resultado = false ;

        fichero.close() ;
    }
    else
        resultado = false ;

    return resultado ;

}

bool Matriz::leerArchivo(const string nombreArchivo){
    char linea[100] ;
    char marcaComentario ;
    int tamFila ;
    double valor ;
    bool resultado = true ;

    liberarMemoria() ;
    ifstream fichero(nombreArchivo.c_str(), ios::in) ;

    if(fichero){
        fichero.getline(linea, 100 ) ;
        if(strcmp(linea, "MP") == 0){
            marcaComentario = fichero.peek() ;
            if(marcaComentario == '#')
                fichero.getline(linea,100) ;

            fichero >> nfilas ;
            fichero.ignore() ;

            ncolumnas = new int[nfilas] ;
            datos = new double *[nfilas] ;

            for(int i = 0 ; i < nfilas ; i++){
                fichero >> tamFila ;
                ncolumnas[i] = tamFila ;
                datos[i] = new double[tamFila] ;
                for(int j = 0 ; j < tamFila ; j++){
                    fichero >> valor ;
                    datos[i][j] = valor ;
                }
            }
        }
        else
            resultado = false ;

        fichero.close() ;
    }
    else
        resultado = false ;

    return resultado ;
}

double Matriz::get(const int fil, const int col){
    if(fil >= 0 && fil < nfilas && col >= 0)
        return datos[fil][col] ;
    else
        return -1 ;
}

void Matriz::set(const int fil, const int col, const double valor){
    if(fil >= 0 && fil < nfilas && col >= 0)
        datos[fil][col] = valor ;
}

Matriz & Matriz::Vflip(){
    Matriz *nueva = new Matriz(*this) ;

    for(int i = 0 ; i < nfilas/2 ; i++){
        nueva->ncolumnas[i] = ncolumnas[nfilas-1-i] ;
        nueva->ncolumnas[nfilas-1-i] = ncolumnas[i] ;
        nueva->datos[nfilas-1-i] = datos[i] ;
        nueva->datos[i] = datos[nfilas-1-i] ;
    }

    return *nueva ;
}

void Matriz::Max(int &fila, int &columna){
    double mayor ;

    fila = 0 ;
    columna = 0 ;
    mayor = datos[fila][columna] ;

    for(int i = 0 ; i < nfilas ; i++){
        for(int j = 0 ; j < ncolumnas[i] ; j++)
            if(datos[i][j] > mayor){
                mayor = datos[i][j] ;
                fila = i ;
                columna = j ;
            }
    }

}

// Fin métodos.
