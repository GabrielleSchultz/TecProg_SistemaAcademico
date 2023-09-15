#pragma once

#include <fstream>
using std::ifstream;
using std::ofstream;

#include <iostream>
using std::cerr;
using std::endl;

#include <algorithm>
using std::replace;

#include "Elemento.h"

template <class TIPO>
class Lista {

private:
	Elemento<TIPO>* primeiro;
	Elemento<TIPO>* ultimo;

	int num_elementos;
	int max_elementos;

	bool inclue_elemento(Elemento<TIPO>* p_elemento);

public:

	Lista();
	~Lista();

	bool incluir(TIPO* p_info);

	void inicializa(); 

	Elemento<TIPO>* get_primeiro();
	Elemento<TIPO>* get_ultimo();

	void set_primeiro(Elemento<TIPO>* primeiro_elem);
	void set_ultimo(Elemento<TIPO>* ultimo_elem);

	int get_num_elementos();
	void set_max_elementos(int max);

	void limpar();
};

template <class TIPO>
Lista<TIPO>::Lista()
{
	inicializa();
}

template <class TIPO>
Lista<TIPO>::~Lista()
{
	limpar();
	inicializa();
}

template<class TIPO>
bool Lista<TIPO>::inclue_elemento(Elemento<TIPO>* p_elemento)
{
	if (p_elemento && (num_elementos <= max_elementos || max_elementos == -1))
	{
		if (primeiro == NULL)
		{
			primeiro = p_elemento;
			ultimo = p_elemento;
		}
		else
		{
			ultimo->set_proximo(p_elemento);
			p_elemento->set_anterior(ultimo);
			ultimo = p_elemento;
		}
		num_elementos++;
		return true;
	}
	else
	{
		cerr << "Erro: elemento nulo na lista" << endl;
		return false;
	}
}

template <class TIPO>
bool Lista<TIPO>::incluir(TIPO* p_info)
{
	if (p_info != NULL)
	{
		Elemento<TIPO>* p_elemento = new Elemento<TIPO>();
		p_elemento->set_referencia(p_info);
		inclue_elemento(p_elemento);
		return true;
	}
	else
	{
		cerr << "Erro: ponteiro nulo na lista." << endl;
		return false;
	}
}

template <class TIPO>
void Lista<TIPO>::inicializa()
{
	Elemento<TIPO>* primeiro = NULL;
	Elemento<TIPO>* ultimo = NULL;

	max_elementos = -1;
	num_elementos = 0;
}

template<class TIPO>
Elemento<TIPO>* Lista<TIPO>::get_primeiro()
{
	return primeiro;
}

template <class TIPO>
Elemento<TIPO>* Lista<TIPO>::get_ultimo()
{
	return ultimo;
}

template <class TIPO>
void Lista<TIPO>::set_primeiro(Elemento<TIPO>* primeiro_elem)
{
	primeiro = primeiro_elem;
}

template <class TIPO>
void Lista<TIPO>::set_ultimo(Elemento<TIPO>* ultimo_elem)
{
	primeiro = ultimo_elem;
}

template<class TIPO>
int Lista<TIPO>::get_num_elementos()
{
	return num_elementos;
}

template<class TIPO>
void Lista<TIPO>::set_max_elementos(int max)
{
	max_elementos = max;
}

template<class TIPO>
void Lista<TIPO>::limpar()
{
	Elemento<TIPO>* aux = primeiro;

	while (aux != NULL)
	{
		primeiro = primeiro->get_proximo();
		delete aux;
		aux = primeiro;
	}
	num_elementos = 0;
}

