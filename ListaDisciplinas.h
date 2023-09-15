#pragma once

#include "Lista.h"
#include "Disciplinas.h"

class ListaDisciplinas : public Identificador {

private:
	
	Lista<Disciplina> template_listaDisciplinas;

public:
	ListaDisciplinas();
	~ListaDisciplinas();

	void set_subject(Disciplina* p_disciplina);
	void imprime_disciplinas_first_to_last();
	Disciplina* localizar(string nome_disciplina);
	int get_num_disciplinas();
	void limpa_lista();
	void gravar_disciplinas();
	void recuperar_disciplinas();
};