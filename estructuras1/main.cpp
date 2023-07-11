#include <iostream>

using namespace std;

struct datos{
    char nombre[30];
    char boleta[20];
    char carrera[50];
    int edad;
}
persona1,persona2;

int main()
{
    cout<<"\n\tNombre: ";
    cin.getline(persona1.nombre,30,'\n');
    cout<<"\tBoleta: ";
    cin.getline(persona1.boleta,20,'\n');
    cout<<"\tCarrrera: ";
    cin.getline(persona1.carrera,50,'\n');
    cout<<"\tEdad: ";cin>>persona1.edad;
    cin.ignore();  //limpia el buffer que esta guardado
    cout<<"\n\tNombre: ";
    cin.getline(persona2.nombre,30,'\n');
    cout<<"\tBoleta: ";
    cin.getline(persona2.boleta,20,'\n');
    cout<<"\tCarrera: ";
    cin.getline(persona2.carrera,50,'\n');
    cout<<"\tEdad: ";cin>>persona2.edad;

    cout<<"\n\t     Imprimiendo datos"<<endl;
    cout<<"\n\tNombre: "<<persona1.nombre;
    cout<<"\n\tBoleta: "<<persona1.boleta;
    cout<<"\n\tCarrera: "<<persona1.carrera;
    cout<<"\n\tEdad: "<<persona1.edad;

    cout<<"\n\n\tNombre: "<<persona2.nombre;
    cout<<"\n\tBoleta: "<<persona2.boleta;
    cout<<"\n\tCarrera: "<<persona2.carrera;
    cout<<"\n\tEdad: "<<persona2.edad<<endl;
    return 0;
}
