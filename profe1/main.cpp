#include <iostream>
#include <string.h>

using namespace std;

typedef struct Alumno STUDENT;

struct Alumno {
     char nombre[50];
     unsigned long boleta;
};

void leer(STUDENT *s){
    cout<<"Nombre del Estudiante:";
    cin.getline(s->nombre,50,'\n');
    cout<<"Boleta:";
    cin>>s->boleta;
}
void ver(STUDENT s){
    cout<<"Nombre del Estudiante:"<<s.nombre<<endl;
    cout<<"Boleta:"<<s.boleta<<endl;
}

int main()
{
   STUDENT a;
   leer(&a);
   ver(a);

   /*
  strcpy(a.nombre,"Juanito Perez");
  a.boleta=30000;

  cout<<"Nombre del Alumno:"<<a.nombre<<endl;
  cout<<"Boleta:"<<a.boleta<<endl;
  */
  return 0;
}
