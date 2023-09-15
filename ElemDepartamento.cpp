#include "ElemDepartamento.h"
#include "Departamento.h"

ElDepartamento::ElDepartamento()
{
	el_dpto_ant = NULL;
	el_dpto_ant = NULL;

	id = -1;
}

ElDepartamento::~ElDepartamento()
{
	el_dpto_ant = NULL;
	el_dpto_ant = NULL;
}

void ElDepartamento::set_p_dpto(Departamento* departamento)
{
	p_dpto = departamento;
}

Departamento* ElDepartamento::get_p_dpto()
{
	return p_dpto;
}

void ElDepartamento::set_elem_prox(ElDepartamento* proximo)
{
	el_dpto_prox = proximo;
}

void ElDepartamento::set_elem_ant(ElDepartamento* anterior)
{
	el_dpto_ant = anterior;
}

ElDepartamento* ElDepartamento::get_elem_prox()
{
	return el_dpto_prox;
}

ElDepartamento* ElDepartamento::get_elem_ant()
{
	return el_dpto_ant;
}

string ElDepartamento::getName()
{
	return p_dpto->get_dpto_name();
}
