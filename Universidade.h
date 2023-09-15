#pragma once

#include "Identifica.h"
#include "ListaDepartamentos.h"

class Departamento;

class Universidade : public Identificador {

private:
	string nome_univ;
	ListaDepartamento obj_dptos;

public:
	Universidade(int setId = -1);
	~Universidade();
	void set_univ_name(string nome);
	string get_univ_name();
	void set_departamento(Departamento* p_dpto);
	void imprimeDptos();
};