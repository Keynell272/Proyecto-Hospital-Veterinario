#ifndef HORA_H
#define HORA_H
#pragma once
#include "utiles.h"

class Hora {
private:
	string hora;
	string minutos;
public:
	Hora();
	Hora(string, string);
	~Hora();

	string getHora();
	string getMinutos();

	void setHora(string);
	void setMinutos(string);

	string toString();
};

#endif // !HOSPITAL_H
