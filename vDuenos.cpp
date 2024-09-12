#include "vDuenos.h"

vDuenos::vDuenos(int n): cantidad(0), tamano(n) {
	vec = new Dueno * [n];
	for (int i = 0; i < n; i++) {
		vec[i] = nullptr;
	}
}
vDuenos::~vDuenos() {
	for (int i = 0; i < cantidad; i++) {
		delete vec[i];
	}
	delete[] vec;
}

void vDuenos::setCantidad(int cant) {
	cantidad = cant;
}
int vDuenos::getCantidad() {
	return cantidad;
}
Dueno* vDuenos::getVec(int n) {
	// Convertimos n a índice de array (0-indexed)
	n = n - 1;

	if (n >= 0 && n < cantidad) {
		return vec[n];
	}

	imprimeCadena("Dueno no encontrado.\n");
	return nullptr;
}

void vDuenos::agregarDueno(Dueno* d) {
	if (cantidad < 100) {
		vec[cantidad] = d;
		cantidad++;
	}
	else {
		cout << "El Contenedor esta lleno" << endl;
	}
}

void vDuenos::imprimeContenedor() {
	for (int i = 0; i < cantidad; i++) {
		imprimeCadena("--->");imprimeEntero(i + 1);imprimeCadena("\n");
		imprimeCadena(vec[i]->toString());imprimeCadena("\n");
	}
}

void vDuenos::eliminarDuenoPorNombre(string nom) {
	for (int i = 0; i < cantidad; i++) {
		if (vec[i]->getNombre() == nom) {
			delete vec[i];
			vec[i] = nullptr;
			for (int j = i; j < cantidad - 1; ++j) {
				vec[j] = vec[j + 1];
			}
			vec[cantidad - 1] = nullptr;
			cantidad--;
			return;
		}
		else {
			cout << "Dueno no encontrado." << endl;
		}
	}

}

bool vDuenos::estaVacio() {
	if (cantidad == 0) {
		return true;
	}
	else {
		return false;
	}
}
