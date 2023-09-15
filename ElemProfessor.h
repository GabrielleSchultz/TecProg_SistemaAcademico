#pragma once

#include "Professor.h"

class ElProfessor : public Identificador{

private:

	ElProfessor* elprof_proximo;
	ElProfessor* elprof_anterior;
	Professor* p_professor;

public:
	ElProfessor();
	~ElProfessor();
	void set_proximo(ElProfessor* p_prox);
	void set_anterior(ElProfessor* p_ant);
	ElProfessor* get_proximo();
	ElProfessor* get_anterior();
	string get_name();
	void set_professor(Professor* p_prof);
	Professor* get_professor();
};