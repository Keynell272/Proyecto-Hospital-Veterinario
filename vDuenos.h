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
	void eliminarDuenoPorNombre(string);

	bool estaVacio();
};

#endif // !VDUENOS_H
