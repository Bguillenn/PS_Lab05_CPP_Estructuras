#include <iostream>
#include <string>

#include "Persona.h"

using namespace std;

//Definimos

int main(){
    Persona persona;

    cout<<"Ingresa el nombre: ";cin>>persona.nombre;
    cout<<"Ingresa el apellido: ";cin>>persona.apellido;
    cout<<"Ingresa la edad: ";cin>>persona.edad;

    cout<<persona.nombre<<", "<<persona.apellido<<", "<<persona.edad;
    return EXIT_SUCCESS;
}