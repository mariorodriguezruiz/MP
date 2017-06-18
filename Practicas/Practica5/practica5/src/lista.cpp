#include <string>
#include <fstream>
#include <iostream>
#include "lista.h"

using namespace std;

Lista::Lista(){
    cabecera = 0 ;
}
   
Lista::Lista(string valor){
    cabecera = 0 ;
    insertar(valor) ;
}

// Permite liberar por defecto la memoria reservada.
/*Lista::~Lista(){
    destruir() ;
}*/

void Lista::destruir(){
    Celda * aux = cabecera;
    while(cabecera != 0){
        aux = cabecera;
        cabecera = cabecera->siguiente;
        delete aux;
    }
    cabecera = 0;
}

void Lista::eliminaUltimo(){
    Celda *pCelda, *penultimo, *ultimo ;

    if(cabecera != 0){
        pCelda = cabecera ;
        penultimo = cabecera ;
        ultimo = cabecera ;

        while(pCelda->siguiente != 0){
            if(pCelda->siguiente->siguiente != 0)
                penultimo = pCelda->siguiente ;

            pCelda = pCelda->siguiente ;
        }

        ultimo = penultimo->siguiente ;
        penultimo->siguiente = 0 ;

        if(ultimo != 0)
            delete ultimo ;
        if(penultimo == cabecera)
            cabecera = 0 ;
    }

}

void Lista::insertar(string valor){
    Celda *pCelda ;

    pCelda = new Celda ;
    pCelda->datos = valor ;
    pCelda->siguiente = 0 ;

    if(cabecera == 0)
        cabecera = pCelda ;
    else{
        Celda *tmp = cabecera ;
        while(tmp->siguiente != 0)
            tmp = tmp->siguiente ;

        tmp->siguiente = pCelda ;
    }
}

string Lista::getCelda(int pos) const{
    Celda *pCelda = cabecera ;
    int tam = longitud();

    if(pos > tam || pos < 0){
        return "";
    }

    for(int i = 0 ; i < longitud() && i != pos; i++){
        pCelda = pCelda->siguiente ;
    }
    return pCelda->datos ;
}

int Lista::longitud() const{
    Celda *pCelda = cabecera ;
    int longitud = 0 ;

    if(cabecera != 0){
        while(pCelda->siguiente != 0){
            pCelda = pCelda->siguiente ;
            longitud++ ;
        }
    }

    return longitud ;
}

/**
 * @brief Construye una lista de celdas enlazadas a partir de la informacion 
 * contenida en un fichero.
 * @param nombreFichero ruta del fichero de texto con el contenido de las datoss
 * a insertar en la lista
 * @retval true si ha tenido éxito en la lectura y el formato es el correcto
 * @retval false si se ha producido algún error en la lectura 
 * 
 * Lee desde disco los elementos almacenados en @a nombreFichero y los guarda 
 * en la lista. La función debe asegurarse de que la estructura sigue un patron 
 * determinado, y se ha de crear la lista con el numero de elementos que contenga. 
 */
bool Lista::leerLista(const char nombrefichero[]){
	ifstream fin;
	fin.open(nombrefichero);
	if(!fin){
		return false;
	}else{
		string grises;
		int lineas;
		getline(fin,grises); //la primera linea se ignora
		fin >> lineas; //leo el numero de datos de grises
		getline(fin,grises); //leer salto de linea
		if (!fin){
			return false;
		}else {
			int i = 0;
			getline(fin,grises); //leer cadena de caracteres
			while ((i < lineas)&&(fin)){
				if (grises != ""){
					insertar(grises);
					i++;
				}
				getline(fin,grises); //leer cadena de caracteres
			}
		}
		fin.close();
	}
	return true;
}
