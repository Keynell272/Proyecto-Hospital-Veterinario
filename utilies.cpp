#include "utiles.h"

void imprimeCadena(string cadena) {
	cout << cadena;
}

string leerCadena() {
	string x;
	getline(cin, x);
	return x;
}

int leerEntero() {
	int n;
	bool continuar = true;
	while (true) {
		if (cin >> n) {
			cin.clear(); // Limpia el estado del flujo..
			cin.ignore(1024, '\n');
			return n;
		}
		else {
			cerr << "Valor incorrecto.. digita UN NUMERO" << endl;
			cin.clear();
			cin.ignore(1024, '\n');
		}
	}

}

void limpiaPantalla() {
	system("cls");
}

void esperandoEnter() {
	cin.get();
}
