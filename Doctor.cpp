#include "Doctor.h"

Doctor::Doctor(): nombre(""), especialidad(NULL) {}
Doctor::Doctor(string nom, Especialidad* esp): nombre(nom), especialidad(esp) {}
Doctor::~Doctor() { delete especialidad; }

void Doctor::setNombre(string nom) { nombre = nom; }
void Doctor::setEspecialidad(Especialidad* esp) { 
	especialidad = esp;
}

string Doctor::getNombre() { return nombre; }
Especialidad* Doctor::getEspecialidad() { return especialidad; }

string Doctor::toString(){
	stringstream s;
	s << "Doctor " << nombre << " \n" << especialidad->toString() << endl;
	return s.str();
}
