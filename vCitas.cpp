#include "vCitas.h"

vCitas::vCitas(int n): cantidad(0), tamano(n) {
	vec = new Cita * [n];
	for (int i = 0; i < n; i++) {
		vec[i] = nullptr;
	}
}
vCitas::~vCitas(){
	for (int i = 0; i < cantidad; i++) {
		delete vec[i];
	}
	delete[] vec;
}

void vCitas::setCantidad(int n) { cantidad = n; }
int vCitas::getCantidad() { return cantidad; }

Cita* vCitas::getVec(int n){
	for (int i = 0; i < cantidad; i++) {
		if (i == n) {
			return vec[i];
		}
	}
	return nullptr;
}

bool vCitas::agregarCita(Cita* cit){
	if (cantidad < tamano) {
		for (int i = 0; i < cantidad; i++) {
			if (vec[i]->getCodigo() == cit->getCodigo()) {
				return false;
			}
		}
	}
	vec[cantidad] = cit;
	cantidad++;
	return true;
}
void vCitas::imprimeContenedor(){
	for (int i = 0; i < cantidad; i++) {
		imprimeCadena("--->");imprimeEntero(i + 1);imprimeCadena("\n");
		imprimeCadena(vec[i]->toString());imprimeCadena("\n");
	}
}
void vCitas::eliminarCitaPorDia(string){}

bool vCitas::estaVacio(){
	if (cantidad == 0) {
		return true;
	}
	else {
		return false;
	}
}
