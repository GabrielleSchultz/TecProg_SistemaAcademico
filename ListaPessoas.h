#pragma once
#include "Lista.h"
#include "Professor.h"
#include "Aluno.h"

class ListaPessoas
{
private:
	Lista<Pessoa> lista_pessoas;

public:
	ListaPessoas();
	~ListaPessoas();
	void inclue_pessoa(Pessoa* p_pessoa);
	void inclue_aluno(Aluno* aluno);
	void inclue_prof(Professor* prof);
	void imprime_pessoas();
	int get_num_pessoas();
};

