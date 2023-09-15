#include "ElemUniversidade.h"

#include <iostream>
using std::add_lvalue_reference;	//NULL value

ElUniversidade::ElUniversidade()
{
	proximo = NULL;
	anterior = NULL;
	p_univ = NULL;
}

ElUniversidade::~ElUniversidade()
{
	proximo = NULL;
	anterior = NULL;
	p_univ = NULL;
}

void ElUniversidade::set_elem_proximo(ElUniversidade* prox)
{
	proximo = prox;
}

void ElUniversidade::set_elem_anterior (ElUniversidade* ant)
{
	anterior = ant;
}

ElUniversidade* ElUniversidade::get_elem_proximo()
{
	return proximo;
}

ElUniversidade* ElUniversidade::get_elem_anterior()
{
	return anterior;
}

void ElUniversidade::set_pUniv(Universidade* universidade)
{
	p_univ = universidade;
}

Universidade* ElUniversidade::get_p_univ()
{
	return p_univ;
}

string ElUniversidade::getName()
{
	return p_univ->get_univ_name();
}


