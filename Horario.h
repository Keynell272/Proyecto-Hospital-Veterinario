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
	Hora* getHora(int);
	string getHoraString(int);

	void setDia(string);

	string toString();
};


#endif // !CITA_H
