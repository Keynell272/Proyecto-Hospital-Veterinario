#include "vEspecialidades.h"

vEspecialidades::vEspecialidades(int n) : cantidad(0), tamano(n) {
	vec = new Especialidad * [n];
	for (int i = 0; i < n; i++) {
		vec[i] = nullptr;
	}
}
vEspecialidades::~vEspecialidades() {
	for (int i = 0; i < cantidad; i++) {
		delete vec[i];
	}
	delete[] vec;
}

void vEspecialidades::setCantidad(int cant) {
	cantidad = cant;
}
int vEspecialidades::getCantidad() {
	return cantidad;
}
Especialidad* vEspecialidades::getVec(int n) {
	// Convertimos n a índice de array (0-indexed)
	n = n - 1;
	
	if (n >= 0 && n < cantidad) {
		return vec[n];
	}

	imprimeCadena("Especialidad no encontrada.\n");
	return nullptr;
}

void vEspecialidades::agregarEspecialidad(Especialidad* esp) {
	if (cantidad < tamano) {
		vec[cantidad] = esp;
		cantidad++;
	}
	else {
		cout << "El Contenedor esta lleno" << endl;
	}
}

void vEspecialidades::imprimeContenedor() {
	for (int i = 0; i < cantidad; i++) {
		imprimeCadena("--->");imprimeEntero(i + 1);imprimeCadena("\n");
		imprimeCadena(vec[i]->toString());imprimeCadena("\n");
	}
}

void vEspecialidades::eliminarEspecialidadPorNombre(string nom) {
	for (int i = 0; i < cantidad; i++) {
		if (vec[i]->getEspecialidad() == nom) {
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
			cout << "Especialidad no encontrada." << endl;
		}
	}

}

bool vEspecialidades::estaVacio() {
	if (cantidad == 0) {
		return true;
	}
	else {
		return false;
	}
}
