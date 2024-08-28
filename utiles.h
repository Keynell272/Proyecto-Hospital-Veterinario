#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>
#include <time.h>
#include <windows.h>

using namespace std;

#ifndef UTILES_H
#define UTILES_H

void imprimeCadena(string);
void imprimeEntero(int);
void limpiaPantalla();
string leerCadena();
int leerEntero();
void esperandoEnter();
bool respuestaValida(int);

#endif
