#include <iostream>
using namespace std;

#include "Professor.h"

Professor::Professor(int setId) :
	Academico(setId)
{
	salario = 0.0;
}

Professor::~Professor()
{
}

Professor::Professor(int dia_nasc, int mes_nasc, int ano_nasc, string nome_prof) :
Academico(dia_nasc, mes_nasc, ano_nasc, nome_prof)
{
	salario = 0.0;
}

void Professor::onde_trabalha()
{
	if (p_univ_filiada != NULL)
		cout << nome_pessoa << " trabalha em: " << p_univ_filiada->get_univ_name() << endl;
	else
		cout << nome_pessoa << "não está vinculada a nenhuma Universidade" << endl;
}

void Professor::onde_trabalha_dpto()
{
	if (p_univ_filiada != NULL)
		cout << nome_pessoa << " trabalha na " << p_univ_filiada->get_univ_name() << " no "
		<< p_dpto_filiado->get_dpto_name() << endl;
	else
		cout << nome_pessoa << "não está vinculada a nenhum departamento dentro da Universidade" << endl;
}

float Professor::informa_proventos()
{
	return salario + bolsa_projeto;
}

