#pragma once
#include "Especialidad.h"

class Doctor {
private:
	string nombre;
	Especialidad* especialidad;
public:
	Doctor();
	Doctor(string, Especialidad&);
	~Doctor();

	void setNombre(string);
	void setEspecialidad(Especialidad&);

	string getNombre();
	Especialidad* getEspecialidad();

	string toString();
};
