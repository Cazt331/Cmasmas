#include <iostream>

using namespace std;

class fraccion{
private:
	int numerador, denominador,sum1,aba1;
public:
	fraccion();
	fraccion(int, int);
	void leer();
	void ver();
	void suma(fraccion, fraccion);
	void resta(fraccion, fraccion);
	void multiplica(fraccion, fraccion);
	void divicion(fraccion, fraccion);
	void mcd(int, int);
	~fraccion();
};
fraccion::fraccion() {
	numerador = sum1 = aba1 = denominador = 0;
}
fraccion::fraccion(int _numerador,int _denominador) {
	numerador = _numerador;
	denominador = _denominador;
}
void fraccion::leer() {
	cout << "\n\tDigite el numerador: ";
	cin >> numerador;
	cout << "\tDigite el denominador: ";
	cin >> denominador;
}
void fraccion::suma(fraccion a,fraccion b) {
	sum1 = (a.numerador*b.denominador)+(b.numerador*a.numerador);
	aba1 = (b.denominador*b.denominador);
}
void fraccion::ver() {
	cout << "\n\tEl resultado es: " << sum1 << "/" << aba1 << endl;
	cout << "------------------------------------------------------------" << endl;
}
void fraccion::resta(fraccion a, fraccion b) {
	sum1 = (a.numerador*denominador) - (b.numerador*a.numerador);
	aba1 = (b.denominador*b.denominador);
}
void fraccion::multiplica(fraccion a, fraccion b) {
	sum1 = (a.numerador*b.numerador);
	aba1 = (b.denominador*b.denominador);
}
void fraccion::divicion(fraccion a, fraccion b) {
	sum1 = (a.numerador*b.denominador);
	aba1 = (a.denominador*b.numerador);
}
void mcd(int sum1, int aba1) {
	int r;
	while (aba1 != 0) {
		r = sum1 % aba1;
		sum1 = aba1;
		aba1 = r;
	}
}
fraccion::~fraccion() {
}
int main() {
	int i=0;
	while ( i<5 ) {
		cout << "\n\t1.-Suma de fracciones";
		cout << "\n\t2.-Resta de fracciones";
		cout << "\n\t3.-Multiplicacion de fracciones";
		cout << "\n\t4.-Divicion de fracciones";
		cout << "\n\t5.-Salir" << endl;
		cout << "\n\tSelecciona una opcion: ";
		cin >> i;
		if (i == 5) {
			return 0;
		}
		fraccion a(0, 0);
		a.leer();
		fraccion b(0, 0);
		b.leer();
		switch (i)
		{
		case 1:a.suma(a, b);
			a.ver();
			a.mcd(int a,int b);
			break;
		case 2:
			a.resta(a,b);
			a.ver();
			break;
		case 3:
			a.multiplica(a,b);
			a.ver();
			break;
		case 4:
			a.divicion(a,b);
			a.ver();
			break;
		}
	}
	return 0;
};
