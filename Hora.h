#ifndef HORA_H
#define HORA_H
#pragma once
#include "utiles.h"

class Hora {
private:
	string hora;
	string minutos;
	bool escogida;
public:
	Hora();
	Hora(string, string);
	~Hora();

	string getHora();
	string getMinutos();
	bool getEscogida();

	void setHora(string);
	void setMinutos(string);
	void setEscogida(bool);

	string toString();
};

#endif // !HOSPITAL_H
