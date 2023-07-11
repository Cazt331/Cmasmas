#include <iostream>
//LUIS ALFREDO CASTILLO TIMOTEO

using namespace std;

class boleto {
	int precio;
	string pelicula;
	int sala;
public:
	boleto();
	boleto(int, string, int);
	void leer();
	void ver();
};
boleto::boleto() {
	precio = 0;
	pelicula = "";
	sala = 0;
}
boleto::boleto(int _precio, string _peli, int _sala) {
	precio = _precio;
	pelicula = _peli;
	sala = _sala;
}
void boleto::leer() {
	cout << "Poner el precio: ";
	cin >> precio;
	cout << "Nombre de la pelicula: ";
	getline(cin, pelicula, '\n');
	cout << "Numero de sala: ";
	cin >> sala;
}
void boleto::ver() {
	cout << precio << endl;
	cout << pelicula;
	cout << sala << endl;
}
class cinema {
	string direccion;
	int capacidad;
	string nombre;
public:
	cinema();
	cinema(string, int, string);
	void leer();
	void ver();
};
cinema::cinema() {
	direccion = "";
	capacidad = 0;
	nombre = "";
}
cinema::cinema(string _dire, int _capa, string _nombre) {
	direccion = _dire;
	capacidad = _capa;
	nombre = _nombre;
}
void cinema::leer() {
	cout << "poner la direccion: ";
	getline(cin, direccion, '\n');
	cout << "Colocar la capacidad: ";
	cin >> capacidad;
	cout << "Poner el nombre: ";
	getline(cin, nombre, '\n');
}
void cinema::ver() {
	cout << direccion << endl;
	cout << capacidad << endl;
	cout << nombre << endl;
}
class cliente :public boleto, cinema {
	string nombre;
	int entradas;
	string clientes;
public:
	cliente();
	cliente(int, string, int, string, int, string, string, int, string);
	void leer();
	void ver();
};
cliente::cliente(int _precio, string _peli, int _sala, string _dire, int _capa, string _nombre, string, int, string) :boleto(_precio, _peli, _sala), cinema(_dire, _capa, _nombre) {
	nombre = "";
	entradas = 0;
	clientes = "";
}
void cliente::leer() {
	boleto::leer();
	cinema::leer();
	cout << "Poner el nombre: ";
	getline(cin, nombre, '\n');
	cout << "Numero de entradas: ";
	cin >> entradas;
	cout << "Tipo de cliente: ";
	getline(cin, clientes, '\n');
	cin.ignore(255, '\n');
}
void cliente::ver() {
	boleto::ver();
	cinema::ver();
	cout << nombre << endl;
	cout << entradas << endl;
	cout << clientes << endl;
}
int main() {
	int n,i=0;
	cout << "Poner el valor de personas a registrar: ";
	cin >> n;
	for (i = 0; i < n; i++) {
		cliente b[i];
		b[i].leer();
	}

	cliente b;
	b.leer();
	b.ver();
	return 0;
}