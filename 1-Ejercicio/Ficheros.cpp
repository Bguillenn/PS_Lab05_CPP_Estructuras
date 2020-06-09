#include "Fichero.h"
#include "Ficheros.h"

#include <iostream>
#include <string>

using namespace std;

//Definimos el constructor
Ficheros::Ficheros(){
    Ficheros::cant_ficheros = 0; //Inicializa en 0 la cantidad de ficheros registrados
}

//Definimos el metodo crearFichero
void Ficheros::crearFichero(Fichero f){
    if(cant_ficheros >= 1000){  //Validamos que haya espacio disponible
        cerr<<"ERROR: No hay campo para añadir un nuevo fichero"<<endl;   
    }else{
        //Si aun hay espacio añadimos el fichero
        ficheros[cant_ficheros] = f;
        //Aumentamos la cantidad de ficheros
        cant_ficheros++;
    }
}

//Definimos el metodo mostrarTodo
void Ficheros::mostrarTodo(){
    //Recorremos el arreglo hasta la cantidad registrada en cant_ficheros
    for(int i = 0;i < cant_ficheros; i++)
        cout<<"Nombre: "<<ficheros[i].nombreFich<<" Tamanio: "<<ficheros[i].tamanyo<<endl;
}

//Definimos el metodo mostrarFicherosApartirDeTam
void Ficheros::mostrarFicherosApartirDeTam(long tam){
    //Recorremos el arreglo hasta la cantidad registrada en cant_ficheros
    for(int i=0;i<cant_ficheros;i++)
        if(ficheros[i].tamanyo >= tam) //Validamos que cumpla con el tamaño establecido
            cout<<"Nombre: "<<ficheros[i].nombreFich<<" Tamanio: "<<ficheros[i].tamanyo<<endl;
}

//Definimos el metodo mostrarFichero
void Ficheros::mostrarFichero(string nombre){
    //Recorremos el arreglo hasta la cantidad registrada en cant_ficheros
    for(int i=0;i<cant_ficheros;i++) 
        if(ficheros[i].nombreFich.compare(nombre) == 0) //Validamos que cumpla la condicion del nombre
            cout<<"Nombre: "<<ficheros[i].nombreFich<<" Tamanio: "<<ficheros[i].tamanyo<<endl;
}

//Definimos el metodo buscarFichero
void Ficheros::buscarFichero(string query){
    //Recorremos el arreglo hasta la cantidad registrada en cant_ficheros
    for(int i=0;i < cant_ficheros;i++)
        if(ficheros[i].nombreFich.find(query) != string::npos) //Verificamos si contiene el query para mostrar
            cout<<"Nombre: "<<ficheros[i].nombreFich<<" Tamanio: "<<ficheros[i].tamanyo<<endl;
}

//Definimos el metodo eliminarFichero
bool Ficheros::eliminarFichero(string nombre){
    //Recorremos el arreglo en busca del fichero
    for(int i=0; i< cant_ficheros;i++)
         if(ficheros[i].nombreFich.compare(nombre) == 0) //Validamos que cumpla la condicion del nombre
            {
                for(int j=i; j<cant_ficheros;j++) // Comenzamos a mover todo a la izquierda
                    ficheros[j] = ficheros[j+1];
                cant_ficheros--; //Restamos en uno la cantidad de ficheros
                return true; //Regresamos que si se borro algo
            }
    return false; //En caso no encuentre nada regresamos que no borro nada
}

//Definimos el metodo editarFichero
bool Ficheros::editarFichero(int n, string nom, long tam){
    if(n < 0 || n >= cant_ficheros) return false; //Validamos que ingrese una posicion valida
    if(nom.empty() || tam <= 0) return false; //Validamos que los datos nuevos sean correctos
    ficheros[n].nombreFich = nom; //Cambiamos el nombre
    ficheros[n].tamanyo = tam; //Cambiamos el tamaño
    return true; //Retornamos todo correcto
}

//Definimos el metodo ordenarFicherosPorNombre
void Ficheros::ordenarFicherosPorNombre(){
    if(cant_ficheros == 0) return; //Validamos que existan ficheros
    Fichero aux; //Creamos un auxiliar 
    for(int i=0 ; i<cant_ficheros ;i++) //Creamos un bucle anidado para metodo burbuja
        for(int j=0; j<cant_ficheros-i-1;j++)
            if(ficheros[j].nombreFich.compare(ficheros[j+1].nombreFich) > 0){ //Validamos si la posicion actual es mayor que la siguiente
                aux = ficheros[j]; //Guardamos la posicion actual en aux
                ficheros[j] = ficheros[j+1]; //Modificamos la posicion actual con el siguiente
                ficheros[j+1] = aux; //La posicion siguiente le ponemos aux
            }
}