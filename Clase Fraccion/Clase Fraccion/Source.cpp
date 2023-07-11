#include <iostream>

using namespace std;

class Fraccion {
	int enteros;
	int numerador;
	int denominador;
public:
	Fraccion();
	Fraccion(int);
	Fraccion(int, int);
	Fraccion(int, int, int);
	void leer();
	void ver();
	void suma(int, int, int);
	~Fraccion();

};
Fraccion::Fraccion() {
	enteros = numerador = denominador = 0;
}
Fraccion::~Fraccion() {
}
Fraccion::Fraccion(int ents) {
	enteros = ents;
	numerador = denominador = 0;
}
Fraccion::Fraccion(int num, int den) {
	enteros = 0;
	numerador = num;
	denominador = den;
}
Fraccion::Fraccion(int ents, int num, int den) {
	enteros = ents;
	numerador = num;
	denominador = den;
}
void Fraccion::leer() {
	cin >> enteros >> numerador >> denominador;
}
void Fraccion::ver() {
	cout << enteros << " " << numerador << "/" << denominador << endl;
}
void Fraccion::suma(int a, int b, int c) {
	enteros = enteros + a;
	numerador = numerador + b;
	denominador += c;
}
int main()
{
	Fraccion a;
	Fraccion b(1, 2);

	a.suma(0, 1, 2);
	a.ver();
	b.suma(3, 1, 2);
	b.ver();

	system("pause");
	return 0;
}
