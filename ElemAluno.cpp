#include "ElemAluno.h"
//#include "Notas.h"
#include "Aluno.h"	//ps: desnecessario pois notas.h inclue aluno.h

ElAluno::ElAluno()
{
	p_proximo = NULL;
	p_anterior = NULL;

	p_aluno = NULL;
	//p_notas = NULL;
}

ElAluno::~ElAluno()
{
	p_proximo = NULL;
	p_anterior = NULL;

	p_aluno = NULL;
	//p_notas = NULL;
}

void ElAluno::set_prox_aluno(ElAluno* proximo_aluno)
{
	p_proximo = proximo_aluno;
}

void ElAluno::set_ant_aluno(ElAluno* anterior_aluno)
{
	p_anterior = anterior_aluno;
}

ElAluno* ElAluno::get_prox_aluno()
{
	return p_proximo;
}

ElAluno* ElAluno::get_ant_aluno()
{
	return p_anterior;
}

void ElAluno::set_aluno(Aluno* aluno)
{
	p_aluno = aluno;
	//p_notas->set_aluno(p_aluno);
}

Aluno* ElAluno::get_aluno()
{
	return p_aluno;
}

string ElAluno::get_nome()
{
	return p_aluno->getName();
}

//Notas* ElAluno::get_nota()
//{
//	return p_notas;
//}

