#include "ListaDisciplinas.h"

ListaDisciplinas::ListaDisciplinas()
{
	template_listaDisciplinas.inicializa();
}

ListaDisciplinas::~ListaDisciplinas()
{
	limpa_lista();
}

void ListaDisciplinas::set_subject(Disciplina* p_disciplina)
{
	template_listaDisciplinas.incluir(p_disciplina);
}

void ListaDisciplinas::imprime_disciplinas_first_to_last()
{
	Elemento<Disciplina>* p_aux = template_listaDisciplinas.get_primeiro();
	Disciplina* p_disciplina = NULL;

	while (p_aux != NULL) {

		p_disciplina = p_aux->get_referencia();
		cout << "-" << p_disciplina->get_subj_name() << endl;
		p_aux = p_aux->get_proximo();
	}
}

Disciplina* ListaDisciplinas::localizar(string nome_disciplina)
{
	Elemento<Disciplina>* percorre = template_listaDisciplinas.get_primeiro();
	Disciplina* p_disciplina = NULL;

	while (percorre != NULL)
	{
		p_disciplina = percorre->get_referencia();

		if (p_disciplina->get_subj_name() == nome_disciplina)
			return percorre->get_referencia();

		percorre = percorre->get_proximo();
	}

	return NULL;
}

int ListaDisciplinas::get_num_disciplinas()
{
	return template_listaDisciplinas.get_num_elementos();
}

void ListaDisciplinas::limpa_lista()
{
	template_listaDisciplinas.limpar();
}

void ListaDisciplinas::gravar_disciplinas()
{
}

void ListaDisciplinas::recuperar_disciplinas()
{
}
