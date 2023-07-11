#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
void imprimir(int n);
struct datos{
    char nombre[30];
    char boleta[30];
    char carrera[50];
    int edad;
    int materias;
}personas[100];
int main(){
    int n,i;
    cout<<"\n\tCantidad de personas a registrar: ";cin>>n;
    for(i=0;i<n;i++){
        cin.ignore();//Vacia el buffer y permite escribir sin saltarse
        cout<<"\n\tNombre: ";
        cin.getline(personas[i].nombre,30,'\n');
        cout<<"\tBoleta: ";
        cin.getline(personas[i].boleta,30,'\n');
        cout<<"\tCarrera: ";
        cin.getline(personas[i].carrera,50,'\n');
        cout<<"\tEdad: ";cin>>personas[i].edad;
        cout<<"\tMaterias: ";cin>>personas[i].materias;
        cout<<"\n";
    }
    imprimir(n);
    cout<<"\n----------------------------------------------\n";
    return 0;
}
void imprimir(int n){
    int i;
    for(i=0;i<n;i++){
        cout<<"\n----------------------------------------------\n";
        cout<<"\n\tNombre: "<<personas[i].nombre;
        cout<<"\n\tBoleta: "<<personas[i].boleta;
        cout<<"\n\tEdad: "<<personas[i].edad;
        cout<<"\n\tCarrera: "<<personas[i].carrera;
        cout<<"\n\tMaterias: "<<personas[i].materias<<endl;
    }
}
