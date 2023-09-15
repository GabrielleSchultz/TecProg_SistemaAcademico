#pragma once

#include <iostream>
using namespace std;

#include <string>
using namespace std;

class Departamento;
#include "Identifica.h"

class ElDepartamento : public Identificador {

private:

	ElDepartamento* el_dpto_prox;
	ElDepartamento* el_dpto_ant;
	Departamento* p_dpto;

public:
	ElDepartamento();
	~ElDepartamento();

	void set_p_dpto(Departamento* departamento);
	Departamento* get_p_dpto();

	void set_elem_prox(ElDepartamento* proximo);
	void set_elem_ant(ElDepartamento* anterior);

	ElDepartamento* get_elem_prox();
	ElDepartamento* get_elem_ant();

	string getName();
};