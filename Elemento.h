#pragma once
#include "Identifica.h"

#include <string>
using std::string;

//declaração

template <class TIPO>
class Elemento : public Identificador
{
private:
	Elemento<TIPO>* p_proximo;
	Elemento<TIPO>* p_anterior;
	TIPO* p_referencia;

public:
	Elemento();
	~Elemento();

	void set_proximo(Elemento<TIPO>* prox);
	Elemento<TIPO>* get_proximo();
	void set_anterior(Elemento<TIPO>* ant);
	Elemento<TIPO>* get_anterior();
	void set_referencia(TIPO* info);
	TIPO* get_referencia();
};

//implementaçao:

template <class TIPO>
Elemento<TIPO>::Elemento() {
	p_proximo = NULL;
	p_anterior = NULL;
	p_referencia = NULL;
}

template <class TIPO>
Elemento<TIPO>::~Elemento() {
	p_proximo = NULL;
	p_anterior = NULL;
	p_referencia = NULL;
}

template <class TIPO>
void Elemento<TIPO>::set_proximo(Elemento<TIPO>* prox) {
	p_proximo = prox;
}

template<class TIPO>
Elemento<TIPO>* Elemento<TIPO>::get_proximo()
{
	return p_proximo;
}

template <class TIPO>
void Elemento<TIPO>::set_anterior(Elemento<TIPO>* ant) {
	p_anterior = ant;
}

template<class TIPO>
Elemento<TIPO>* Elemento<TIPO>::get_anterior()
{
	return p_anterior;
}

template <class TIPO>
void Elemento<TIPO>::set_referencia(TIPO* info) {
	p_referencia = info;
}

template<class TIPO>
TIPO* Elemento<TIPO>::get_referencia()
{
	return p_referencia;
}

