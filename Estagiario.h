#pragma once
#include "Aluno.h"

class Estagiario : public Aluno
{
private:
	float bolsa_estudos;

public:
	Estagiario();
	~Estagiario();
	void informa_proventos();
};

