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
		imprimeCadena("Especialidad agregada.\n");
	}
	else {
		imprimeCadena("El Contenedor esta lleno\n");
	}
}

void vEspecialidades::imprimeContenedor() {
	for (int i = 0; i < cantidad; i++) {
		imprimeCadena("--->");imprimeEntero(i);imprimeCadena("\n");
		imprimeCadena(vec[i]->toString());imprimeCadena("\n");	
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
