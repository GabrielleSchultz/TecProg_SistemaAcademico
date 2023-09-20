#pragma once

#include "Professor.h"
#include "Aluno.h"

#include "ListaPessoas.h"
#include "ListaAlunos.h"
#include "ListaDepartamentos.h"
#include "ListaDisciplinas.h"
#include "ListaUniversidades.h"
#include "ListaProfessores.h"

class Principal{
private:
	
	//contadores de ID:
	int contID_Alunos;
	int contID_Professores;
	int contID_Disciplinas;
	int contID_Departamentos;
	int contID_Universidades;

	/* Variáveis Estáticas: */

	//professores:
	Professor Einstein;
	Professor Newton;
	Professor Simao;
	Professor Dorini;

	//alunos:
	Aluno Gabi;
	Aluno Michat;

	//universidades:
	Universidade Cambridge;
	Universidade Princeton;
	Universidade UTFPR;

	//departamentos:
	Departamento Princeton_Physics;
	Departamento Cambridge_Math; 
	Departamento UTFPR_DAINF;
	Departamento UTFPR_DAMAT;

	//disciplinas:
	Disciplina Quantum_Physics_PRIN2023;
	Disciplina Algebra_CAM2023;
	Disciplina TecProg_UTF2023;
	Disciplina Topicos_UTF2023;

	/*----*/

	//listas:
	ListaDisciplinas L_Disciplinas;
	ListaDepartamento L_Departamentos;
	ListaUniversidade L_Universidades;
	ListaAlunos L_Alunos;
	ListaProfessor L_Professores;
	ListaPessoas L_Pessoas;

	//data:
	int mes_atual;
	int ano_atual;
	int dia_atual;

public:

	//incialização (obj. estáticos):

	Principal();  
	~Principal();	 
	void Inicializa();
	void inicializaProfessores();
	void inicializaAlunos();
	void inicializaUniversidades();
	void inicializaDepartamentos();
	void inicializaDisciplinas();

	//execução:
	void Executar();
	void calculaIdadeProf();
	void calculaIdadeAluno();
	void imprimeIdadeProf();
	void imprimeIdadeAluno();
	void univOndeProfsTrabalham();
	void depOndeProfsTrabalham();
	void univOndeAlunosEstudam();
	void lista_DisclinasDeptos();
	void lista_DptosUniversidades();
	void listaAlunosDisciplinas();

	//menu:
	void Menu();
	void MenuCad();		
	void MenuExe();		
	void MenuGravar();
	void MenuRecuperar();

	//cadastro:
	void CadDisciplina();
	void CadAluno();
	void CadProfessor();
	void CadUniversidade();
	void CadDepartamento();
	//void CadNotas();

	//gravar:
	void GravarTudo();
	void GravarAlunos();
	void GravarProfessores();
	void GravarUniversidades();
	void GravarDepartamentos();
	void GravarDisciplinas();

	//recuperar:
	void RecuperarTudo();
	void RecuperarAlunos();
	void RecuperarProfessores();
	void RecuperarUniversidades();
	void RecuperarDepartamentos();
	void RecuperarDisciplinas();
};