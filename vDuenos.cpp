#include "vDuenos.h"

vDuenos::vDuenos(): cantidad(0) {
	for (int i = 0; i < cantidad; i++) {
		vec[i] = nullptr;
	}
}
vDuenos::~vDuenos() {
	for (int i = 0; i < cantidad; i++) {
		delete vec[i];
	}
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
		cout << vec[i]->toString() << endl;
	}
}

void vDuenos::eliminarDuenoPorNombre(string nom) {
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
			cout << "Dueno no encontrado." << endl;
		}
	}

}
