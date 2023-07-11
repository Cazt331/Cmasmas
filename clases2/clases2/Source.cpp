#include<iostream>

using namespace std;
class entero {
private: 
	int numerador,denominador,sum, recip1,deno;
public:
	entero();
	entero(int,int);
	void leer();
	void ver();
	void suma(entero,entero);
	~entero();
};
entero::entero() {
	sum = recip1 = numerador = denominador = 0;//constructor
}
entero::entero(int _numerador,int _denominador) {
	numerador = _numerador;
	denominador = _denominador;
}
entero::~entero() {//destructor
}
void entero::leer() {
	cout << "Digite el numerador: ";
	cin >> numerador;
	cout << "Digite el denominador: ";
	cin >> denominador;
}
void entero::ver() {
	cout << "\nEl resultado es: "<<recip1<<"/"<<deno<< endl;
}
void entero::suma(entero a,entero b) {
	recip1 = (a.numerador*b.denominador)+(a.denominador*b.numerador);
	deno = a.denominador*b.denominador;
}

int main() {
	entero a(0,0);
	a.leer();
	entero b(0,0);
	b.leer();
	a.suma(a,b);
	a.ver();

	system("pause");
	return 0;
}