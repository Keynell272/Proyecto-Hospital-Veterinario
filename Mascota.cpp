#include "Mascota.h"

Mascota::Mascota(){
	nombre= "";
	dueno = NULL;
}

Mascota::Mascota(string nom, Dueno* Dueno){
	nombre = nom;
	dueno = Dueno;
}

Mascota::~Mascota(){
	delete Dueno; 
}

void Mascota::setNombre(string nom) {
	nombre = nom; 
}

void Mascota::setDueno(Dueno* nuevoDueno) { 
	this->dueno = nuevoDueno;
}

string Mascota::getNombre() { 
	return nombre; 
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
