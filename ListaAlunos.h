#pragma once
#include "ElemAluno.h"

#include <fstream>
#include <string>
using namespace std;

#include "Lista.h"

class Aluno;

class ListaAlunos : public Identificador {

private:

	Lista<Aluno> template_listaAlunos;

public:
	ListaAlunos(int n_alunos = 50);
	~ListaAlunos();

	void inclue_aluno(Aluno* p_aluno);
	void lista_alunos();
	Aluno* localizar(string nome_aluno);
	int get_num_alunos();
	void gravar_alunos();
	void recuperar_alunos();
	void limpa_lista();
};