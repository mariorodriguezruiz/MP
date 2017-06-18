/*
    Mario Rodríguez Ruiz
    15 de marzo de 2016
    Implementación de las funciones de la clase Imagen.
*/

#include<imagen.h>
#include<pgm.h>
#include<byte.h>
#include<fstream>


// Construye una imagen vacia ( 0 filas , 0 columnas )
Imagen::Imagen()
    :datos(0),
    nfilas(0),
    ncolumnas(0){
}

// Construye una imagen negra de tamaño filas x columnas
Imagen::Imagen(int filas , int columnas){
    datos = 0 ;
    crear(filas, columnas) ;
}

// Constructor de copia.
Imagen::Imagen(const Imagen &otra){
    copiaDatos(otra) ;
}

// Destructor.
Imagen::~Imagen(){
    destruir() ;
}

// Permite liberar la memoria reservada.
void Imagen::destruir(){
    if(datos != 0){
        nfilas = 0 ;
        ncolumnas = 0 ;

        delete []datos ;
    }
}


void Imagen::copiaDatos(const Imagen &otra){
    crear(otra.filas(), otra.columnas()) ;
    for(int i = 0 ; i < nfilas*ncolumnas ; i++)
        datos[i] = otra.datos[i] ;
}

// Crea una imagen negra de tamaño filas x columnas
void Imagen::crear(int filas , int columnas){
    destruir() ;
    datos = new byte [filas*columnas] ;
    nfilas = filas ;
    ncolumnas = columnas ;

    for (int i = 0; i < nfilas*ncolumnas ; i++)
        setPos(i, 0) ;

}

// Dado k, extrae el plano de bits k-ésimo de la imagen actual y lo devuelve como una nueva imagen.
Imagen Imagen::plano(int k){
    Imagen nueva(nfilas, ncolumnas) ;
    bool estado ;

    // Copia la imagen tal y como estaba en la nueva.
    for(int i = 0 ; i < nfilas*ncolumnas ; i++)
        nueva.datos[i] = datos[i] ;

    // Guarda el estado del bit k del pixel
    // pone a 0 todos los pixeles
    // pone en el bit-kesimo el estado anteriormente guardado.
    for (int i = 0 ; i < nfilas*ncolumnas ; i++){
        estado = getbit(datos[i], k) ;
        apagar(nueva.datos[i]) ;
        if(estado)
            on(nueva.datos[i], 0) ;
    }

    return nueva ;
}

// Devuelve el numero de filas de la imagen
int Imagen::filas() const{
    return nfilas ;
}

// Devuelve el numero de columnas de la imagen
int Imagen::columnas() const{
    return ncolumnas ;
}

// Asigna el valor a la posición (x, y) de la imagen.
void Imagen::set(int y, int x, byte v){
    datos[y*ncolumnas + x] = v ;
}

// Devuelve el valor de la posición (x, y) de la imagen
byte Imagen::get(int y, int x) const{
    return datos[y*ncolumnas + x] ;
}

// Asigna el valor a la posición i de la imagen considerada como vector.
void Imagen::setPos(int i , byte v){
    datos[i] = v ;
}

// Devuelve el valor de la posición i de la imagen considerada como vector.
byte Imagen::getPos(int i){
    return datos[i] ;
}

// Carga una imagen desde el fichero
bool Imagen::leerImagen(const char nombreFichero[]){
    bool res = false;
    if(infoPGM(nombreFichero, nfilas, ncolumnas) == IMG_PGM_BINARIO){
        if(nfilas*ncolumnas < MAXPIXELS){
            crear(nfilas, ncolumnas) ;
            leerPGMBinario(nombreFichero, datos, nfilas, ncolumnas) ;
            res = true ;
        }
    }
    else if(infoPGM(nombreFichero, nfilas, ncolumnas) == IMG_PGM_TEXTO){
        if(nfilas*ncolumnas < MAXPIXELS){
            crear(nfilas, ncolumnas) ;
            leerPGMTexto(nombreFichero, datos, nfilas, ncolumnas) ;
            res = true ;
        }
    }
    return res ;
}

// Guarda la imagen en fichero. El parámetro esBinario ,
// que siempre tomará el valor true , se ańade para
// su uso en el futuro.
bool Imagen::escribirImagen(const char nombreFichero[], bool esBinario){
    if(esBinario)
        return escribirPGMBinario(nombreFichero, datos, nfilas, ncolumnas) ;
    else
        return escribirPGMTexto(nombreFichero, datos, nfilas, ncolumnas) ;
}

// Crea una imagen con caracteres ASCII.
bool Imagen::aArteASCII(const char grises[], char arteASCII[], int maxlong){
    // pos_orig es la posición en el vector de la imagen original
    // pos_ascii es la posición en el vector de la imagen ascci
    int cardinal, cont = 0, pos_ascii = 0, pos_orig = 0 ;
    // ncolumnas+1 porque hay que añadirle el \n a cada columna.
    // + 1 para el \0
    int tope = nfilas*(ncolumnas+1) + 1;
    bool res = true ;

    // Cuenta el número de cardinales que hay en grises.
    for(cardinal = 0 ; grises[cardinal] != '\0' ; cardinal++) ;

    if(tope > maxlong)
        res = false ;
    else{
        while(pos_orig < nfilas*ncolumnas){
            if(cont == ncolumnas){
                arteASCII[pos_ascii] = '\n' ;
                pos_ascii++ ;
                cont = 0 ;
            }
            // el carácter de salida será el que ocupe la posición entera
            // valorDelPixel ∗ cardinal/256 dentro del conjunto de caracteres.
            else{
                arteASCII[pos_ascii] = grises[datos[pos_orig]*cardinal/256] ;
                cont++ ;
                pos_orig++ ;
                pos_ascii++ ;
            }
        }
        arteASCII[pos_ascii] = '\0' ;
    }

    return res ;
}

bool Imagen::listaAArteASCII(const Lista celdas){
    ofstream fsalida ;
    string nombreFiSalida = "ascii" ;
    string ficheroSalida ;

    char *arteASCII ;
    int tope ;

    tope = filas()*(columnas()+1) + 1 ;
    arteASCII = new char[tope] ;

    for(int i = 0 ; i <= celdas.longitud() ; i++){
        ficheroSalida = nombreFiSalida + to_string(i+1) + ".txt" ;
        fsalida.open(ficheroSalida.c_str()) ;
        fsalida << "\nLa imagen en arte ASCII es:\n";

        if(aArteASCII(celdas.getCelda(i).c_str(), arteASCII, tope))
            fsalida << arteASCII ;
        else{
            cerr << "La conversión no ha sido posible." << endl;
            return 0 ;
        }
        fsalida.close() ;
    }

    delete[]arteASCII ;
    return 1 ;
}

// Sobrecarga del operador de asignación
Imagen &Imagen::operator= (const Imagen &otra) {
    if(this != &otra) {
        // Libera la memoria ocupada
        destruir();
        copiaDatos(otra);
    }
    return *this;
}

// Sobrecarga del operador '+'
Imagen Imagen::operator+ (const Imagen &otra) {
    int fil, col ;
    int posUna, posOtra, cuentaColUna, cuentaColOtra ;
    int tope, topeOtra ;

    col = ncolumnas + otra.columnas() ;
    fil = nfilas ;

    if(otra.filas() > nfilas)
        fil = otra.filas() ;

    Imagen nueva(fil, col) ;

    posUna = 0 ;
    posOtra = 0 ;
    cuentaColUna = 0 ;
    cuentaColOtra = 0 ;
    tope = nfilas*ncolumnas ;
    topeOtra = otra.filas()*otra.columnas() ;

    for(int i = 0 ; i < fil*col ; i++){
        if(cuentaColUna < ncolumnas && posUna < tope){
            nueva.datos[i] = datos[posUna] ;
            posUna++ ;
            cuentaColUna++ ;
        }
        else if(cuentaColUna < ncolumnas && posUna >= tope){
            nueva.datos[i] = 0 ;
            posUna++ ;
            cuentaColUna++ ;
        }
        else if(cuentaColOtra < otra.columnas() && posOtra < topeOtra){
            nueva.datos[i] = otra.datos[posOtra] ;
            posOtra++ ;
            cuentaColOtra++ ;
            if(cuentaColOtra == otra.columnas()){
                cuentaColOtra = 0 ;
                cuentaColUna = 0 ;
            }
        }
        else{
            nueva.datos[i] = 0 ;
            posOtra++ ;
            cuentaColOtra++ ;
            if(cuentaColOtra == otra.columnas()){
                cuentaColOtra = 0 ;
                cuentaColUna = 0 ;
            }
        }
    }

    return nueva;
}
