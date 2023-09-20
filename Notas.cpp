#include "Notas.h"

Notas::Notas(int num_faltas, float n_p1, float n_p2, float n_final, Aluno* aluno)
{
	faltas = num_faltas;
	nota_P1 = n_p1;
	nota_P2 = n_p2;
	nota_final = n_final;
	p_aluno = aluno;
}

Notas::~Notas()
{
	p_aluno = NULL;
}

void Notas::set_primeira_nota(float n1)
{
	nota_P1 = n1;
}

const float Notas::get_primeira_nota()
{
	return nota_P1;
}

void Notas::set_segunda_nota(float n2)
{
	nota_P2 = n2;
}

const float Notas::get_segunda_nota()
{
	return nota_P2;
}

void Notas::set_nota_final(float n_final)
{
	nota_final = n_final;
}

const float Notas::get_nota_final()
{
	return nota_final;
}

void Notas::set_faltas(int n_faltas)
{
	faltas = n_faltas;
}

const int Notas::get_faltas()
{
	return faltas;
}

void Notas::set_aluno(Aluno* aluno)
{
	p_aluno = aluno;
}

