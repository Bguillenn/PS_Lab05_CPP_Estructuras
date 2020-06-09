#ifndef PERSONA_H
#define PERSONA_H

#include <string>

using namespace std;

//Definimos la estructura persona
struct Persona{
    string nombre; //Miembro que almacena el nombre
    int dia_nac; //Miembro que almacena el dia de nacimiento
    int mes_nac; //Miembro que almacena el mes de nacimiento
    int anio_nac; //Miembro que almacena el año de nacimiento
};

#endif // !PERSONA_H