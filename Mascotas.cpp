#include "Mascotas.h"

Mascota::Doctor(): nombre(""), especialidad(NULL) {}
Doctor::Doctor(string nom, Especialidad& esp): nombre(nom){
	especialidad = new Especialidad(esp);
}
Doctor::~Doctor() { delete especialidad; }

void Doctor::setNombre(string nom) { nombre = nom; }
void Doctor::setEspecialidad(Especialidad& esp) { 
	delete especialidad;
	especialidad = new Especialidad(esp);
}

string Doctor::getNombre() { return nombre; }
Especialidad* Doctor::getEspecialidad() { return especialidad; }

string Doctor::toString(){
	stringstream s;
	s << "Doctor " << nombre << " \n" << especialidad->toString() << endl;
	return s.str();
