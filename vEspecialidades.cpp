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
	

	if (n >= 0 && n < cantidad) {
		return vec[n];
	}

	imprimeCadena("Mascota no encontrada.\n");
	return nullptr;
}

void vMascotas::agregarMascota(Mascota* m) {
	if (cantidad < tamano) {
		vec[cantidad] = m;
		cantidad++;
	}
	else {
		imprimeCadena("El Contenedor esta lleno.\n");
	}
}

void vMascotas::imprimeContenedor() {
	for (int i = 0; i < cantidad; i++) {
		imprimeCadena("--->");imprimeEntero(i);imprimeCadena("\n");
		imprimeCadena(vec[i]->toString());imprimeCadena("\n");
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

string vMascotas::mascotasPorDueno(int id) {
	stringstream s;
	for (int i = 0; i < cantidad; i++) {
		if (id == vec[i]->getDueno()->getID()) {
			s << "-->" << i << endl << vec[i]->toString() << endl;

		}
	}
	return s.str();
}

int vMascotas::cantidadMascotasPorDueno(int id) {
	int cant = 0;
	for (int i = 0; i < cantidad; i++) {
		if (id == vec[i]->getDueno()->getID()){
			cant++;
		}
	}
	return cant;
}

bool vMascotas::verificarPosicion(int id, int pos) {
	int * posicionesValidas = new int[cantidadMascotasPorDueno(id)];
	int contador = 0;
	for (int i = 0;i < cantidad; i++) {
		if (id == vec[i]->getDueno()->getID()) {
			if(contador < cantidadMascotasPorDueno(id)){
				posicionesValidas[contador] = i;
				contador++;
			}
		}
	}
	for (int i = 0;i < cantidadMascotasPorDueno(id);i++) {
		if (pos == posicionesValidas[i]) {
			delete[] posicionesValidas;
			return true;
		}
	}
	delete[] posicionesValidas;
	return false;
}

bool vMascotas::tieneMascota(int id) {
	for (int i = 0; i < cantidad;i++) {
		if (id == vec[i]->getDueno()->getID()) {
			return true;
		}
	}
	return false;
}
