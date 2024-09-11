#include "Horario.h"

Horario::Horario(): dia(""){}
Horario::Horario(string _dia) : dia(_dia) {
	int y = 8;
	for (int i = 0; i < tam; i++) {
		hora[i] = new Hora(to_string(y), "00");
		y++;
	}
}
Horario::~Horario() {
	for (int i = 0; i < tam; i++) {
		delete hora[i];
	}
}

string Horario::getDia() { return dia; }
Hora* Horario::getHora(int n){
	if (n < tam) {
		return hora[n];
	}
}
string Horario::getHoraString(int n) {
	if (n < tam) {
		return hora[n]->toString();
	}
}

void Horario::setDia(string _dia) { dia = _dia; }

string Horario::toString() {
	stringstream s;
	s << "Dia: " << dia << "\n";
	for (int i = 0; i < tam; i++) {
		s <<"->"<<i<<"\n"
			<< "   " << hora[i]->toString() << "\n";
	}
	return s.str();
}
