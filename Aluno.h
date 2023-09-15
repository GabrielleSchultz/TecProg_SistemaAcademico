#pragma once

#include "Academico.h"

class Aluno : public Academico {

private:

	int RA;
	float CR;

public:
	Aluno(int setId = -1);
	~Aluno();
	Aluno(int dia_nasc, int mes_nasc, int ano_nasc, string nome);
	void onde_estuda();
	void set_RA(int registro_academico);
	int get_RA();
};