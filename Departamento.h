#pragma once

#include "ListaDisciplinas.h"
#include "Disciplinas.h"
#include "Universidade.h"

class Departamento : public Identificador{

private:

	string nome_departamento;

	Universidade* p_univ;
	ListaDisciplinas obj_listaDisciplinas;	//aqui

public:
	Departamento(int setId = -1);
	~Departamento();

	void set_dpto_name (string nome);
	string get_dpto_name ();

	void set_univ(Universidade* univ);
	Universidade* get_univ_associada();

	void set_subject(Disciplina* p_disciplina);
	void imprime_disciplinas_first_to_last();
};