#include "vEspecialidades.h"

vEspecialidades::vEspecialidades() {
	for (int i = 0; i < cantidad; i++) {
		vec[i] = nullptr;
	}
}
vEspecialidades::~vEspecialidades() {
	for (int i = 0; i < cantidad; i++) {
		delete vec[i];
	}
}

void vEspecialidades::agregarEspecialidad(Especialidad& esp) {
	if (cantidad < 100) {
		vec[cantidad] = (Especialidad*)&esp;
		cantidad++;
	}
	else {
		cout << "El Contenedor esta lleno" << endl;
	}
}

void vEspecialidades::imprimeContenedor() {
	for (int i = 0; i < cantidad; i++) {
		cout << vec[i]->toString() << endl;
	}
}

void vEspecialidades::eliminarEspecialidadPorNombre(string nom) {
	for (int i = 0; i < cantidad; i++) {
		if (vec[i]->getEspecialidad() == nom) {
			delete vec[i];
			for (int j = i; j < cantidad - 1; ++j) {
				vec[j] = vec[j + 1];
			}
			vec[cantidad - 1] = nullptr;
			cantidad--;
		}
		else {
			cout << "Especialidad no encontrada." << endl;
		}
	}

}
