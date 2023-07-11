#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <math.h>
#include <conio.h>

void general(float discr,float b,float a);
void cero(float b,float a);
void imaginario(float a,float b,float c);

using namespace std;

int main()
{
    float a,b,c,discr,elecc;//ERROR A=1  B=-7  C=12
    while(elecc!=0){
        cout<<"\n\tColoca el valor de A: ";cin>>a;
        cout<<"\tColoca el valor de B: ";cin>>b;
        cout<<"\tColoca el valor de C: ";cin>>c;
        cout<<"-----------------------------------------------";
        discr=(pow(b,2)-(4*a*c));
        if(discr>0){
            general(discr,b,a);
        }
        else if(discr==0){
            cero(b,a);
        }
        else if(discr<0){
            imaginario(a,b,c);
        }
        cout<<"Quieres resolver otra ecuacion";
        cout<<"\nSI digita un 1";
        cout<<"\nNO dita un 0: ";
        cin>>elecc;
    }
    return 0;
}
void general(float discr,float b,float a){
    float form1,form2,valabs1,valabs2,arri1,arri2;
    arri1=(-b+sqrt(discr));
    arri2=(-b-sqrt(discr));
    form1=(arri1/(2*a));
    form2=(arri2/(2*a));
    if(a==0){
        cout<<"\n\n\tNo existe solucion real"<<endl;
        cout<<"\n-----------------------------------------------"<<endl;
    }
    else if(arri1==0){
        cout<<"\n\n\tEl primer resultado es: 0";
        cout<<"\n\tEl segundo resultado es: "<<form2<<endl;
        cout<<"\n-----------------------------------------------"<<endl;
    }
    else if(arri2==0){
        cout<<"\n\n\tEl primer resultado es: "<<form1;
        cout<<"\n\tEl segundo resultado es: 0"<<endl;
        cout<<"\n-----------------------------------------------"<<endl;
    }
    else if(form1!=-0 || form2!=-0){
        cout<<"\n\n\tEl primer resultado es: "<<form1;
        cout<<"\n\tEl segundo resultado es: "<<form2<<endl;
        cout<<"\n-----------------------------------------------"<<endl;
    }
    else if(form1==-0){
        valabs1=abs(form1);
        cout<<"\n\n\tEl primer resultado es: "<<valabs1;
        cout<<"\n\tEl segundo resultado es: "<<form2<<endl;
        cout<<"\n-----------------------------------------------"<<endl;
    }
    else if(form2==-0){
        cout<<"\n\n\tEl primer resultado es: "<<form1;
        cout<<"\n\tEl segundo resultado es: "<<valabs2<<endl;
        cout<<"\n-----------------------------------------------"<<endl;
    }
}
void cero(float b,float a){
    float form1,valabs;
    if(b<0){
        form1=(abs(b)/(2*a));
        cout<<"\n\n\tEl resultado es: "<<form1<<endl;
        cout<<"\n-----------------------------------------------"<<endl;
    }
    form1=(-b/(2*a));
    if(form1==-0){
        valabs=abs(form1);
        cout<<"\n\n\tEl resultado es: "<<valabs<<endl;
        cout<<"\n-----------------------------------------------"<<endl;
    }
    else if(form1==0){
        cout<<"\n\n\tEl resultado es: "<<form1<<endl;
        cout<<"\n-----------------------------------------------"<<endl;
    }
}
void imaginario(float a,float b,float c){
    float form1,raiz,abaj;
    raiz=sqrt(abs((pow(b,2)-(4*a*c))));
    abaj=(2*a);
    if(b<0){
        form1=(b/(abaj));
            cout<<"\n\n\tEl primer resultado es: "<<form1<<"+"<<raiz<<"i"<<"/"<<abaj;
            cout<<"\n\tEl segundo resultado es: "<<form1<<"-"<<raiz<<"i"<<"/"<<abaj<<endl;
            cout<<"\n-----------------------------------------------"<<endl;
        }
    form1=((-b)/abaj);
    cout<<"\n\n\tEl primer resultado es: "<<form1<<"+"<<raiz<<"i"<<"/"<<abaj;
    cout<<"\n\tEl segundo resultado es: "<<form1<<"-"<<raiz<<"i"<<"/"<<abaj<<endl;
    cout<<"\n-----------------------------------------------"<<endl;
}
