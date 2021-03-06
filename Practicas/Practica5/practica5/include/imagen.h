/**
@file
@author Mario Rodríguez Ruiz
@date 4 de abril de 2016
@brief Clase imagen blanco y negro.

*/
#ifndef _IMAGEN_H_
#define _IMAGEN_H_

#include<lista.h>

typedef unsigned char byte; ///< byte = 8bits almacenado en un unsigned char

/**
@brief Una imagen en blanco y negro. Cada píxel es un byte
*/
class Imagen{
private:
   static const int MAXPIXELS = 1000000;  ///< número máximo de píxeles que podemos almacenar 
   byte *datos;///< datos de la imagen
   int nfilas; 			///< número de filas de la imagen
   int ncolumnas;		///< número de columnsa de la imagen

/**
@brief Libera la memoria reservada llamando al destructor.

Además de liberar la memoria, también debe poner el número de filas y columnas a cero.

*/
    void destruir();

public:
/// Construye una imagen vacía (0 filas, 0 columnas)
   Imagen();


/**
@brief Construye una imagen negra de tamaño @a filas x @a columnas
@param filas 	número de filas de la imagen
@param columnas	número de columnas de la imagen

Construye una imagen de tamaño @a filas x @a columnas y pone todos
sus elementos a 0.
*/
   Imagen(int filas, int columnas);

/**
@brief Libera por defecto la memoria reservada.

Invoca a la función destruir para hacer una limpieza personalizada.

*/
   ~Imagen();

/**
@brief Define el plano @a k -ésimo de una imagen como una nueva imagen
con un tamaño idéntico.
@param k número de filas de la imagen

Dado un número, @a k, extrae el plano de bits k-ésimo de la imagen actual y lo devuelve como una nueva imagen.
*/
   Imagen plano(int k);


/**
@brief Crea una imagen negra de tamaño @a filas x @a columnas
@param filas 	número de filas de la imagen
@param columnas	número de columnas de la imagen

Dimensiona la imagen a tamaño @a filas x @a columnas y pone todos
sus elementos a 0.
*/
   void crear(int filas, int columnas);


/**
@brief Devuelve el número de filas de las imagen
@return el número de filas de la imagen
*/
   int filas();


/**
@brief Devuelve el número de columnas de las imagen
@return el número de columnas de la imagen
*/
   int columnas();


/**
@brief Asigna el valor @a v a la posición (@a x,@a y) de la imagen
@param y 	fila de la imagen
@param x 	columna de la imagen
@param v 	valor a asignar

Asigna el valor @a v a la posición (@a x,@a y) de la imagen. Dado que la imagen se guarda
como un vector, la posición (@a x,@a y) corresponde a la posición @a y * @c ncolumnas + @a x
del vector.
*/
   void set(int y, int x, byte v);


/**
@brief Devuelve el valor de la posición (@a x,@a y) de la imagen
@param y	 fila de la imagen
@param x	 columna de la imagen
@return el valor de la posición (@a x,@a y) de la imagen

Devuelve el valor de la posición (@a x,@a y) de la imagen. Dado que la imagen se guarda
como un vector, la posición (@a x,@a y) corresponde a la posición @a y * @c ncolumnas + @a x
del vector.
*/
   byte get(int y, int x);


/**
@brief Asigna el valor @a v a la posición @a i de la imagen considerada como vector
@param i 	posición de la imagen considerada como vector
@param v 	valor a asignar

Asigna el valor @a v a la posición @a i de la imagen considerada como vector. La posición @a i
corresponde con la posición @c y * @c ncolumnas + @c x de la imagen donde @c y representa la
fila y @c x representa la columna.
*/
   void setPos(int i, byte v);


/**
@brief Devuelve el valor de la posición @a i de la imagen considerada como vector
@param i 	posición de la imagen considerada como vector

Devuelve el valor de la posición @a i de la imagen considerada como vector. La posición @a i
corresponde con la posición @c y * @c ncolumnas + @c x de la imagen donde @c y representa la
fila y @c x representa la columna.
*/
   byte getPos(int i);


/**
@brief Carga una imagen desde un fichero
@param nombreFichero nombre del fichero que contiene la imagen
@retval true 	si ha tenido éxito en la lectura
@retval false 	si se ha producido algún error en la lectura

Lee desde disco los datos de la imagen llamada @a nombreFichero y la guarda en la memoria. La función debe asegurarse de que la imagen es de un tipo de imagen conocido y de que su tamaño es menor del tamaño máximo permitido (@c MAXDATOS).
*/
   bool leerImagen(const char nombreFichero[]);


/**
@brief Guarda una imagen desde un fichero
@param nombreFichero nombre del fichero que contiene la imagen
@param esBinario toma el valor @c true si el fichero se escribe en formato binario o @c false en caso contrario.
@retval true 	si ha tenido éxito en la escritura
@retval false 	si se ha producido algún error en la escritura
*/
   bool escribirImagen(const char nombreFichero[], bool esBinario);


/**
@brief hace imágenes con caracteres ASCII.
@param grises conjunto de caracteres que se usarán en el dibujo
@param arteASCII  contendrá la imagen convertida a arte ASCII
@param maxlong 	número máximo de caracteres que puede almacenar arteASCII

Consiste en representar cada pı́xel de una imagen con un carácter que
representa su nivel de gris.
*/
   bool aArteASCII(const char grises[], char arteASCII[], int maxlong) ;

/**
@brief Trabajará con una lista de celdas de cadenas.
@param grises conjunto de caracteres que se usarán en el dibujo
@param arteASCII  contendrá la imagen convertida a arte ASCII
@param maxlong 	número máximo de caracteres que puede almacenar arteASCII

El método debe generar, por cada cadena de la lista, un fichero de salida ASCII
tal y como se explica en el Ejercicio 1 de la Práctica 4 pero cambian-
do el nombre del fichero de salida a ascii1.txt, ascii2.txt,
etc. Esta función deberá iterar por cada celda de la lista y ejecutar el
método aArteASCII.

*/
   bool listaAArteASCII(const Lista celdas);

};

#endif
