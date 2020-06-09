#include <iostream>
#include <string>
#include <conio.h>

#include "Persona.h"

using namespace std;

Persona personas[50];
int cant_personas = 0;

void ingresarPersona(string nombre);
int mostrarMenu();
void procesarOpcion(int);
void mostrarTodosLosNombres();
void mostrarPersonasDeEdad(int edad);
void mostrarPersonasInicial(char i);

int main(){
    string nombre;
    do{
        cout<<endl;
        cout<<"Nueva persona:"<<endl;
        cout<<"Ingrese el nombre: ";getline(cin, nombre);
        ingresarPersona(nombre);
        fflush(stdin);
        cant_personas++;
    }while(!nombre.empty() && cant_personas < 50);

    int opc;

    do{
        opc = mostrarMenu();
        procesarOpcion(opc);
    }while(opc != 4);

    return EXIT_SUCCESS;
}

void ingresarPersona(string nombre){
    if(nombre.empty()) return;
    personas[cant_personas].nombre = nombre;
    cout<<"Ingrese la direccion: ";cin>>personas[cant_personas].direccion;
    cout<<"Ingrese el telefono: ";cin>>personas[cant_personas].telefono;
    cout<<"Ingrese la edad: ";cin>>personas[cant_personas].edad;
}

int mostrarMenu(){
    cout<<endl;
    cout<<"Menu de opciones:"<<endl;
    cout<<"1. Mostrar la lista de todos los nombres"<<endl;
    cout<<"2. Mostrar las personas de una cierta edad"<<endl;
    cout<<"3. Mostrar las personas cuya inicial sea indicada por el usuario"<<endl;
    cout<<"4. Salir"<<endl<<endl;

    int opc;
    cout<<"Ingrese una opcion: "; cin>>opc;

    return opc;
}

void procesarOpcion(int opc){
    switch(opc){
        case 1:
            mostrarTodosLosNombres();
            break;
        case 2:
            int edad;
            cout<<"Ingrese la edad que desea buscar: ";cin>>edad;
            mostrarPersonasDeEdad(edad);
            break;
        case 3:
            char inicial;
            cout<<"Ingrese la inicial: ";cin>>inicial;
            mostrarPersonasInicial(inicial);
            break;
        case 4:
            cout<<"FIN DEL PROGRAMA!"<<endl;
        default:
            cout<<"Opcion desconocida"<<endl;
    }
}

void mostrarTodosLosNombres(){
    cout<<endl;
    cout<<"Lista de todas las personas"<<endl;
    for(int i=0;i<cant_personas;i++)
        cout<<"Nombre: "<<personas[i].nombre<<endl;
    cout<<"Presione cualquier tecla para continuar"<<endl;
    getch();
}

void mostrarPersonasDeEdad(int edad){
    cout<<endl;
    cout<<"Personas de la edad "<<edad<<endl;
    for(int i=0;i<cant_personas;i++)
        if(personas[i].edad == edad)
            cout<<"Nombre: "<<personas[i].nombre<<endl;
    cout<<"Presione cualquier tecla para continuar"<<endl;
    getch();
}

void mostrarPersonasInicial(char inicial){
    cout<<endl;
    cout<<"Personas con la inicial "<<inicial<<endl;
    for(int i=0;i<cant_personas;i++)
        if(personas[i].nombre[i] == inicial)
            cout<<"Nombre: "<<personas[i].nombre<<endl;
    cout<<"Presione cualquier tecla para continuar"<<endl;
    getch();
}