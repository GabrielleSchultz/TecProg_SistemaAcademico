#include "Pessoa.h"

Pessoa::Pessoa(int dia_pessoa, int mes_pessoa, int ano_pessoa, string nome_pessoa)
{
	inicializa(dia_pessoa, mes_pessoa, ano_pessoa, nome_pessoa);
}

//construtora sem parametros
Pessoa::Pessoa(int setId)
{
	inicializa(0, 0, 0, " ");
	id = setId;
}

Pessoa::~Pessoa()
{
}

void Pessoa::inicializa(int dia, int mes, int ano, string nome)
{
	dia_nasc = dia;
	mes_nasc = mes;
	ano_nasc = ano;
	idade_pessoa = -1;
	nome_pessoa = nome;
}

void Pessoa::calcula_idade(int dia_atual, int mes_atual, int ano_atual)
{
	idade_pessoa = ano_atual - ano_nasc;

	if (mes_atual < mes_nasc) {
		idade_pessoa -= 1;
	}

	else if (mes_atual == mes_nasc) {
		if (dia_atual < dia_nasc)
			idade_pessoa -= 1;
	}
}

int Pessoa::getIdade() {	//informaIdade()
	return idade_pessoa;
}

void Pessoa::imprime_idade()
{
	cout << "Idade de " << nome_pessoa << ": " << idade_pessoa << " anos" << endl;
}

void Pessoa::setName(string nome)
{
	nome_pessoa = nome;
}
