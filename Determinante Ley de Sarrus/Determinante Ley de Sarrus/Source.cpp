#include<iostream>
#include<math.h>

using namespace std;
void leer();
float sarrus[2][3];
float sarrus1();

int main() {
	float a, b, c;
	a = b = c = 0;
	leer();
	sarrus1();

	system("pause");
	return 0;
}
void leer() {
	cout << "coloca los valores de las ecuaciones "<<endl;
	for (int j = 0; j < 3; j++) {
		for (int i = 0; i < 4; i++) {
			cout << i + 1 << ".-" << "valor: "; cin >> sarrus[j][i];
		}
		cout << endl;
	}

}
float sarrus1() {
	float A=0,B=0,C=0;
	A = (sarrus[3][1] * sarrus[2][2] * sarrus[1][3]) + (sarrus[3][2] * sarrus[2][3] * sarrus[1][1]) + (sarrus[3][3] * sarrus[2][1] * sarrus[1][2]);
	B = (sarrus[1][1] * sarrus[2][2] * sarrus[3][3]) + (sarrus[2][1] * sarrus[2][3] * sarrus[3][1]) + (sarrus[3][1] * sarrus[2][1] * sarrus[3][2]);
	cout << A << endl;
	cout << B << endl;//esta mal todo esto
	C = A - B;
	cout << C << endl;
	return 0;
}