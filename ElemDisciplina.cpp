#include "ElemDisciplina.h"

ElDisciplina::ElDisciplina()
{
	p_proximo = nullptr;
	p_anterior = nullptr;
}

ElDisciplina::~ElDisciplina()
{
	p_proximo = nullptr;
	p_anterior = nullptr;
}

void ElDisciplina::set_elemDisciplina_anterior(ElDisciplina* p_subj_anterior)
{
	p_anterior = p_subj_anterior;
}

ElDisciplina* ElDisciplina::get_elemDisciplina_anterior()
{
	return p_anterior;
}

void ElDisciplina::set_elemDisciplina_proxima(ElDisciplina* p_subj_proximo)
{
	p_proximo = p_subj_proximo;
}

ElDisciplina* ElDisciplina::get_elemDisciplina_proxima()
{
	return p_proximo;
}

void ElDisciplina::set_disciplina(Disciplina* disciplina)
{
	p_disciplina = disciplina;
}

Disciplina* ElDisciplina::get_disciplina()
{
	return p_disciplina;
}

string ElDisciplina::getName()
{
	return p_disciplina->get_subj_name();
}
