#include "vDoctores.h"

vDoctores::vDoctores(int n) : cantidad(0), tamano(n) {
	vec = new Doctor * [n];
	for (int i = 0; i < n; i++) {
		vec[i] = nullptr;
	}
}
vDoctores::~vDoctores() {
	for (int i = 0; i < cantidad; i++) {
		delete vec[i];
	}
	delete[] vec;
}

void vDoctores::setCantidad(int cant) {
	cantidad = cant;
}
int vDoctores::getCantidad() {
	return cantidad;
}
Doctor* vDoctores::getVec(int n) {
	
	if (n >= 0 && n < cantidad) {
		return vec[n];
	}

	imprimeCadena("Doctor no encontrado.\n");
	return nullptr;
}

void vDoctores::agregarDoctor(Doctor* d) {
	if (cantidad < tamano) {
		vec[cantidad] = d;
		cantidad++;
		imprimeCadena("Doctor agregado.\n");
	}
	else {
		imprimeCadena("El Contenedor esta lleno.\n");
	}
}

void vDoctores::imprimeContenedor() {
	for (int i = 0; i < cantidad; i++) {
		imprimeCadena("--->");imprimeEntero(i);imprimeCadena("\n");
		imprimeCadena(vec[i]->toString());imprimeCadena("\n");
	}
}

string vDoctores::doctoresPorEspecialidad(string esp) {
	stringstream s;
	for (int i = 0; i < cantidad; i++) {
		if (esp == vec[i]->getEspecialidad()->getEspecialidad()) {
			s << "-->" << i << endl << vec[i]->toString() << endl;

		}
	}
	return s.str();
}

bool vDoctores::estaVacio() {
	if (cantidad == 0) {
		return true;
	}
	else {
		return false;
	}
}

bool vDoctores::tieneEspecialidad(Especialidad* esp) {
	for (int i = 0; i < cantidad;i++) {
		if (esp->getEspecialidad() == vec[i]->getEspecialidad()->getEspecialidad()) {
			return true;
		}
	}
	return false;
}

int vDoctores::cantidadDoctoresPorEspecialidad(string espPos) {
	int cant = 0;
	for (int i = 0; i < cantidad; i++) {
		if (espPos == vec[i]->getEspecialidad()->getEspecialidad()) {
			cant++;
		}
	}
	return cant;
}

bool vDoctores::verificarPosicion(string espPos, int docPos) {
	int* posicionesValidas = new int[cantidadDoctoresPorEspecialidad(espPos)];
	int contador = 0;
	for (int i = 0;i < cantidad; i++) {
		if (espPos == vec[i]->getEspecialidad()->getEspecialidad()) {
			if (contador < cantidadDoctoresPorEspecialidad(espPos)) {
				posicionesValidas[contador] = i;
				contador++;
			}
		}
	}
	for (int i = 0;i < cantidadDoctoresPorEspecialidad(espPos);i++) {
		if (docPos == posicionesValidas[i]) {
			delete[] posicionesValidas;
			return true;
		}
	}
	delete[] posicionesValidas;
	return false;
}

