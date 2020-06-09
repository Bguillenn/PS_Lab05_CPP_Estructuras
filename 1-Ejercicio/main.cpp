#include <iostream>
#include <string>
#include <conio.h>

#include "Ficheros.h"

using namespace std;

//Declaramos los metodos a implementarse
int mostrarMenu();
void procesarRespuesta(int);

//Instanciamos un objeto de la clase ficheros
Ficheros registro;

//Metodo main
int main(){
    //Creamos una variable opc donde se almacenara la opcion elegida por el usuario
    int opc;
    
    //Realizamos un bucle
    do{
        //Mostramos menu y guardamos el resultado en opc
        opc = mostrarMenu();
        //Procesamos la respuesta obtenida
        procesarRespuesta(opc);
        //Limpiamos el buffer para evitar problemas en el ingreso de datos
        fflush(stdin);
    }while(opc != 9);

    //Retornamos con exito la ejecucion del programa
    return EXIT_SUCCESS;
}

int mostrarMenu(){
    //Mostramos las opciones del menu con su descripcion
    cout << endl;
    cout << "Escoja una opcion:" << endl;
    cout << "1.- Crear datos de un nuevo fichero" << endl;
    cout << "2.- Mostrar los nombres de todos los ficheros" << endl;
    cout << "3.- Mostrar ficheros que sean de mas de un cierto tamanio" << endl;
    cout << "4.- Ver datos de un fichero" << endl;
    cout << "5.- Buscar por parecidos"<<endl;
    cout << "6.- Borrar dato"<<endl;
    cout << "7.- Editar dato"<<endl;
    cout << "8.- Ordenar por nombre"<<endl;
    cout << "9.- Salir" << endl;
    cout<<"\nIngresa una opcion: ";
    //Guardamos la opcion ingresada en una variable;
    int opcion;
    cin>>opcion;
    //Retornamos la opcion elegida
    return opcion;
}

void procesarRespuesta(int opc){
    //Creamos variables para almacenar un posible nombre, tamaño y nuevo fichero
    string nom;
    long tam;
    Fichero nuevo;
    cin.ignore();
    switch (opc){
        case 1: // Añadir un dato nuevo
            cout<<endl;
            cout<<"Ingresa el nombre del fichero: "; getline(cin,nom);
            cout<<"Ingresa el tamaño en KB: ";cin>>tam;
            cout<<endl;
            if(!nom.empty() && tam>0){
                nuevo.nombreFich = nom;
                nuevo.tamanyo = tam;
                registro.crearFichero(nuevo);
            }else{
                cout<<"ERROR: No se puede ingresar un nombre vacio o un tamaño negativo"<<endl;
            }
            break;
        case 2: // Mostrar todos
            cout<<endl;
            registro.mostrarTodo();
            cout<<endl;
            cout<<"Presione cualquier tecla para volver al menu.."<<endl;
            getch();
            break;
        case 3: // Mostrar según el tamaño
            cout << "¿A partir de que tamaño quieres que te muestre? ";
            cin >> tam;
            cout<<endl;
            registro.mostrarFicherosApartirDeTam(tam);
            cout<<endl;
            cout<<"Presione cualquier tecla para volver al menu.."<<endl;
            getch();
            break;
        case 4: // Ver todos los datos (pocos) de un fichero
            cout << "¿De qué fichero quieres ver todos los datos?";
            cin>>nom;
            cout<<endl;
            registro.mostrarFichero(nom);
            cout<<endl;
            cout<<"Presione cualquier tecla para volver al menu.."<<endl;
            getch();
            break;
        case 5:
            cout <<"¿Que cadena quieres que contenga el nombre a buscar? ";
            cin>>nom;
            registro.buscarFichero(nom);
            cout<<endl;
            cout<<"Presione cualquier tecla para volver al menu.."<<endl;
            getch();
        case 6:
            cout << "¿Que elemento deseas eliminar? ";
            cin >> nom;
            if(registro.eliminarFichero(nom))
                cout<<"Se elimino el registro con nombre:"<<nom<<endl;
            else
                cout<<"No se pudo encontrar el registro con nombre: "<<nom<<endl;
            cout<<endl;
            cout<<"Presiona cualquier tecla para volver al menu.."<<endl;
            getch();
            break;
        case 7:
            cout << "Ingrese el numero de registro que desea modificar: "; 
            int n;
            cin >> n; //Ingresa el indice del fichero a modificar
            cin.ignore(); //Limpiamos el buffer
            cout<<"Ingrese el nuevo nombre: "; getline(cin,nom); //pedimos que ingrese el nuevo nombre
            if(nom.empty()){ //Validamos si esta vacio para cancelar la operacion
                cout<<"Se cancelo la operacion! "<<endl; //Cancelamos la operacion
            }else{ //en caso no este vacio procedemos
                cout<<"Ingrese el tamaño: "; cin>>tam;
                if(registro.editarFichero(n,nom,tam))
                    cout<<"Registro actualizado con exito! "<<endl; //Validamos si no nos dio algun error
                else
                    cout<<"Ocurrio un error al actualizar revise los datos!"<<endl;
            }
            cout<<endl;
            cout<<"Presiona cualquier tecla para volver al menu.."<<endl;
            getch();
            break;
        case 8:
            cout<<"Ordenando por nombre A-Z.."<<endl;
            registro.ordenarFicherosPorNombre();
            cout<<"Operacion completada!"<<endl<<endl;
            break;
        case 9: // Salir: avisamos de que salimos
            cout << "Fin del programa" << endl;
            break;
        default: // Otra opcion: no válida
            cout << "Opción desconocida!" << endl;
            break;
        }
}

