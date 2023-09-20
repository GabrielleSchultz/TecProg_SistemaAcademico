#pragma once

#include "Identifica.h"
#include "ListaDepartamentos.h"

class Departamento;

class Universidade : public Identificador {

private:
	string nome_univ;
	string sigla;
	ListaDepartamento obj_dptos;

public:
	Universidade(int setId = -1);
	~Universidade();
	void set_univ_name(string nome);
	void set_univ_nickname(string nickname); //entende a sigla
	const string get_univ_name();
	const string get_univ_nickname();
	void set_departamento(Departamento* p_dpto);
	void imprimeDptos();
};