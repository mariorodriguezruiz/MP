#include<iostream>
#include<fstream>
#include<string>

using namespace std ;

int main(int argc, char **argv){
    ifstream input1, input2 ;
    ofstream output ;


    if(argc != 4){
        cerr << "\nError en el número de parámetros." << endl ;
        cerr << "\nPruebe: % programa input1.txt input2.txt output.txt"  << endl ;
        return 1 ;
    }

    input1.open(argv[1]) ;

    if(!input1){
        cerr << "\nError en la apertura del fichero." << argv[1] << endl ;
        return 1 ;
    }

    input2.open(argv[2]) ;

    if(!input2){
        cerr << "\nError en la apertura del fichero." << argv[2] << endl ;

        input1.close() ;
        return 1 ;
    }

    double dato1, dato2 ;

    output.open(argv[3]) ;
    input1 >> dato1 ;
    input2 >> dato2 ;

    while(!input1.eof() || !input2.eof()){
        if(!input1.eof() && !input2.eof()){
            if(dato1 < dato2){
                output << dato1 << " ";
                output << dato2 << " ";
            }
            else{
                output << dato2 << " ";
                output << dato1 << " ";
            }
            input1 >> dato1 ;
            input2 >> dato2 ;
        }
        else if(!input1.eof() && input2.eof()){
            output << dato1 << " ";
            input1 >> dato1 ;
        }
        else{
            output << dato2 << " ";
            input2 >> dato2 ;
        }
    }

    output << endl ;

    input1.close() ;
    input2.close() ;
    output.close() ;

    return 0 ;
}
