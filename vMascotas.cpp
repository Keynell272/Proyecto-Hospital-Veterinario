#include "vMascotas.h"

vMascotas::vMascotas(int n) : cantidad(0), tamano(n) {
	vec = new Mascota * [n];
	for (int i = 0; i < n; i++) {
		vec[i] = nullptr;
	}
}
vMascotas::~vMascotas() {
	for (int i = 0; i < cantidad; i++) {
		delete vec[i];
	}
	delete[] vec;
}

void vMascotas::setCantidad(int cant) {
	cantidad = cant;
}
int vMascotas::getCantidad() {
	return cantidad;
}
Mascota* vMascotas::getVec(int n) {
	// Convertimos n a índice de array (0-indexed)
	n = n - 1;

	if (n >= 0 && n < cantidad) {
		return vec[n];
	}

	imprimeCadena("Mascota no encontrada.\n");
	return nullptr;
}

void vMascotas::agregarMascota(Mascota* m) {
	if (cantidad < 100) {
		vec[cantidad] = m;
		cantidad++;
	}
	else {
		cout << "El Contenedor esta lleno" << endl;
	}
}

void vMascotas::imprimeContenedor() {
	for (int i = 0; i < cantidad; i++) {
		imprimeCadena("--->");imprimeEntero(i + 1);imprimeCadena("\n");
		imprimeCadena(vec[i]->toString());imprimeCadena("\n");
	}
}

void vMascotas::eliminarMascotaPorNombre(string nom) {
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
			cout << "Mascota no encontrada." << endl;
		}
	}

}


bool vMascotas::estaVacio() {
	if (cantidad == 0) {
		return true;
	}
	else {
		return false;
	}
}
