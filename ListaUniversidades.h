#pragma once
#include "Lista.h"

class Universidade;

class ListaUniversidade : public Identificador {

private:
	
	Lista<Universidade> template_listaUniversidades;

public:
	ListaUniversidade();
	~ListaUniversidade();

	void inclue_universidade(Universidade* universidade);
	void imprime_universidades();
	Universidade* localizar(string nome_univ);
	int get_num_univs();
	void limpa_lista();
	void gravar_universidades();
	void recuperar_universidades();
};