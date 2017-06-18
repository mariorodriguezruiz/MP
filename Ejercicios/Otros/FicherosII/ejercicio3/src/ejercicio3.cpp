/*
    Escribir un programa que reciba como parámetros tres nombres de ficheros de texto. Los dos primeros ficheros
    contienen números reales y están ordenados. El programa tomará los datos de esos ficheros y los irá copiando
    ordenadamente en el tercer fichero, de forma que al finalizar esté también ordenado.
    valgrind --leak-check=full --track-origins=yes
*/

#include<iostream>
#include<fstream>
#include<string>

using namespace std ;

void calculaTamanioCadena(ifstream &entrada, int &tamanio){

    tamanio = 0 ;
    char c ;

    c = entrada.get() ;
    while(!entrada.eof()){
        if(c != '\n' && c != '\0' && c != ' ')
            tamanio++ ;

        c = entrada.get() ;
    }
    entrada.clear() ;
    entrada.seekg (ios::beg);
}

void copiaCadenaEnVector(ifstream &entrada, double *v){
    char c ;
    double valor ;
    int index = 0 ;

    c = entrada.get() ;
    while(!entrada.eof()){
        if(c != '\n' && c != '\0' && c != ' '){
            valor = (double)c - 48;
            v[index] = valor ;
            index++ ;
        }

        c = entrada.get() ;
    }
}

void insertaValorEnPosicionVector(double *v, int &utilV, const int valor, const int pos){
    for(int i = utilV ; i > pos ; i--)
        v[i] = v[i-1] ;

    v[pos] = valor ;
    utilV++ ;
}

void copiaVectorEnOtro(const double *vIn, const int utilVin, double *vOut, int &utilVout){
    if(utilVout == 0){
        for(int i = 0 ; i < utilVin ; i++)
           vOut[i] = vIn[i] ;

        utilVout = utilVin ;
    }
    else{
        int i = 0 ;
        int j = 0 ;
        while(i < utilVin){
            if(vIn[i] < vOut[j]){
                insertaValorEnPosicionVector(vOut, utilVout, vIn[i], j) ;
                i++ ;
                j++ ;
            }
            else
                j++ ;
        }
    }
}

int main(){
    ifstream fentrada1, fentrada2 ;
    ofstream fsalida ;
    string nombref1, nombref2, nombreSalida ;
    double *vSalida, *v1, *v2 ;
    int totalUtilizadosV1, totalUtilizadosV2, totalUtilizadosVout;

    cout << "\nFichero entrada 1: ";
	getline(cin, nombref1) ;
    fentrada1.open(nombref1.c_str(), ios::in) ;

    if (!fentrada1){
	   cerr << "\nError de apertura del fichero " << nombref1 << endl ;
	   return 1;
    }

    cout << "\nFichero entrada 2: ";
	getline(cin, nombref2) ;
    fentrada2.open(nombref2.c_str(), ios::in) ;

    if (!fentrada2){
	   cerr << "\nError de apertura del fichero " << nombref2 << endl ;
	   return 1;
    }

    cout << "\nFichero salida: ";
	getline(cin, nombreSalida) ;
    fsalida.open(nombreSalida.c_str()) ;

    calculaTamanioCadena(fentrada1, totalUtilizadosV1) ;
    v1 = new double[totalUtilizadosV1] ;
    copiaCadenaEnVector(fentrada1, v1) ;

    calculaTamanioCadena(fentrada2, totalUtilizadosV2) ;
    v2 = new double[totalUtilizadosV2] ;
    copiaCadenaEnVector(fentrada2, v2) ;

    vSalida = new double[totalUtilizadosV1+totalUtilizadosV2] ;
    totalUtilizadosVout = 0 ;

    copiaVectorEnOtro(v1, totalUtilizadosV1, vSalida, totalUtilizadosVout) ;
    copiaVectorEnOtro(v2, totalUtilizadosV2, vSalida, totalUtilizadosVout) ;

    for(int i = 0 ; i < totalUtilizadosVout ; i++)
        fsalida << vSalida[i] << " " ;

    fentrada2.close() ;
    fentrada1.close() ;
    fsalida.close() ;

    delete []v1 ;
    delete []v2 ;
    delete []vSalida ;
}
