#pragma once

//classe de associação (Aluno e Disciplina)
//implementa a relação de n_alunos para n_disciplinas sem sobrescrever relações

#include "Identifica.h"

#include <string>
using namespace std;

class Aluno;
//class Notas;

class ElAluno : public Identificador {

private:

	ElAluno* p_proximo;
	ElAluno* p_anterior;
	Aluno* p_aluno;
	//Notas* p_notas;

public:
	ElAluno();
	~ElAluno();
	void set_prox_aluno(ElAluno* proximo_aluno);
	void set_ant_aluno(ElAluno* anterior_aluno);
	ElAluno* get_prox_aluno();
	ElAluno* get_ant_aluno();
	void set_aluno(Aluno* aluno);
	Aluno* get_aluno();
	string get_nome();
	//Notas* get_nota();
};