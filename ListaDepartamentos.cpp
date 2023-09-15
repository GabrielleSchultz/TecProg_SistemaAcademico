#include "ListaDepartamentos.h"
#include "Departamento.h"

ListaDepartamento::ListaDepartamento()
{
	template_listaDptos.inicializa();
}

ListaDepartamento::~ListaDepartamento()
{
	limpa_lista();
}

void ListaDepartamento::inclue_departamento(Departamento* p_dpto)
{
	template_listaDptos.incluir(p_dpto);
}

void ListaDepartamento::imprime_departamentos()
{
	Elemento<Departamento>* percorre = template_listaDptos.get_primeiro();
	Departamento* aux_dpto = NULL;

	while (percorre != NULL)
	{
		aux_dpto = percorre->get_referencia();
		cout << "-" << aux_dpto->get_dpto_name() << endl;
		percorre = percorre->get_proximo();
	}
}

Departamento* ListaDepartamento::localizar(string nome_dpto)
{
	Elemento<Departamento>* percorre = template_listaDptos.get_primeiro();
	Departamento* aux_dpto = NULL;

	while (percorre != NULL)
	{
		aux_dpto = percorre->get_referencia();

		if (aux_dpto->get_dpto_name() == nome_dpto)
			return percorre->get_referencia(); //return aux_dpto

		percorre = percorre->get_proximo();
	}

	return NULL;
}

int ListaDepartamento::get_num_dptos()
{
	return template_listaDptos.get_num_elementos();
}

void ListaDepartamento::gravar_dptos()
{
	ofstream gravador_dptos("departamentos.dat");

	if (!gravador_dptos)
	{
		cerr << "Erro: Nao foi possivel abrir o arquivo de gravacao de departamentos" << endl;
		cin >> ws;
		getchar();
		return;
	}

	Elemento<Departamento>* aux_elemento = template_listaDptos.get_primeiro();

	while (aux_elemento != NULL)
	{
		Departamento* aux_dpto = aux_elemento->get_referencia();
		string nome = aux_dpto->get_dpto_name();

		std::replace(nome.begin(), nome.end(), ' ', '_');
		gravador_dptos << nome << " " << aux_dpto->get_id() << endl;

		aux_elemento = aux_elemento->get_proximo();
	}

	gravador_dptos.close();
}

void ListaDepartamento::recuperar_dptos()
{
	ifstream recuperador_dptos("departamentos.dat", ios::in);

	if (!recuperador_dptos)
	{
		cerr << "Erro : nao foi possivel abrir o arquivo de recuperacao de departamentos" << endl;
		cin >> ws;
		getchar();
		return;
	}

	int id = 0;
	string nome;

	while (recuperador_dptos >> nome >> id)
	{
		Departamento* dpto_recuperado = new Departamento(id);
		replace(nome.begin(), nome.end(), '_', ' ');

		dpto_recuperado->set_dpto_name(nome);
		dpto_recuperado->set_static_value(0);
		inclue_departamento(dpto_recuperado);
	}
}

void ListaDepartamento::limpa_lista()
{
	template_listaDptos.limpar();
}
