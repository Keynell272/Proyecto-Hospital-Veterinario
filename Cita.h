#ifndef CITA_H
#define CITA_H
#pragma once
#include "Mascota.h"

class Cita {
private:
	Mascota* mas;
	Doctor* doc;
	int dia;
	int hora;
public:
	Cita();
	Cita(Mascota*, Doctor*, int, int);
	~Cita();

	void setMascota(Mascota*);
	void setDoctor(Doctor*);

	Mascota* getMascota();
	Doctor* getDoctor();
	int getDia();
	int getHora();

	string toString();
};

#endif // !CITA_H
