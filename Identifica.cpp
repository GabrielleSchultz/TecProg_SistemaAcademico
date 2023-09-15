#include "Identifica.h"

Identificador::Identificador(int id_num, int s_value)
{
	id = id_num;
	is_static = s_value;
}

Identificador::~Identificador()
{
}

int Identificador::static_verify()
{
	if (is_static)
		return 1;
	else
		return 0;
}

void Identificador::set_static_value(int value)
{
	is_static = value;
}

