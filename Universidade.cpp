#include "Universidade.h"
#include "Departamento.h"

#include <iostream>
using namespace std;
#include <string>

Universidade::Universidade(int setId)
{
	nome_univ = " ";
	id = setId;
}

Universidade::~Universidade()
{
}

void Universidade::set_univ_name(string nome)
{
	nome_univ = nome;
}

void Universidade::set_univ_nickname(string nickname)
{
	sigla = nickname;
}

const string Universidade::get_univ_name()
{
	return nome_univ;
}

const string Universidade::get_univ_nickname()
{
	return sigla;
}


void Universidade::set_departamento(Departamento* p_dpto)
{
	obj_dptos.inclue_departamento(p_dpto);
}

void Universidade::imprimeDptos()
{
	cout << "Lista de Departamentos de " << nome_univ << endl;
	obj_dptos.imprime_departamentos();
	printf("\n");
}
