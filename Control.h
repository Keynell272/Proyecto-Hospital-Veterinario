#ifndef CONTROL_H
#define CONTROL_H
#pragma once
#include "Hospital.h"

class Control {
private:
	Hospital* hospital;
public:
	Control();
	~Control();

	void menuOpcion();
	void manejarSubMenu(int);
	void manejarOpcionAdministrativo(int);
	void manejarOpcionCitas(int);
	void manejarOpcionBusquedas(int);

	void menuPrincipal();
	void menuAdministrativo();
	void menuCitas();
	void menuBusquedasListados();
};

#endif // !CONTROL_H
