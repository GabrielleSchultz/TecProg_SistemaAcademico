#include "ElemProfessor.h"

ElProfessor::ElProfessor()
{
	elprof_proximo = NULL;
	elprof_anterior = NULL;
	p_professor = NULL;
}

ElProfessor::~ElProfessor()
{
	elprof_proximo = NULL;
	elprof_anterior = NULL;
	p_professor = NULL;
}

void ElProfessor::set_proximo(ElProfessor* p_prox)
{
	elprof_proximo = p_prox;
}

void ElProfessor::set_anterior(ElProfessor* p_ant)
{
	elprof_anterior = p_ant;
}

ElProfessor* ElProfessor::get_proximo()
{
	return elprof_proximo;
}

ElProfessor* ElProfessor::get_anterior()
{
	return elprof_anterior;
}

string ElProfessor::get_name()
{
	return p_professor->getName();
}

void ElProfessor::set_professor(Professor* p_prof)
{
	p_professor = p_prof;
}

Professor* ElProfessor::get_professor()
{
	return p_professor;
}
