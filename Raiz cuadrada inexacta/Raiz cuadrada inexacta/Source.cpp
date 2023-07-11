#include<iostream>

using namespace std;

int main() {
	int i, n, nume,a,r=0,cont,raiz;
	cout << "ingrese un numero: ";
	cin >> nume;
	for (i = 0; r < nume; i++) {
		a = i;
		r = a * a;
	}
	a = a - 1;
	r = a * a;
	raiz = nume - r;
	cout << "El resultado es " << a <<" sqrt("<<raiz<<")";
	system("pause");
	return 0;
}