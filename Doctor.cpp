#include "Doctor.h"

Doctor::Doctor(): nombre(""), especialidad(nullptr) {}
Doctor::Doctor(string nom, Especialidad* esp): nombre(nom), especialidad(esp) {}
Doctor::~Doctor() { delete especialidad; }

void Doctor::setNombre(string nom) { nombre = nom; }
void Doctor::setEspecialidad(Especialidad* esp) { 
	especialidad = esp;
}

string Doctor::getNombre() { return this->nombre; }
Especialidad* Doctor::getEspecialidad() { return this->especialidad; }

string Doctor::toString(){
	stringstream s;
	s << "Doctor " << nombre << " \n" << especialidad->toString() << endl;
	return s.str();
}
