#include "vDoctores.h"

vDoctores::vDoctores() : cantidad(0) {
	vec = new Doctor * [100];
	for (int i = 0; i < 100; i++) {
		vec[i] = nullptr;
	}
}
vDoctores::~vDoctores() {
	for (int i = 0; i < cantidad; i++) {
		delete vec[i];
	}
	delete[]vec;
}

void vDoctores::agregarDoctor(Doctor* d) {
	if (cantidad < 100) {
		vec[cantidad] = d;
		cantidad++;
	}
	else {
		cout << "El Contenedor esta lleno" << endl;
	}
}

void vDoctores::imprimeContenedor() {
	for (int i = 0; i < cantidad; i++) {
		cout << vec[i]->toString() << endl;
	}
}

void vDoctores::eliminarDoctorPorNombre(string nom) {
	for (int i = 0; i < cantidad; i++) {
		if (vec[i]->getNombre() == nom) {
			delete vec[i];
			for (int j = i; j < cantidad - 1; ++j) {
				vec[j] = vec[j + 1];
			}
			vec[cantidad - 1] = nullptr;
			cantidad--;
		}
		else {
			cout << "Doctor no encontrado." << endl;
		}
	}

}
