#pragma once

class Identificador
{
protected:
	int id;
	int is_static;

public:
	Identificador(int id_num = 0, int s_value = 1);
	~Identificador();

	void set_id(int ID) { id = ID; };
	int get_id() { return id; };
	int static_verify();
	void set_static_value(int value);
};