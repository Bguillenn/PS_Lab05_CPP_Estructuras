#include <iostream>
#include <string>
#include <conio.h>

#include "Persona.h"

using namespace std;

void mostrarPersonaPorMes(int mes);

//Creamos un array de personas
Persona personas[8];

int main(){
    //Registramos los datos de las 8 personas
    for(int i = 0;i<8;i++){
        cout<<"Ingresando datos [ PERSONA "<<(i+1)<<" de 8]"<<endl;
        cout<<"Ingrese su nombre: ";cin>>personas[i].nombre;
        cout<<"Ingrese dia de nacimiento: ";cin>>personas[i].dia_nac;
        cout<<"Ingrese mes de nacimiento: ";cin>>personas[i].mes_nac;
        cout<<"Ingrese anio de nacimineto: ";cin>>personas[i].anio_nac;
    }

    int mes;
    //Solicitamos que ingrese un numero de mes hasta que digite 0
    do{
        cout<<endl;
        cout<<"Ingrese el mes: ";cin>>mes; //Solicitamos el numero de mes
        cout<<endl;
        mostrarPersonaPorMes(mes); //Llamamos a la funcion
    }while(mes > 0);

        cout<<"Fin del programa"<<endl;
    return EXIT_SUCCESS;
}

void mostrarPersonaPorMes(int mes){
    //Validamos que ingrese un mes mayor a 0
    if(mes <= 0)return;
    
    cout<<"MOSTRANDO PERSONAS QUE CUMPLEN AÑOS EN EL MES "<<mes<<endl;
    //Buscamos las personas que cumplen años en ese mes
    for(int i = 0; i<8;i++)
        if(personas[i].mes_nac == mes)
            cout<<"Nombre :: "<<personas[i].nombre<<endl;
    cout<<"Presione cualquier tecla para continuar.."<<endl;
    //Esperamos a que el usuario presione alguna tecla para regresar al ingreso de mes
    getch();
}
