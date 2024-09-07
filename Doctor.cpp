#include "Doctor.h"

Doctor::Doctor(): nombre(""), especialidad(nullptr) {}
Doctor::Doctor(string nom, Especialidad* esp): nombre(nom), especialidad(esp) {
	horario[0] = new Horario("Lunes");
	horario[1] = new Horario("Martes");
	horario[2] = new Horario("Miercoles");
	horario[3] = new Horario("Jueves");
	horario[4] = new Horario("Viernes");
	horario[5] = new Horario("Sabado");
}
Doctor::~Doctor() {
	for (int i = 0; i < tam2; i++) {
		delete horario[i];
	}
}

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
