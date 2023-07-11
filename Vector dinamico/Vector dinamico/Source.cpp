#include <iostream>

using namespace std;
class Vector {
	double *v;
	int n;
public:
	Vector();
	Vector(int tam);
	Vector(int, int, int);
	Vector(double, double, double);
	Vector operator+(Vector a);
	void ver();
	void libera();
};
Vector::Vector() {
	v = NULL;
	n = 0;
}
Vector::Vector(int tam) {
	v = new double[tam];
	n = tam;
	for (int i = 0; i < n; i++)
		v[i] = 0;
}

Vector::Vector(int a, int b, int c) {
	v = new double[3];
	v[0] = a; //*v=a
	v[1] = b; //*(v+1)=b
	v[2] = c; //*(v+2)=c
	n = 3;
}
Vector::Vector(double a, double b, double c) {
	v = new double[3];
	v[0] = a;
	v[1] = b;
	v[2] = c;
	n = 3;
}

Vector Vector::operator+(Vector a) {
	Vector t(n);

	for (int i = 0; i < n; i++)
		t.v[i] = v[i] + a.v[i];

	return t;
}
void Vector::ver() {
	for (int i = 0; i < n; i++)
		cout << v[i] << " ";
	cout << endl;
}
void Vector::libera() {
	delete[] v;
}
class Matrix {
	Vector **a;
	int n, m;
public:
	Matrix();
	Matrix(int, int);
	void ver();
};
Matrix::Matrix() {
	n = m = 0;
	a = NULL;
}
Matrix::Matrix(int f, int c) {
	n = f;
	m = c;
	*a = new Vector[n];// direcs de las filas
	for (int i = 0; i < n; i++)
		a[i] = new Vector(m); //asigno memoria a cada fila de tam m
}
void Matrix::ver() {
	for (int i = 0; i < n; i++)
		a[i]->ver();
}
int main()
{/*
	Vector a(1,2,3);
	Vector b(3,2,1);
	Vector c;

	c=a+b;
	a.ver();
	b.ver();
	cout<<"------"<<endl;
	c.ver();

	a.libera();
	b.libera();
	c.libera();
*/
	Matrix a(3, 3);

	a.ver();
	return 0;
}
