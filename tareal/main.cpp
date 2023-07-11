//CONVERSIONES DE LA TEMPERATURA

#include<iostream>
#include<iomanip>
#include<math.h>

using namespace std;
void celkel();
void celfahr();
void fahrcel();
void farhkel();
void kelcels();
void kelfahr();

int main() {
	int selecc=0;
		while (selecc!=7) {
			cout << "\n\t1.-Grados Celsius a Fahrenheit";
			cout << "\n\t2.-Grados Celsius a Kelvin";
			cout << "\n\t3.-Grados Fahrenheit a Celsius";
			cout << "\n\t4.-Grados Fahrenheit a Kelvin";
			cout << "\n\t5.-Grados Kelvin a Celsius";
			cout << "\n\t6.-Grados Kelvin a Fahrenheit";
			cout << "\n\t7.-Salir" << endl;
			cout << "\n\tSelecciona un de las anteriores opcciones:";
			cin >> selecc;
			switch (selecc){
			case 1: celfahr(); break;
			case 2: celkel();  break;
			case 3: fahrcel(); break;
			case 4: farhkel(); break;
			case 5: kelcels(); break;
			case 6: kelfahr(); break;
			}

	}
	return 0;
}
void celkel() {
	float a,res;
	cout << "\n\tPoner el valor de grados celsius: "; cin >> a;
	res = a + 273.15;
	cout << "\n\tEl resultado es: " << res << " K";
	cout << "\n------------------------------------------------------"<<endl;
}
void celfahr() {
	float a, res;
	cout << "\n\tPoner el valor de grados Celsius: "; cin >> a;
	res = (((9 * a) / 5) + 32);
	cout << "\n\tEl resultado es: " << res << "F";
	cout << "\n------------------------------------------------------" << endl;
}
void fahrcel() {
	float a, res;
	cout << "\n\tPoner el valor de grados Fahrenheit: "; cin >> a;
	res = ((5*(a - 32)) / 9);
	cout << "\n\tEl resultado es: " << res << "C";
	cout << "\n------------------------------------------------------" << endl;
}
void farhkel() {
	float a, res;
	cout << "\n\tPoner el valor de grados Fahrenheit: "; cin >> a;
	res = (((5 * (a - 32)) / 9)+273.15);
	cout << "\n\tEl resultado es: " << res << "K";
	cout << "\n------------------------------------------------------" << endl;
}
void kelcels() {
	float a, res;
	cout << "\n\tPoner el valor de grados Kelvin: "; cin >> a;
	res = a-273.15;
	cout << "\n\tEl resultado es: " << res << "C";
	cout << "\n------------------------------------------------------" << endl;
}
void kelfahr() {
	float a, res;
	cout << "\n\tPoner el valor de grados Kelvin: "; cin >> a;
	res = (((9*(a-273.15))/5)+32);
	cout << "\n\tEl resultado es: " << res << "F";
	cout << "\n------------------------------------------------------" << endl;
}
