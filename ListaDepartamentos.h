#pragma once

#include "Lista.h"
#include "ElemDepartamento.h"

class Departamento;

class ListaDepartamento : public Identificador 
{
private:

	Lista<Departamento> template_listaDptos;

public:
	ListaDepartamento();
	~ListaDepartamento();

	void inclue_departamento(Departamento* p_dpto);
	void imprime_departamentos();
	Departamento* localizar(string nome_dpto);
	int get_num_dptos();
	void gravar_dptos();
	void recuperar_dptos();
	void limpa_lista();
};