#include "ListaProfessores.h"
#include "Professor.h"

ListaProfessor::ListaProfessor()
{
	template_listaProfessores.inicializa();
}

ListaProfessor::~ListaProfessor()
{
	limpa_lista();
}

int ListaProfessor::get_num_professores()
{
	return template_listaProfessores.get_num_elementos();
}

void ListaProfessor::inclue_professor(Professor* p_prof)
{
	template_listaProfessores.incluir(p_prof);
}

void ListaProfessor::imprime_professores()
{
	Elemento<Professor>* percorre = template_listaProfessores.get_primeiro();
	Professor* p_professor = NULL;

	while (percorre != NULL)
	{
		p_professor = percorre->get_referencia();
		cout << "-" << p_professor->getName() << endl;
		percorre = percorre->get_proximo();
	}
}

Professor* ListaProfessor::localiza(string nome_prof)
{
	Elemento<Professor>* percorre = template_listaProfessores.get_primeiro();
	Professor* p_professor = NULL;

	while (percorre != NULL)
	{
		p_professor = percorre->get_referencia();
		if (p_professor->getName() == nome_prof)
			return percorre->get_referencia();
	}

	return NULL;
}

void ListaProfessor::limpa_lista()
{
	template_listaProfessores.limpar();
}

void ListaProfessor::gravar_professores()
{
}

void ListaProfessor::recuperar_professores()
{
}
