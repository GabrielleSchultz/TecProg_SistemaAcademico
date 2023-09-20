#include "ListaUniversidades.h"
#include "Universidade.h"

ListaUniversidade::ListaUniversidade()
{
	template_listaUniversidades.inicializa();
}

ListaUniversidade::~ListaUniversidade()
{
	limpa_lista();
}

void ListaUniversidade::inclue_universidade(Universidade* p_universidade)
{
	template_listaUniversidades.incluir(p_universidade);
}

void ListaUniversidade::imprime_universidades()
{
	Elemento<Universidade>* percorre_lista = template_listaUniversidades.get_primeiro();
	Universidade* p_univ = NULL;

	while (percorre_lista != NULL)
	{
		p_univ = percorre_lista->get_referencia();
		cout << "-" << p_univ->get_univ_name() << endl;
		percorre_lista = percorre_lista->get_proximo();
	}
}

Universidade* ListaUniversidade::localizar(string nome_univ)
{
	Elemento<Universidade>* percorre = template_listaUniversidades.get_primeiro();
	Universidade* p_univ = NULL;

	while (percorre != NULL)
	{
		p_univ = percorre->get_referencia();
		if (p_univ->get_univ_name() == nome_univ || p_univ->get_univ_nickname() == nome_univ)
			return percorre->get_referencia();	//p_univ

		percorre = percorre->get_proximo();
	}

	return NULL;
}

int ListaUniversidade::get_num_univs()
{
	return template_listaUniversidades.get_num_elementos();
}

void ListaUniversidade::limpa_lista()
{
	template_listaUniversidades.limpar();
}

void ListaUniversidade::gravar_universidades()
{
	ofstream gravador_universidades("universidades.dat", ios::out);

	if (!gravador_universidades)
	{
		cerr << "Erro: nao foi possivel abrir arquivo de gravacao (universidades)";
		cin >> ws;
		getchar();
	}

	Elemento<Universidade>* p_aux = template_listaUniversidades.get_primeiro();

	while (p_aux != NULL)
	{
		Universidade* p_univ = p_aux->get_referencia();
		string nome_univ = p_univ->get_univ_name();

		std::replace(nome_univ.begin(), nome_univ.end(), ' ', '_');

		gravador_universidades << nome_univ << " " << p_univ->get_id() << endl;
		p_aux = p_aux->get_proximo();
	}
	gravador_universidades.close();
}

void ListaUniversidade::recuperar_universidades()
{
	ifstream recuperador_universidades("universidades.dat", ios::in);

	if (!recuperador_universidades)
	{
		cerr << "Erro: nao foi possivel abrir o arquivo de gravacao de universidades" << endl;
		cin >> ws;
		getchar();
	}

	limpa_lista();

	int id = 0;
	string nome_univ;

	while (recuperador_universidades >> nome_univ >> id)
	{
		Universidade* univ_recuperada = new Universidade(id);

		replace(nome_univ.begin(), nome_univ.end(), '_', ' ');
		univ_recuperada->set_univ_name(nome_univ);

		template_listaUniversidades.incluir(univ_recuperada);
	}
	recuperador_universidades.close();
}
