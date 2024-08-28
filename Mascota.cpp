#include "Mascota.h"

Mascota::Mascota(){
	nombre= "";
	dueno = nullptr;
}

Mascota::Mascota(string nom, Dueno* Dueno){
	nombre = nom;
	dueno = Dueno;
}

Mascota::~Mascota() {}

void Mascota::setNombre(string nom) {
	nombre = nom; 
}

void Mascota::setDueno(Dueno* nuevoDueno) { 
	this->dueno = nuevoDueno;
}

string Mascota::getNombre() { 
	return this->nombre; 
}

Dueno* Mascota::getDueno() {
	return this->dueno; 
}

string Mascota::toString() {
	stringstream s;
	s << "Mascota: " << nombre<< endl;
	s<< "Dueno:" << (dueno ? dueno->getNombre() : "No tiene dueno") << endl;
	return s.str();
}
