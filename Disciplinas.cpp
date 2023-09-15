#include "Disciplinas.h"
#include "Departamento.h"

#include <string>
#include <iostream>
using namespace std;

Disciplina::Disciplina(int n_alunos, int setId) :
	obj_listaAlunos (n_alunos)
{
	strcpy_s(area_conhecimento, sizeof area_conhecimento, "");
	nome_disciplina = "";
	max_alunos = n_alunos;
	alunos_matriculados = 0;
	p_dpto_associado = NULL;

	id = setId;
}

Disciplina::~Disciplina()
{
	p_dpto_associado = NULL;
}

void Disciplina::set_subj_name(string nome)
{
	nome_disciplina = nome;
}

string Disciplina::get_subj_name()
{
	return nome_disciplina;
}

void Disciplina::set_dpto_associado(Departamento* dpto_disciplina)
{
	p_dpto_associado = dpto_disciplina;
	dpto_disciplina->set_subject(this);
}

Departamento* Disciplina::get_dpto_associado()
{
	return p_dpto_associado;
}

void Disciplina::inclue_aluno(Aluno* p_aluno)
{
	obj_listaAlunos.inclue_aluno(p_aluno);
}

void Disciplina::lista_alunos() {

	cout << "Alunos matriculados na disciplina " << nome_disciplina << " : \n" << endl;
	obj_listaAlunos.lista_alunos();
}
