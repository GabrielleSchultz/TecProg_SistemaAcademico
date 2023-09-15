#pragma once

#include "Pessoa.h"

#include "Universidade.h"
#include "Departamento.h"
#include "Disciplinas.h"

class Academico : public Pessoa
{
protected:
	Universidade* p_univ_filiada;
	Disciplina* p_disc_associada;
	Departamento* p_dpto_filiado;

public:
	Academico(int setId = -1);
	~Academico();
	Academico(int dia, int mes, int ano, string nome);
	void set_univ_filiada(Universidade* univ_filiada);
	Universidade* get_univ_filiada();
	void set_disciplina_associada(Disciplina* disc_associada);
	Disciplina* get_disciplina_associada();
	void set_dpto_filiado(Departamento* dpto_filiado);
	Departamento* get_dpto_filiado();
};

