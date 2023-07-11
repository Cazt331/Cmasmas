#include <stdio.h>
#include <iostream>

using namespace std;

void reducir(int nominador, int denominador) {
	if (denominador == 1) {
		cout << nominador <<endl;
	}
	else {
		int b = 2;
		while (b <= nominador) {
			if (denominador%b == 0 && nominador%b == 0) {
				denominador = denominador / b;
				nominador = nominador / b;
			}
			else {
				b++;
			}
		}
		if (denominador == 1) {
			cout << nominador << endl;
		}
		else {
			cout << nominador << "/" << denominador<<endl;
		}
	}
}

int main() {
	int n, d;
	n = d = 0;
	cout << "Coloca el primer valor: " << endl;
	cin >> n;
	cout << "Coloca el segundo valor: " << endl;
	cin >> d;
	reducir(n, d);
	system("pause");
	return 0;
}