#include "Cita.h"

Cita::Cita(): mas(nullptr), doc(nullptr), codigo(0)
{}
Cita::Cita(Mascota* _mas, Doctor* _doc, int cod) : mas(_mas), doc(_doc), codigo(cod)
{}
Cita::~Cita() {}

void Cita::setCodigo(int n) { codigo = n; }
void Cita::setMascota(Mascota* m) { mas = m; }
void Cita::setDoctor(Doctor* d) { doc = d; }

int Cita::getCodigo() { return codigo; }
Mascota* Cita::getMascota() { return mas; }
Doctor* Cita::getDoctor() { return doc; }


string Cita::toString() {
	stringstream s;
	s << "\nCita.\n";
	return s.str();
}
