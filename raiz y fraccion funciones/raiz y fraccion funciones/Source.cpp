#include<iostream>
#include<math.h>

using namespace std;
//int reducirfraccion(int numerador, int denominador);
float raiz(float c);

int main() {
	float a = 0,b=0,c=0;
	cout << "coloca un numerador: ";
	cin >> a;
	//cout << "coloca el denominador: ";
	//cin >> b;
	raiz(a);
	system("pause");
	return 0;
}
float raiz(float c) {
	int x;
	float y;
	x = c;
	y = x - c;
	if (y == 0) {
		c = sqrt(c);
		cout << c<<"efe";
		return c;
	}
	else {
		cout << c;
		return c;
	}
}
/*int reducirfraccion(int numerador, int denominador) {
	if (denominador == 1) {
		cout << numerador <<"1"<< endl;
		return numerador;
	}
	else {
		int b = 2;
		while (b <= numerador) {
			if (denominador%b == 0 && numerador%b == 0) {
				denominador = denominador / b;
				numerador = numerador / b;
			}
			else {
				b++;
			}
			if (denominador == 1) {
				cout << numerador << endl;
				return 0;
			}
			else if (numerador == denominador) {
				cout << "Es igual a 1";
				return 0;
			}
			else if (denominador != 1) {
				cout << numerador << "/" << denominador << endl;
				return 0;
			}
		}
	}
}*/