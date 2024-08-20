#ifndef VDUENOS_H
#define VDUENOS_H
#pragma once
#include "Dueno.h"

class vDuenos {
private:
	Dueno* vec[100];
	int cantidad;
public:
	vDuenos();
	~vDuenos();

	void agregarDueno(Dueno*);
	void imprimeContenedor();
	void eliminarDuenoPorNombre(string);
};

#endif // VDUENOS_H
