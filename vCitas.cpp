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
		vec[cantidad] = cit;
		cantidad++;
		imprimeCadena("Cita agregada.\n");
		return true;
	}
	else {
		imprimeCadena("El Contenedor esta lleno.\n");
		return false;
	}
}
void vCitas::imprimeContenedor(){
	for (int i = 0; i < cantidad; i++) {
		imprimeCadena("--->");imprimeEntero(i + 1);imprimeCadena("\n");
		imprimeCadena(vec[i]->toString());imprimeCadena("\n");
	}
}

bool vCitas::estaVacio(){
	if (cantidad == 0) {
		return true;
	}
	else {
		return false;
	}
}

string vCitas::toStringDoctoresXDueno(int _id) {
	stringstream s;

	for (int i = 0; i < cantidad; i++) {
		if (vec[i]->getMascota()->getDueno()->getID() == _id) {	
			s << "-->" << i << "\n"
				<< vec[i]->getDoctor()->toString() << "\n";
			
		}
	}
	return s.str();
}

string vCitas::toStringMascotasXDoctor(Doctor* d, int id) {
	stringstream s;

	for (int i = 0; i < cantidad; i++) {
		if (d == vec[i]->getDoctor() && id == vec[i]->getMascota()->getDueno()->getID()) {
			s << "-->" << i << "\n"
				<< vec[i]->getMascota()->toString() << "\n";
		}
	}
	return s.str();
}

bool vCitas::eliminarCitaXMascota(int mas) {

	for (int i = 0; i < cantidad; i++) {
		if (i == mas) {
			vec[i]->getDoctor()->getHorario(vec[i]->getDia())->getHora(vec[i]->getHora() - 8)->setEscogida(false);
			delete vec[i];
			for (int j = i; j < cantidad - 1; j++) {
				vec[j] = vec[j + 1]; 
			}
			cantidad--;
			return true;
		}
	}
	return false;
}

int vCitas::cantidadDoctoresPorDueno(int id) {
	int cant = 0;
	for (int i = 0; i < cantidad; i++) {
		if (id == vec[i]->getMascota()->getDueno()->getID()) {
			cant++;
		}
	}
	return cant;
}

bool vCitas::verificarPosicion(int id, int pos) {
	int* posicionesValidas = new int[cantidadDoctoresPorDueno(id)];
	int contador = 0;
	for (int i = 0;i < cantidad; i++) {
		if (id == vec[i]->getMascota()->getDueno()->getID()) {
			if (contador < cantidadDoctoresPorDueno(id)) {
				posicionesValidas[contador] = i;
				contador++;
			}
		}
	}
	for (int i = 0;i < cantidadDoctoresPorDueno(id);i++) {
		if (pos == posicionesValidas[i]) {
			delete[] posicionesValidas;
			return true;
		}
	}
	delete[] posicionesValidas;
	return false;
}

string vCitas::toStringCitasXDueno(int _id) {
	stringstream s;

	for (int i = 0; i < cantidad; i++) {
		if (vec[i]->getMascota()->getDueno()->getID() == _id) {
			s << "-->" << i << "\n"
				<< vec[i]->toString() << "\n";

		}
	}
	return s.str();
}

string vCitas::toStringCitasXDoctor(Doctor* d) {
	stringstream s;

	for (int i = 0; i < cantidad; i++) {
		if (vec[i]->getDoctor() == d) {
			s << "-->" << i << "\n"
				<< vec[i]->toString() << "\n";
		}
	}

	return s.str();
}

string vCitas::toStringPacienteXDoctor(Doctor* d) {
	stringstream s;

	for (int i = 0; i < cantidad; i++) {
		if (vec[i]->getDoctor() == d) {
			s << "-->" << i << "\n"
				<< vec[i]->getMascota()->toString() << "\n";
		}
	}

	return s.str();
}
