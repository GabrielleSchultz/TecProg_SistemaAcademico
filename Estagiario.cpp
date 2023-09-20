#include "Estagiario.h"

Estagiario::Estagiario()
{
	bolsa_estudos = 0;
}

Estagiario::~Estagiario()
{
}

void Estagiario::informa_proventos()
{
	cout << "Proventos: " << bolsa_estudos << endl;
}
