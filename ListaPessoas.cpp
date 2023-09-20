#include "ListaPessoas.h"

ListaPessoas::ListaPessoas()
{
	lista_pessoas.inicializa();
}

ListaPessoas::~ListaPessoas()
{
	lista_pessoas.limpar();
}

void ListaPessoas::inclue_pessoa(Pessoa* p_pessoa)
{
	if (p_pessoa != NULL)
		lista_pessoas.incluir(p_pessoa);
	else
		cerr << "Erro: ponteiro nulo para pessoa." << endl;
}

void ListaPessoas::inclue_aluno(Aluno* aluno)
{
	Pessoa* p_aluno_pessoa = NULL;

	p_aluno_pessoa = static_cast <Pessoa*> (aluno);
	inclue_pessoa(p_aluno_pessoa);
}

void ListaPessoas::inclue_prof(Professor* prof)
{
	Pessoa* p_prof_pessoa = NULL;

	p_prof_pessoa = static_cast <Pessoa*> (prof);
	inclue_pessoa(p_prof_pessoa);
}

void ListaPessoas::imprime_pessoas()
{
	Elemento<Pessoa> *aux = lista_pessoas.get_primeiro();

	while (aux != NULL)
	{
		Pessoa* p_pessoa = aux->get_referencia();
		cout << "- " << p_pessoa->getName() << endl;
	}
}

int ListaPessoas::get_num_pessoas()
{
	return lista_pessoas.get_num_elementos();
}

