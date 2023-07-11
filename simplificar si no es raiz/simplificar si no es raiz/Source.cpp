#include<iostream>
#include<math.h>

using namespace std;
float raiz(float a);

int main() {
	int ra,c;//c es la raiz
	cout << "poner el valor";
	cin >> c;
	raiz(c);
	if (raiz(c) == 0) {
		cout << "no hay raiz entera:" << c;//no hay raiz
	}
	else if (raiz(c) != 0) {
		ra=raiz(c);
		cout << ra;//si hay raiz
	}
	system("pause");
	return 0;
}
float  raiz(float a) {
	int x;
	float y;
	a = pow(a, 0.5);
	x = a;
	y = x - a;
	if (y == 0) {
		return a;
	}
	else {
		return 0;
	}
}