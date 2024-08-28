#ifndef VESPECIALIDADES_H
#define VESPECIALIDADES_H
#pragma once
#include "Especialidad.h"

class vEspecialidades {
private:
	Especialidad ** vec;
	int cantidad;
	int tamano;
public:
	vEspecialidades(int);
	~vEspecialidades();

	void setCantidad(int);
	int getCantidad();
	Especialidad* getVec(int);
		
	void agregarEspecialidad(Especialidad*);
	void imprimeContenedor();
	void eliminarEspecialidadPorNombre(string);

	bool estaVacio();
};

#endif // !VESPECIALIDADES_H
