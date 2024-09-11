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

string Doctor::toStringHorarios() {
	//horario[4]->getHora(1)->setEscogida(true);
	//horario[1]->getHora(10)->setEscogida(true);
	stringstream s;
	s << "\n\tHorarios\n" << endl;
	for (int i = 0; i < 6; i++) {
		s << horario[i]->getDia() << " ";
	}
	s << "\n";
	for (int i = 0; i < tam; i++) {
		for (int j = 0; j < 6; j++) {
			if(horario[j]->getHora(i)->getEscogida() == false) {
				s << horario[j]->getHoraString(i) << "\t";
			}
			else {
				s << "ocupado" << "\t";
			}
		}
		s << "\n";
	}
	
	return s.str();
}
