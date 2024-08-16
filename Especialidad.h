#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>
#include <time.h>
#include <windows.h>

using namespace std;

class Especialidad{
  private:
    string especialidad;
  public:
    Especialidad();
    Especialidad(string);
    ~Especialidades();

    void setEspecialidad(string);
    string getEspecialidad();

    string toString();
};
