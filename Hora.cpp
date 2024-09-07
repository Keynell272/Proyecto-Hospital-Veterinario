#include "Hora.h"

Hora::Hora(): hora("00"), minutos("00")
{}
Hora::Hora(string h, string m): hora(h), minutos(m)
{}
Hora::~Hora(){}

string Hora::getHora() { return hora; }
string Hora::getMinutos() { return minutos; }

void Hora::setHora(string h) { hora = h; }
void Hora::setMinutos(string m) { minutos = m; }

string Hora::toString(){
	stringstream s;
	s << hora << ":" << minutos;
	return s.str();
}
