#include "Academico.h"

Academico::Academico(int setId):
Pessoa(setId)
{
	p_univ_filiada = NULL;
	p_dpto_filiado = NULL;
	p_disc_associada = NULL;
}

Academico::~Academico()
{
	p_univ_filiada = NULL;
	p_dpto_filiado = NULL;
	p_disc_associada = NULL;
}

Academico::Academico(int dia, int mes, int ano, string nome) :
Pessoa(dia, mes, ano, nome)
{
	p_univ_filiada = NULL;
	p_dpto_filiado = NULL;
	p_disc_associada = NULL;
}

void Academico::set_univ_filiada(Universidade* univ_filiada)
{
	p_univ_filiada = univ_filiada;
}

Universidade* Academico::get_univ_filiada()
{
	return p_univ_filiada;
}

void Academico::set_disciplina_associada(Disciplina* disc_associada)
{
	p_disc_associada = disc_associada;
	p_dpto_filiado = p_disc_associada->get_dpto_associado();
}

Disciplina* Academico::get_disciplina_associada()
{
	return p_disc_associada;
}

void Academico::set_dpto_filiado(Departamento* dpto_filiado)
{
	p_dpto_filiado = dpto_filiado;
}

Departamento* Academico::get_dpto_filiado()
{
	return p_dpto_filiado;
}
