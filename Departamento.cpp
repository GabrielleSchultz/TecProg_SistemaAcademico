#include "Departamento.h"

#include <string.h>

#include <iostream>
using namespace std;

Departamento::Departamento(int setId)
{
	nome_departamento = "";
	p_univ = NULL;

	id = setId;
}

Departamento::~Departamento()
{
	p_univ = NULL;
}

void Departamento::set_dpto_name(string nome)
{
	nome_departamento = nome;
}

string Departamento::get_dpto_name()
{
	return nome_departamento;
}

void Departamento::set_univ(Universidade* univ)
{
	p_univ = univ;
	p_univ->set_departamento(this);
}

void Departamento::set_subject(Disciplina* p_disciplina)
{	
	obj_listaDisciplinas.set_subject(p_disciplina);
}

 Universidade* Departamento::get_univ_associada()
{
	return p_univ;
}

void Departamento::imprime_disciplinas_first_to_last()
{
	cout << "Lista de disciplinas do " << nome_departamento << " : " << endl;
	obj_listaDisciplinas.imprime_disciplinas_first_to_last();
	cout << "--------" << endl;
	printf("\n");

}

