#include "vMascotas.h"

vMascotas::vMascotas() : cantidad(0), tamano(100) {
	vec = new Mascota * [100];
	for (int i = 0; i < 100; i++) {
		vec[i] = nullptr;
	}
}
vMascotas::~vMascotas() {
	for (int i = 0; i < cantidad; i++) {
		delete vec[i];
	}
	delete[]vec;
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
		cout << vec[i]->toString() << endl;
	}
}

void vMascotas::eliminarMascotaPorNombre(string nom) {
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
			cout << "Mascota no encontrada." << endl;
		}
	}

}
