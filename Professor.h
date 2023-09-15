#pragma once

#include "Academico.h"
 
class Professor : public Academico {

private:

	float salario;
	float bolsa_projeto;

public:
	Professor(int setId = -1);
	~Professor();
	Professor(int dia_nasc, int mes_nasc, int ano_nasc, string nome_prof);
	void onde_trabalha();
	void onde_trabalha_dpto();
	float informa_proventos();
};