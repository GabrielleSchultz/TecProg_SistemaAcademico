#pragma once
#include "Lista.h"

class Professor;

class ListaProfessor {

private:

	Lista<Professor> template_listaProfessores;

public:
	ListaProfessor();
	~ListaProfessor();

	int get_num_professores();
	void inclue_professor(Professor* p_prof);
	void imprime_professores();
	Professor* localiza(string nome_prof);
	void limpa_lista();
	void gravar_professores();
	void recuperar_professores();
};