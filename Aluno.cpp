#include "iostream"
using namespace std;

#include "Aluno.h"

#define RA_MIN 1000000
#define RA_MAX 10000000


Aluno::Aluno(int setId):
	Academico(setId)
{
	RA = 0;
	CR = 0;
}

Aluno::~Aluno() 
{
}

Aluno::Aluno(int dia_nasc, int mes_nasc, int ano_nasc, string nome) :
Academico (dia_nasc, mes_nasc, ano_nasc, nome)
{
	RA = 0;
	CR = 0;
}

void Aluno::onde_estuda() 
{
	cout << nome_pessoa << " estuda na " << p_univ_filiada->get_univ_name() << endl;
}

void Aluno::set_RA(int registro_academico)
{
	if (registro_academico > RA_MIN && registro_academico < RA_MAX)	//verifica se o RA tem 7 digitos
		RA = registro_academico;
	else
		cout << "ERRO: RA invalido atribuido a " << nome_pessoa << endl;
}

const int Aluno::get_RA()
{
	return RA;
}

