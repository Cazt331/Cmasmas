#include<iostream>
#include<iomanip>

using namespace std;

struct Alumno {
	char nombre[50];
	unsigned long boleta;
};
class Grupo {
	Alumno *grupo;
	int n;
public:
	Grupo();
	Grupo(int);
	void reset();
	void leer();
	void ver(int);
	Grupo::Grupo() {
		grupo = NULL;
		n = 0;
	}
	Grupo::Grupo(int cuantos) {
		grupo = new Alumno[cuantos];
		n = cuantos;
	}
	void Grupo :: reset (){
		int i;
		for (i = 0; i < n; i++) {
			*grupo[i].nombre = '0';
			grupo[i].boleta = 0;
		}
	}

};
void Grupo::leer() {
	for (int i = 0; i < n; i++) {
		if (!*grupo[i].nombre) {
			fflush(stdin);
			cout << "Nombre: ";
			cin.getline(grupo[i].nombre, 50, '/n');
			cout << "Boleta: ";
			cin >> grupo[i].boleta;
			return i;
		}
		return 0;
	}
}
void Grupo::ver(int i) {
	cout << "Nombre: " << grupo[i].nombre << endl;
	cout << "Boleta: " << grupo[i].boleta << endl;
}
void Grupo::libera() {
	delete[]grupo;
}
void Grupo::ver() {
	for (int i = 0; i < n; i++) {
		if (*grupo[i].nombre)
			ver(i);
	}
}

int main() {
	Grupo_2AM5(30);
	-2AM5.reset();
	-2AM5.leer();
	-2AM5.leer();
	-2AM5.ver();
	-2AM5.libera();

	return 1;
}