#ifndef DOCTOR_H
#define DOCTOR_H
#pragma once
#include "Especialidad.h"
#include "Horario.h"

const int tam2 = 6;

class Doctor {
private:
	string nombre;
	Especialidad* especialidad;
	Horario * horario[tam2];
public:
	Doctor();
	Doctor(string, Especialidad*);
	~Doctor();

	void setNombre(string);
	void setEspecialidad(Especialidad*);

	string getNombre();
	Especialidad* getEspecialidad();

	string toString();
};

#endif // !DOCTOR_H
