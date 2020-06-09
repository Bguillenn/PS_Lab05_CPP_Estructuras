#include <iostream>
#include <string>
#include <conio.h>

#include "Jugador.h"

using namespace std;

//Array donde almacenaremos nuestros jugadores
Jugador jugadores[20];

//Definimos los metodos necesarios
int mostrarMenu();
void procesarOpcion(int);
void esperarAccion();
void listarPorNombre();
void listarPorAltura();
void listarPorEdad();

int main(){
    cout<<"Ingresa los datos de los 20 jugadores>>"<<endl;
    Jugador temp;
    //Ingreso de los datos de los 20 jugadores
    for(int i=0;i<20;i++){
        cout<<endl;
        cout<<"JUGADOR ["<<(i+1)<<" de 20]:"<<endl;
        cout<<"Ingresa su nombre: "; getline(cin, temp.nombre);
        cout<<"Ingresa su edad: "; cin>>temp.edad;
        cout<<"Ingresa su estatura: "; cin>>temp.altura;
        jugadores[i] = temp;
        cin.ignore();
    }

    //Menu de opciones
    int opc;
    do{
        opc = mostrarMenu();
        procesarOpcion(opc);
    }while(opc != 4);

    return EXIT_SUCCESS;
}

//Funcion para mostrar elmenu y recibir la opcion elegida
int mostrarMenu(){
    cout<<endl;
    cout<<"Menu de opciones:"<<endl;
    cout<<"1. Listar nombres de jugadores"<<endl;
    cout<<"2. Listar alturas de los jugadores"<<endl;
    cout<<"3. Listar las edades de los jugadores"<<endl;
    cout<<"4. Salir"<<endl<<endl;
    int opc;
    cout<<"Ingresa una opcion: "; cin >> opc;

    return opc;
}

//Funcion para procesar la opcion
void procesarOpcion(int opc){
    switch(opc){
        case 1: //Listar por nombre
            listarPorNombre();
            esperarAccion();
            break;
        case 2: //Listar por altura
            listarPorAltura();
            esperarAccion();
            break;
        case 3: //listar por edad
            listarPorEdad();
            esperarAccion();
            break;
        case 4: //Salir
            cout<<"Fin del programa!"<<endl;
            break;
        default:
            cout<<"Opcion desconocida!"<<endl;
    }
}

//Funcion para esperar que el usuario presione una tecla
void esperarAccion(){
    cout<<endl<<"Presione cualquier tecla para volver al menu.."<<endl;
    getch();
}

//Funcion para listar por nombre
void listarPorNombre(){
    cout<<endl;
    for(int i =0 ; i<20;i++)
        cout<<"["<<(i+1)<<"] "<<jugadores[i].nombre<<endl;
    cout<<endl;
}

//Funcion para listar por altura
void listarPorAltura(){
    cout<<endl;
    for(int i=0;i<20;i++)
        cout<<"["<<(i+1)<<"] "<<jugadores[i].altura<<endl;
    cout<<endl;
}

//Funcion para listar por edad
void listarPorEdad(){
    cout<<endl;
    for(int i=0;i<20;i++)
        cout<<"["<<(i+1)<<"] "<<jugadores[i].edad<<endl;
    cout<<endl;
}