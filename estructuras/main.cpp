#include <iostream>

using namespace std;

struct personas{
    char nombre[30];
    int edad;
    float sueldo;
}
persona1={"rubert",22,23000.45},
persona2={"Lucas",45,32200.23}
;

int main()
{
    cout<<"\n\tTrabajador 1: " <<persona1.nombre;
    cout<<"\n\tEdad: "<<persona1.edad;
    cout<<"\n\tSueldo: "<<persona1.sueldo<<endl;
    cout<<"\n\tTrabajador 2: "<<persona2.nombre;
    cout<<"\n\tEdad: "<<persona2.edad;
    cout<<"\n\tSueldo: "<<persona2.sueldo<<endl;
    return 0;
}
