#ifndef CITA_H
#define CITA_H
#pragma once
#include "Mascota.h"

class Cita {
private:
	int codigo;
	Mascota* mas;
	Doctor* doc;
public:
	Cita();
	Cita(Mascota*, Doctor*, int);
	~Cita();

	void setCodigo(int);
	void setMascota(Mascota*);
	void setDoctor(Doctor*);

	int getCodigo();
	Mascota* getMascota();
	Doctor* getDoctor();

	string toString();
};

#endif // !CITA_H
