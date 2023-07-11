#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
//#include "constud.h"

using namespace std;
#define horizontal 196
#define vertical 179
#define edersup 191
#define ederinf 217
#define eizqsup 218
#define eizqinf 192

using namespace std;
void setattr(int BackC, int texto);
void clrScreen()
{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coordScreen = { 0, 0 };    // home for the cursor
	DWORD cCharsWritten;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD dwConSize;

	// Get the number of character cells in the current buffer.
	if (!GetConsoleScreenBufferInfo(hConsole, &csbi))
	{
		return;
	}
	dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
	// Fill the entire screen with blanks.
	if (!FillConsoleOutputCharacter(hConsole,        // Handle to console screen buffer
		(TCHAR) ' ',     // Character to write to the buffer
		dwConSize,       // Number of cells to write
		coordScreen,     // Coordinates of first cell
		&cCharsWritten))// Receive number of characters written
	{
		return;
	}
	// Get the current text attribute.
	if (!GetConsoleScreenBufferInfo(hConsole, &csbi))
	{
		return;
	}
	// Set the buffer's attributes accordingly.
	if (!FillConsoleOutputAttribute(hConsole,         // Handle to console screen buffer
		csbi.wAttributes, // Character attributes to use
		dwConSize,        // Number of cells to set attribute
		coordScreen,      // Coordinates of first cell
		&cCharsWritten)) // Receive number of characters written
	{
		return;
	}
	SetConsoleCursorPosition(hConsole, coordScreen);
}
void gotoxy(int x, int y) {
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}

void recuadroD(int izq, int sup, int der, int inf, char *c) {
	int i;
	gotoxy(der, sup); cout << (char)(c[1]);
	gotoxy(der, inf);  cout << (char)(c[3]);
	gotoxy(izq, inf);  cout << (char)(c[4]);
	gotoxy(izq, sup);  cout << (char)(c[5]);
	for (i = izq + 1; i < der; ++i) {
		gotoxy(i, sup);  cout << (char)(c[0]);
		gotoxy(i, inf);  cout << (char)(c[0]);
	}
	for (i = sup + 1; i < inf; ++i) {
		gotoxy(izq, i);  cout << (char)(c[2]);
		gotoxy(der, i);  cout << (char)(c[2]);
	}
	return;
}
void recuadroS(int izq, int sup, int der, int inf, int relleno, int color) {
	int i, j;
	gotoxy(der, sup); cout << (char)(edersup);
	gotoxy(der, inf);  cout << (char)(ederinf);
	gotoxy(izq, inf);  cout << (char)(eizqinf);
	gotoxy(izq, sup);  cout << (char)(eizqsup);
	for (i = izq + 1; i < der; ++i) {
		gotoxy(i, sup);  cout << (char)(horizontal);
		gotoxy(i, inf);  cout << (char)(horizontal);
	}
	for (i = sup + 1; i < inf; ++i) {
		gotoxy(izq, i);  cout << (char)(vertical);
		gotoxy(der, i);  cout << (char)(vertical);
	}
	if (relleno == 1) {
		setattr(color, 0);
		for (j = sup + 1; j < inf; j++)
			for (i = izq + 1; i < der; ++i) {
				gotoxy(i, j);  cout << (char)(' ');
			}
	}
	return;
}
void setattr(int BackC, int texto)
{
	WORD wColor = ((BackC & 0x0F) << 4) | texto;
	//Get the handle to the current output buffer...
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, wColor);
	return;
}
#define MAXUSUARIOS 25
#define Acces 4

char nomarch1[50] = "Acceso.dat";
fstream usuarios2;
int leerregistro(char cuenta[], int *nip) {
	char loccuenta[100];
	usuarios2.open(nomarch1, ios::in);
	while (!usuarios2.eof()) {
		usuarios2 >> loccuenta;
		usuarios2 >> *nip;
		if (strstr(loccuenta, cuenta)) {
			usuarios2.close();
			return 1;
		}
	}
	usuarios2.close();
	return 0;
}
int leerregistro1(char cuenta[], int *nip) {
	char loccuenta[100];
	usuarios2.open(nomarch1, ios::in);
	while (!usuarios2.eof()) {
		usuarios2 >> *nip;
		usuarios2 >> loccuenta;
		if (strstr(loccuenta, cuenta)) {
			usuarios2.close();
			return 1;
		}
	}
	usuarios2.close();
	return 0;
}
class seleccion {
	char *cuentas[Acces];
	int   nips[Acces];
	int n;
public:
	seleccion() {
		for (int i = 0; i < Acces; i++) {
			cuentas[i] = NULL;
			nips[0] = 0;
		}
	}
};
char nomarch[100] = "usuarios.dat";
fstream usuarios;
class seguridad {
	char *cuentas[MAXUSUARIOS];
	int   nips[MAXUSUARIOS];
	int n;
public:
	seguridad() {
		for (int i = 0; i < MAXUSUARIOS; i++) {
			cuentas[i] = NULL;
			nips[0] = 0;
		}
	}
	void registra(char cuenta[], int nip) {
		usuarios.open(nomarch, ios::out | ios::app);
		usuarios << std::setfill('0') << setw(16) << cuenta << " " << setw(4) << nip << "\n";
		usuarios.close();
	}
	int leerregistro(char cuenta[], int *nip) {
		char loccuenta[100];
		usuarios.open(nomarch, ios::in);
		while (!usuarios.eof()) {
			usuarios >> loccuenta;
			usuarios >> *nip;
			if (strstr(loccuenta, cuenta)) {
				usuarios.close();
				return 1;
			}
		}
		usuarios.close();
		return 0;
	}

	int modificaRegistro(char cuenta[], int *nip, int nuevonip) {
		char loccuenta[100];
		long int pos;
		usuarios.open(nomarch, ios::in | ios::out);
		while (!usuarios.eof()) {
			pos = usuarios.tellg();
			usuarios >> loccuenta;
			usuarios >> *nip;
			if (strstr(loccuenta, cuenta)) {
				usuarios.seekg(pos, ios::beg);
				usuarios << std::setfill('0') << setw(16) << cuenta << " " << setw(4) << nuevonip << "\n";
				usuarios.close();
				return 1;
			}
		}
		usuarios.close();
		return 0;
	}
	int consultarRegistro(char cuenta[]) {
		char loccuenta[100];
		long int pos;
		int nip;
		usuarios.open(nomarch, ios::in | ios::out);
		while (!usuarios.eof()) {
			usuarios >> loccuenta;
			usuarios >> nip;
			if (strstr(loccuenta, cuenta)) {
				gotoxy(45, 17);
				setattr(1, 7); //azul, blanco
				cout << "Su NIP es:      ";
				recuadroS(45, 18, 60, 20, 0, 7);
				gotoxy(46, 19);
				cout << cuenta << " " << nip << " " << "\n";
				usuarios.close();
				return 1;
			}
		}
		usuarios.close();
		return 0;
	}
	int menu() {
		char cuenta[100], usuario[20];
		int opc, nipu, nip;
		while (1) {
			setattr(1, 3);
			recuadroS(10, 8, 40, 20, 1, 3);
			setattr(3, 1);
			gotoxy(11, 10);
			cout << "1.- Registrar Usuario" << endl;
			gotoxy(11, 11);
			cout << "2.- Dar de Baja a Usuario" << endl;
			gotoxy(11, 12);
			cout << "3.- Modificar Cuenta, NIP" << endl;
			gotoxy(11, 13);
			cout << "4.- Modificar Usuario" << endl;
			gotoxy(11, 14);
			cout << "5.- Consultar Cuenta" << endl;
			gotoxy(11, 15);
			cout << "6.- Consultar Usuario" << endl;
			gotoxy(11, 16);
			cout << "7.- Salir" << endl;
			gotoxy(12, 18);
			cout << "Opcion:";
			cin >> opc;
			cin.ignore();
			switch (opc) {
			case 1:
				clrScreen();
				gotoxy(11, 12);
				cout << "Usuario:";
				cin >> usuario;
				gotoxy(11, 13);
				cout << "NIP:";
				cin >> nipu;
				registra(usuario, nipu);
				clrScreen();
				system("color 0F");
				break;
			case 2:

				break;
			case 3:
				clrScreen();
				gotoxy(11, 12);
				cout << "Usuario:";
				cin >> usuario;
				gotoxy(11, 13);
				cout << "NIP:";
				cin >> nipu;
				modificaRegistro(usuario, &nip, nipu);
				clrScreen();
				system("color 0F");
				break;
			case 5:
				clrScreen();
				gotoxy(10, 13);
				cout << "Usuario:";
				cin >> usuario;
				consultarRegistro(usuario);
				cin.ignore(255, '\n');
				cin.get();
				clrScreen();
				system("color 0F");
				break;
			case 7:
				clrScreen();
				gotoxy(80 / 2 - strlen("Adios") / 2, 13);
				setattr(1, 7);
				cout << "  |  SALIENDO  | " << endl;
				Sleep(1500);
				clrScreen();
				system("color 0F");
				return 1;
			}
		}
		return 0;
	}
	int menu2() {
		char cuenta[100], usuario[20];
		int opc, nipu, nip;
		while (1) {
			clrScreen();
			setattr(1, 3);
			recuadroS(10, 8, 40, 20, 1, 3);
			setattr(3, 1);
			gotoxy(11, 10);
			cout << "1.- Modificar Cuenta, NIP" << endl;
			gotoxy(11, 11);
			cout << "2.- Consultar Cuenta" << endl;
			gotoxy(11, 12);
			cout << "3.- Consultar Usuario" << endl;
			gotoxy(11, 13);
			cout << "4.- Salir" << endl;
			gotoxy(12, 15);
			cout << "Opcion:";
			cin >> opc;
			cin.ignore(1);
			clrScreen();
			system("color 0F");
			switch (opc) {
			case 1:
				clrScreen();
				gotoxy(11, 12);
				cout << "Usuario:";
				cin >> usuario;
				gotoxy(11, 13);
				cout << "NIP:";
				cin >> nipu;
				modificaRegistro(usuario, &nip, nipu);
				clrScreen();
				system("color 0F");
				break;
			case 2:
				clrScreen();
				gotoxy(10, 13);
				cout << "Usuario:";
				cin >> usuario;
				consultarRegistro(usuario);
				cin.ignore(255, '\n');
				cin.get();
				clrScreen();
				system("color 0F");
				break;
			case 3:
				break;
			case 4:
				clrScreen();
				gotoxy(80 / 2 - strlen("Adios") / 2, 13);
				setattr(1, 7);
				cout << "  |  SALIENDO  | " << endl;
				Sleep(1500);
				clrScreen();
				system("color 0F");
				return 1;
			}
		}
		return 0;
	}
};

int main() {
	char cuenta[100], usario[20];
	int nipu, nip;
	int i = 0;
	while (1) {
		clrScreen();
		int opc, s;
		setattr(1, 3);
		recuadroS(10, 8, 40, 20, 1, 3);
		setattr(3, 1);
		gotoxy(11, 10);
		cout << "1.- Acceso a supervisores" << endl;
		gotoxy(11, 11);
		cout << "2.- Acceso a empleados" << endl;
		gotoxy(11, 12);
		cout << "3.- Salir" << endl;
		gotoxy(12, 15);
		cout << "Opcion:";
		cin >> opc;
		cin.ignore(1);
		clrScreen();
		system("color 0F");
		if (opc == 1) {
			while (i < 3) {
				clrScreen();
				cout << "NIP: ";
				cin >> nipu;
				if (leerregistro("jaime", &nip)) {
					if (nip == nipu) {
						cout << "Clave: ";
						cin >> nipu;
						cin.ignore(255, '\n');
						if (leerregistro1("jaime", &nip)) {
							if (nip == nipu) {
								clrScreen();
								seguridad s;
								s.menu();
							}
						}
					}
				}
				cout << "NIP Incorrecto " << endl;
				i++;
			}
		}
		else if (opc == 2) {
			seguridad s;
			s.menu2();
		}
		else if (opc == 3) {
			clrScreen();
			gotoxy(80 / 2 - strlen("Adios") / 2, 13);
			setattr(1, 7);
			cout << "Adios" << endl;
			Sleep(1000);
			return 1;
		}
	}
}
