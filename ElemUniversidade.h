#pragma once

#include "Universidade.h"

#include <string>
using namespace std;

class ElUniversidade : public Identificador 
{
private:

	ElUniversidade* proximo;
	ElUniversidade* anterior;
	Universidade* p_univ;

public:

	ElUniversidade();
	~ElUniversidade();

	void set_elem_proximo (ElUniversidade* prox);
	void set_elem_anterior(ElUniversidade* ant);

	ElUniversidade* get_elem_proximo();
	ElUniversidade* get_elem_anterior();

	void set_pUniv(Universidade* universidade);
	Universidade* get_p_univ();

	string getName();
};