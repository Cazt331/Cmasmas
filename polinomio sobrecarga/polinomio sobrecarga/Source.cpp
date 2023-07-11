#include <iostream>

using namespace std;

class Polinomio {
	double *coef;
	int    *expo;
	int n,cant;
public:
	Polinomio();
	Polinomio(int tam);
	void leer();
	void ver();
	Polinomio operator+(Polinomio a);
	//void libera();
	~Polinomio();
};
Polinomio::Polinomio() {
	coef = NULL;
	expo = NULL;
	n = cant = 0;
}
Polinomio::Polinomio(int tam) {
	coef = new double[tam];
	expo = new int[tam];
	n = tam;
	for (int i = 0; i < n; i++) {
		coef[i] = 0;
		expo[i] = 0;
	}
}
void Polinomio::leer() {
	for (int i = 0; i < n; i++) {
		cant = cant + 1;
		cout << "Coeficiente del Monomio (" << cant << ")" << endl;
		cout << "coef[" << i << "]=";
		cin >> coef[i];
		expo[i] = i;
	}
}
void Polinomio::ver() {
	for (int i = 0; i < n; i++)
		if (coef[i] != 0)
			cout << coef[i] << "x^" << expo[i] << " ";
	cout << endl;
}
Polinomio Polinomio::operator+(Polinomio a) {
	Polinomio p(n * 2);
	int kp;
	for (int i = kp = 0; i < n; i++) {
		p.coef[i] = coef[i] + a.coef[i];
		p.expo[i] = expo[i];
	}
	return p;
}
/*void Polinomio::libera() {
	delete[] coef;
	delete[] expo;
}*/
Polinomio::~Polinomio() {
}
int main()
{
	int tam1=0;
	cout << "Cantidad de monomios a ingresar: ";
	cin >> tam1;
	Polinomio a(tam1);
	Polinomio b(tam1);
	Polinomio c(tam1);
	cout << "Introduzca los coeficientes y exponentes en orden ascendente" << endl;
	cout << "Como se indica a continuacion:" << endl;
	cout << "Ax^0+Bx^1+Cx^2+Dx^...+Zx^(n-1)" << endl;
	cout << "coef[i]=A,B,D,...Z para i=0,1,2,...(n-1)" << endl;
	cout << endl;
	a.leer();
	b.leer();

	c = a + b;

	a.ver();
	b.ver();
	cout << "----------------" << endl;
	c.ver();
	//a.libera();
	//b.libera();
	//c.libera();
	system("pause");
	return 0;
}
