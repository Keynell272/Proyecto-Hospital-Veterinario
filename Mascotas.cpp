#include "Mascotas.h"

Mascota::Mascota(){
	nombre=""
	Dueno(NULL)
}

Mascota::Mascota(string nom, Dueno* dueno){
	nombre = nom;
	Dueno = new Dueno;
}

Mascota::~Mascota(){
	delete Dueno; 
}

void Mascota::setNombre(string nom) {
	nombre = nom; 
}

void Mascota::setDueno(Especialidad& esp) { 
	delete especialidad;
	especialidad = new Especialidad(esp);
}

string Doctor::getNombre() { return nombre; }
Especialidad* Doctor::getEspecialidad() { return especialidad; }

string Doctor::toString(){
	stringstream s;
	s << "Doctor " << nombre << " \n" << especialidad->toString() << endl;
	return s.str();
