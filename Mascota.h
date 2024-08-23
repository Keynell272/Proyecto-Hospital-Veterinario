#ifndef MASCOTA_H
#define MASCOTA_H
#pragma once
#include "Dueno.h"

class Mascota {
private:
    string nombre;
    Dueno* dueno;

public:
    Mascota();
    Mascota(string, Dueno*);
    ~Mascota();

	void setNombre(string);
	void setDueno(Dueno*);

	string getNombre();
	Dueno* getDueno();

	string toString();
};

#endif // !MASCOTA_H
