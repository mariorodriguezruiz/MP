#ifndef PUNTO_H
#define PUNTO_H

#include<iostream>
#include<string.h>

using namespace std ;

class Punto{
    private:
        int x, y ;
    public:
        Punto(){
            x = 0 ;
            y = 0 ;
        }

        Punto(int valorX, int valorY){
            x = valorX ;
            y = valorY ;
        }

        inline int getX() const{
            return x ;
        }

        inline int getY() const{
            return y ;
        }

        inline void setX(const int valor){
            x = valor ;
        }

        inline void setY(const int valor){
            y = valor ;
        }
};

#endif /* PUNTO_H */
