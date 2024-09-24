#include "Cita.h"

Cita::Cita(): mas(nullptr), doc(nullptr)
{}
Cita::Cita(Mascota* _mas, Doctor* _doc, int _dia, int _hora) : mas(_mas), doc(_doc), dia(_dia), hora(_hora)
{}
Cita::~Cita() {}

void Cita::setMascota(Mascota* m) { mas = m; }
void Cita::setDoctor(Doctor* d) { doc = d; }

Mascota* Cita::getMascota() { return mas; }
Doctor* Cita::getDoctor() { return doc; }
int Cita::getDia() { return dia; }
int Cita::getHora() { return hora; }

string Cita::toString() {
	stringstream s;
	s << "\nCita.\n"
		<< "Dia: ";
	switch (dia)
	{
	case 0:
		s << "Lunes" << endl;
		break;
	case 1:
		s << "Martes" << endl;
		break;
	case 2:
		s << "Miercoles" << endl;
		break;
	case 3:
		s << "Jueves" << endl;
		break;
	case 4:
		s << "Viernes" << endl;
		break;
	case 5:
		s << "Sabado" << endl;
		break;
	default:
		break;
	}
	s << "Hora: " << hora << ":00" << endl
	<< mas->toString() 
	<< doc->toString();
	return s.str();
}
