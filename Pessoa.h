#pragma once

#include <string>
#include <iostream>
using namespace std;

#include "Identifica.h"

class Pessoa : public Identificador {

protected:
	int dia_nasc;
	int mes_nasc;
	int ano_nasc;
	int idade_pessoa;
	string nome_pessoa;

public:

	Pessoa(int setId = -1);
	~Pessoa();
	Pessoa(int dia_pessoa, int mes_pessoa, int ano_pessoa, string nome_pessoa);
	void inicializa(int dia, int mes, int ano, string nome);
	void calcula_idade(int dia_atual, int mes_atual, int ano_atual);
	int getIdade();	//informaIdade()
	void imprime_idade();
	string getName() { return nome_pessoa; }
	void setName(string nome);

};