#pragma once

#include "ListaAlunos.h"

class Departamento;

class Disciplina : public Identificador{
private:

	string nome_disciplina;
	char area_conhecimento[100];
	int max_alunos;
	int alunos_matriculados;

	Departamento* p_dpto_associado;
	ListaAlunos obj_listaAlunos;


public:
	Disciplina(int n_alunos = 45, int setId = -1);
	~Disciplina();
	void set_subj_name(string nome);
	string get_subj_name();
	void set_dpto_associado(Departamento* dpto_disciplina);
	Departamento* get_dpto_associado();
	void inclue_aluno(Aluno* p_aluno);
//	void remove_aluno(Aluno* p_aluno);
	void lista_alunos();

};