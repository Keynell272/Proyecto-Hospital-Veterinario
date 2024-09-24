#include "Hora.h"

Hora::Hora(): hora("00"), minutos("00"), escogida(false)
{}
Hora::Hora(string h, string m): hora(h), minutos(m), escogida(false)
{}
Hora::~Hora(){}

string Hora::getHora() { return hora; }
string Hora::getMinutos() { return minutos; }
bool Hora::getEscogida() { return escogida; }

void Hora::setHora(string h) { hora = h; }
void Hora::setMinutos(string m) { minutos = m; }
void Hora::setEscogida(bool e) { escogida = e; }

string Hora::toString(){
	stringstream s;
	s << hora << ":" << minutos;
	return s.str();
}
