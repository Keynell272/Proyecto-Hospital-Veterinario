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

	if (n >= 0 && n < cantidad) {
		return vec[n];
	}

	imprimeCadena("Dueno no encontrado.\n");
	return nullptr;
}

void vDuenos::agregarDueno(Dueno* d) {
	if (cantidad < tamano) {
		vec[cantidad] = d;
		cantidad++;
	}
	else {
		imprimeCadena("El Contenedor esta lleno.\n");
	}
}

void vDuenos::imprimeContenedor() {
	for (int i = 0; i < cantidad; i++) {
		imprimeCadena("--->");imprimeEntero(i);imprimeCadena("\n");
		imprimeCadena(vec[i]->toString());imprimeCadena("\n");
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

bool vDuenos::verificarID(int _id) {
	for (int i = 0;i < cantidad; i++) {
		if (_id == vec[i]->getID()) {
			return true;
		}
	}
	return false;
}
