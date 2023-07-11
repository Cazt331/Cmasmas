#include <iostream>
#include<math.h>

using namespace std;
void general(float discr, float a, float b);
void cero(float b, float a);
void imaginario(float a, float b, float c);
float raizimag(float a);
//int reducirfraccion(int nominador, int denominador);

int main() {
	float a, b, c, discr, elecc = 3;
	while (elecc != 0) {
		cout << "\n\tColoca el valor de A: "; cin >> a;
		cout << "\tColoca el valor de B: "; cin >> b;
		cout << "\tColoca el valor de C: "; cin >> c;
		cout << "-----------------------------------------------";
		if (a == 0) {
			cout << "\n\n\tNo existe solucion real" << endl;
			cout << "\n-----------------------------------------------" << endl;
		}
		discr = (pow(b, 2) - (4 * a*c));
		if (discr > 0) {
			general(discr, a, b);
		}
		else if (discr == 0) {
			cero(b, a);
		}
		else if (discr < 0) {
			imaginario(a, b, c);
		}
		cout << "Quieres resolver otra ecuacion";
		cout << "\nSI digita un 1";
		cout << "\nNO dita un 0: "; cin >> elecc;
	}
	return 0;
}
void general(float discr, float a, float b) {
	float form1, form2, valabs1 = 0, valabs2 = 0, arri1, arri2;
	arri1 = ((-1 * b) + (sqrt(discr)));
	arri2 = ((-1 * b) - (sqrt(discr)));
	form1 = (arri1 / (2 * a));
	form2 = (arri2 / (2 * a));
	if (arri1 == 0) {
		cout << "\n\n\tEl primer resultado es: 0";
		cout << "\n\tEl segundo resultado es: " << form2 << endl;
		cout << "\n-----------------------------------------------" << endl;
	}
	else if (arri2 == 0) {
		cout << "\n\n\tEl primer resultado es: " << form1;
		cout << "\n\tEl segundo resultado es: 0" << endl;
		cout << "\n-----------------------------------------------" << endl;
	}
	else if (form1 != 0 || form2 != 0) {
		cout << "\n\n\tEl primer resultado es1: " << form1;
		cout << "\n\tEl segundo resultado es2: " << form2 << endl;
		cout << "\n-----------------------------------------------" << endl;
	}
	else if (form1 == 0) {
		valabs1 = abs(form1);
		cout << "\n\n\tEl primer resultado es: " << valabs1;
		cout << "\n\tEl segundo resultado es: " << form2 << endl;
		cout << "\n-----------------------------------------------" << endl;
	}
	else if (form2 == 0) {
		cout << "\n\n\tEl primer resultado es: " << form1;
		cout << "\n\tEl segundo resultado es: " << valabs2 << endl;
		cout << "\n-----------------------------------------------" << endl;
	}
}
void cero(float b, float a) {
	float form1=0, valabs=0;
	b=(-1*b);
	if (b < 0) {
		form1 = ((b) / (2 * a));
		cout << "\n\n\tEl resultado es: " << form1 << endl;
		cout << "\n-----------------------------------------------" << endl;
	}
	form1 = (-1*(b / (2 * a)));
	if (form1 == 0) {
		valabs = abs(form1);
		cout << "\n\n\tEl resultado es: " << valabs << endl;
		cout << "\n-----------------------------------------------" << endl;
	}
}
void imaginario(float a, float b, float c) {
	float form1, raiz1 = 0, abaj, ra;
	raiz1 = abs(((b*b) - (4 * a * c)));
	raizimag(raiz1);
	ra = raizimag(raiz1);
	abaj = (2 * a);
	form1 = ((-1 * b) / abaj);
	if (ra== 0) {
		raiz1 = raiz1;//no hay raiz
		cout << "\n\n\tEl primer resultado es2: " << form1 << "+" <<"sqrt("<< raiz1 <<")"<< "i" << "/" << abaj;
		cout << "\n\tEl segundo resultado es: " << form1 << "-" << "sqrt("<<raiz1 <<")"<< "i" << "/" << abaj << endl;
		cout << "\n-----------------------------------------------" << endl;
	}
	else if (ra != 0) {
		raiz1 = ra;//si hay raiz
		cout << "\n\n\tEl primer resultado es2: " << form1 << "+" << raiz1 << "i" << "/" << abaj;
		cout << "\n\tEl segundo resultado es: " << form1 << "-" << raiz1 << "i" << "/" << abaj << endl;
		cout << "\n-----------------------------------------------" << endl;
	}
}
float  raizimag(float a) {
	int x;
	float y;
	a = pow(a, 0.5);
	x = a;
	y = x - a;
	if (y == 0) {
		cout << a;
		return a;
		exit;
	}
	else if( y!=0 ){
		return 0;
	}
	return 0;
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
}
*/