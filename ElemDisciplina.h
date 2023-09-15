#pragma once
#include "Disciplinas.h"

#include <string>
using namespace std;

class ElDisciplina : public Identificador {

private:

	ElDisciplina* p_proximo;
	ElDisciplina* p_anterior;
	Disciplina* p_disciplina;


public:
	ElDisciplina();
	~ElDisciplina();

	void set_elemDisciplina_anterior(ElDisciplina* p_subj_anterior);
	ElDisciplina* get_elemDisciplina_anterior();
	void set_elemDisciplina_proxima(ElDisciplina* p_subj_proxima);
	ElDisciplina* get_elemDisciplina_proxima();

	void set_disciplina(Disciplina* disciplina);
	Disciplina* get_disciplina();

	string getName();
};
