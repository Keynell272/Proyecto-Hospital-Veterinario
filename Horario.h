#ifndef HORARIO_H
#define HORARIO_H
#pragma once
#include "Hora.h"

const int tam = 12;

class Horario {
private:
	string dia;
	Hora * hora[tam];
public:
	Horario();
	Horario(string);
	~Horario();

	string getDia();

	void setDia(string);

	string toString();
};


#endif // !CITA_H
