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
        byte **datos;///< datos de la imagen
        int nfilas; 			///< número de filas de la imagen
        int ncolumnas;		///< número de columnas de la imagen

        /**
        @brief Libera la memoria reservada llamando al destructor.

        Además de liberar la memoria, también debe poner el número de filas y columnas a cero.

        */
            void destruir();

        /**
        @brief Modifica una fila sumando dos filas distintas.
        @param numFila 	número de fila a modificar
        @param unosDatos	vector de datos de la primera fila a sumar
        @param utilUnos 	número de datos del primer vector.
        @param otrosDatos	vector de datos de la segunda fila a sumar
        @param utilOtros 	número de datos del segundo vector.

        Construye una fila completa mediante dos grupos de datos distintos que finalmente se estableceran juntos en esa fila.
        */
            void modificaFila(const int numFila, const byte *unosDatos, const int utilUnos, const byte *otrosDatos, const int utilOtros) ;

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
        * @brief Constructor de copia
        * @param otra es el objeto a asignar
        *
        * Construye una imagen a partir de @a otra
        */
        Imagen(const Imagen &otra);

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
        int filas() const;


        /**
        @brief Devuelve el número de columnas de las imagen
        @return el número de columnas de la imagen
        */
        int columnas() const;


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
        byte get(int y, int x) const;


        /**
        @brief Asigna el valor @a v a la posición @a i @a j de la imagen considerada como matriz
        @param i 	posición de una fila de la imagen considerada como matriz
        @param j 	posición de una columna de la imagen considerada como matriz
        @param v 	valor a asignar

        Asigna el valor @a v a la posición @a i @a j de la imagen considerada como matriz. .
        */
        void setPos(int i, int j, byte v);


        /**
        @brief Devuelve el valor de la posición @a i de la imagen considerada como vector
        @param i 	posición de la imagen considerada como vector
        @param j 	posición de la imagen considerada como vector

        Devuelve el valor de la posición @a i @a j de la imagen considerada como matriz. .
        */
        byte getPos(int i, int j) const;


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

        /**
        @brief Copia el contenido de una imagen en otra.
        @param otra Imagen a copiar
        */
        void copiaDatos(const Imagen &otra) ;

        /**
        * @brief Sobrecarga el operador de asignación
        * @param otra es el objeto a copiar
        *
        * Construye una imagen a partir de @a otra
        */
        Imagen& operator= (const Imagen &otra) ;

        /**
        * @brief Sobrecarga el operador '+'
        * @param imagen es el objeto a copiar
        *
        * Sobrecarga el operador ’+’ para poder realizar operaciones de concatenación de imágenes
        */
        Imagen operator+ (const Imagen &otra) ;

};

#endif
