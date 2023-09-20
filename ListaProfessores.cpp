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
	ofstream gravador_professores("professores.dat", ios::out);

	if (!gravador_professores)
	{
		cerr << "Erro: nao foi possivel abrir arquivo de gravacao (professores)" << endl;
		cin >> ws;
		getchar();
	}
	
	Elemento<Professor>* aux = template_listaProfessores.get_primeiro();

	while (aux != NULL)
	{
		Professor* prof_gravado = aux->get_referencia();
		Universidade* univ_filiada = prof_gravado->get_univ_filiada();

		string nome_prof = prof_gravado->getName();
		std::replace(nome_prof.begin(), nome_prof.end(), ' ', '_');
		string nome_univ = univ_filiada->get_univ_name();
		std::replace(nome_univ.begin(), nome_univ.end(), ' ', '_');

		gravador_professores << prof_gravado->get_id() << " " << nome_prof
			<< " " << nome_univ << endl; 

		aux = aux->get_proximo();
	}
	gravador_professores.close();
}

void ListaProfessor::recuperar_professores()
{
}
