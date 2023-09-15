#pragma once

//classe para atribuir notas aos alunos:
//nao funcionando no momento, verificar com a monitoria assim que possivel

#include "Aluno.h"
class Notas
{
private:

	int faltas;
	float nota_P1;
	float nota_P2;
	float nota_final;

	Aluno* p_aluno;

public:
	Notas(int num_faltas = 0, float n_p1 = 0.0, float n_p2 = 0.0, float n_final = 0.0, Aluno* aluno = NULL);
	~Notas();
	void set_primeira_nota(float n1);
	float get_primeira_nota();
	void set_segunda_nota(float n2);
	float get_segunda_nota();
	void set_nota_final(float n_final);
	float get_nota_final();
	void set_faltas(int n_faltas);
	int get_faltas();
	void set_aluno(Aluno* aluno);
};

