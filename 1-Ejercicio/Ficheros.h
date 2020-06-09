#ifndef FICHEROS_H
#define FICHEROS_H

#include "Fichero.h"
#include <string>

using namespace std;

//CREAMOS LA CLASE FICHEROS QUE ADMINISTRA UN ARRAY DE FICHEROS
class Ficheros{
    private:
        Fichero ficheros[1000];
        int cant_ficheros; //Cantidad actual de ficheros
    public:
        Ficheros(); //Constructor
        void crearFichero(Fichero f); //Añade un nuevo fichero
        void mostrarTodo(); //Muestra todos los ficheros disponibles
        void mostrarFicherosApartirDeTam(long tam); //Muestra un fichero apartir de un tamaño dado
        void mostrarFichero(string nombre); //Muestra un fichero con el nombre dado si existe
        void buscarFichero(string query); //Muestra el fichero con el nombre que contenga query
        bool eliminarFichero(string nombre); //Elimina el primer registro encontrado con el nombre
        bool editarFichero(int n, string nom, long tam); //Edita el registro n con el nuevo nom y tam
        void ordenarFicherosPorNombre(); //Ordena los ficheros registrados por nombre
    };
#include "Ficheros.cpp" //Incluimos los metodos
#endif
