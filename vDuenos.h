#ifndef VDUENOS_H
#define VDUENOS_H
#pragma once
#include "Dueno.h"

class vDuenos {
private:
	Dueno ** vec;
	int cantidad;
	int tamano;
public:
	vDuenos(int);
	~vDuenos();

	void setCantidad(int);
	int getCantidad();
	Dueno* getVec(int);

	void agregarDueno(Dueno*);
	void imprimeContenedor();

	bool estaVacio();

	bool verificarID(int);
};

#endif // !VDUENOS_H
