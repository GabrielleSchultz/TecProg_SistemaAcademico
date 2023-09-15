#include "ListaAlunos.h"
#include "Aluno.h"

ListaAlunos::ListaAlunos(int n_alunos)
{
	template_listaAlunos.inicializa();
	template_listaAlunos.set_max_elementos(n_alunos);
}

ListaAlunos::~ListaAlunos()
{
	limpa_lista();
}

void ListaAlunos::inclue_aluno(Aluno* p_aluno)
{
	if (p_aluno)
		template_listaAlunos.incluir(p_aluno);
	else
	{ 
		cerr << "Erro: ponteiro nulo para aluno" << endl;
		cerr << "Aluno nao incluido." << endl;
	}
}	

int ListaAlunos::get_num_alunos()
{
	return template_listaAlunos.get_num_elementos();
}

void ListaAlunos::gravar_alunos()
{
	ofstream gravador_alunos("alunos.dat"); // ios::out <- default

	if (!gravador_alunos)
	{
		cerr << "Erro: nao foi possivel abrir arquivo de gravacao de alunos" << endl;
		cin >> ws;
		getchar();
	}

	Elemento<Aluno>* aux_elAluno = template_listaAlunos.get_primeiro();
	Aluno* aux_aluno = NULL;

	while (aux_elAluno != NULL)
	{
		aux_aluno = aux_elAluno->get_referencia();
		string nome = aux_aluno->getName();

		std::replace(nome.begin(), nome.end(), ' ', '_'); 
		gravador_alunos << nome << " " << aux_aluno->get_id() << " "
			<< aux_aluno->get_RA() << endl;

		aux_elAluno = aux_elAluno->get_proximo();
	}

	gravador_alunos.close();
}

void ListaAlunos::recuperar_alunos()
{
	ifstream recuperador_alunos("alunos.dat", ios::in);
	//ifstream recuperador_alunos;
	//recuperador_alunos.open ("alunos.dat, ios::in);

	if (!recuperador_alunos)
	{
		cerr << "Erro: nao foi possivel abrir arquivo de recuperacao de alunos" << endl;
		cin >> ws;
		getchar();
		return;
	}

	limpa_lista();

	int id_aluno;
	int ra_aluno;
	string nome_aluno;

	while (recuperador_alunos >> nome_aluno >> id_aluno >> ra_aluno)
	{
		Aluno* aluno_recuperado = new Aluno(id_aluno);

		std::replace(nome_aluno.begin(), nome_aluno.end(), '_', ' ');

		aluno_recuperado->setName(nome_aluno);
		aluno_recuperado->set_id(id_aluno);
		aluno_recuperado->set_RA(ra_aluno);
		aluno_recuperado->set_static_value(0);

		inclue_aluno(aluno_recuperado);
	}

	recuperador_alunos.close();
}

void ListaAlunos::limpa_lista()
{
	template_listaAlunos.limpar();
}

void ListaAlunos::lista_alunos() {

	Elemento<Aluno>* aux_elemento = NULL;
	Aluno* aux_aluno = NULL;

	aux_elemento = template_listaAlunos.get_primeiro();

	while (aux_elemento != NULL)
	{
		aux_aluno = aux_elemento->get_referencia();
		cout << "- " << aux_aluno->getName() << " || RA: " << aux_aluno->get_RA() << endl;
		aux_elemento = aux_elemento->get_proximo();
	}
}

Aluno* ListaAlunos::localizar(string nome_aluno)
{
	Elemento<Aluno>* percorre = template_listaAlunos.get_primeiro();
	Aluno* aux_aluno = NULL;

	while (percorre != NULL)
	{
		aux_aluno = percorre->get_referencia();
		if (aux_aluno->getName() == nome_aluno)
			return percorre->get_referencia();
		percorre = percorre->get_proximo();
	}
	return NULL;
}
