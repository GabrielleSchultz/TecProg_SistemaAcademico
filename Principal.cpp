#include "Principal.h"
#include "Windows.h"

#include <iostream>
using namespace std;
#include <fstream>

//configuracao para mensagens de erro:
ostream& error(ostream& os) {
	string errorStr = "Erro: digite uma opcao valida!";
	os << errorStr;
	return os;
}
HANDLE error_message = GetStdHandle(STD_OUTPUT_HANDLE); //atribui mensagem de erro ao buffer de saida


Principal::Principal() :

	//incializa contadores:
	contID_Alunos(0),
	contID_Professores(0),
	contID_Disciplinas(0),
	contID_Departamentos(0),
	contID_Universidades(0),

	//construtores dos objetos:

	//professores:
	Einstein(contID_Professores++),
	Newton(contID_Professores++),
	Simao(contID_Professores++),
	Dorini(contID_Professores++),

	//alunos:
	Gabi(contID_Alunos++),
	Michat(contID_Alunos++),

	//universidades:
	Cambridge(contID_Universidades++),
	Princeton(contID_Universidades++),
	UTFPR(contID_Universidades++),

	//departamentos:
	Princeton_Physics(contID_Departamentos++),
	Cambridge_Math(contID_Departamentos++),
	UTFPR_DAINF(contID_Departamentos++),
	UTFPR_DAMAT(contID_Departamentos++),

	//disciplinas:
	Quantum_Physics_PRIN2023(contID_Disciplinas++),
	Algebra_CAM2023(contID_Disciplinas++),
	TecProg_UTF2023(contID_Disciplinas++),
	Topicos_UTF2023(contID_Disciplinas++)
{
	//data:
	SYSTEMTIME st;
	GetSystemTime(&st);

	dia_atual = st.wDay;
	mes_atual = st.wMonth;
	ano_atual = st.wYear; 

	Inicializa();
	Executar();
}

Principal::~Principal()
{
}

void Principal::Inicializa()
{
	inicializaAlunos();
	inicializaProfessores();
	inicializaUniversidades();
	inicializaDepartamentos();
	inicializaDisciplinas();
}

void Principal::inicializaProfessores()
{
	//inicializa
	Einstein.inicializa(14, 3, 1879, "Einstein");
	Newton.inicializa(4, 1, 1643, "Newton");
	Simao.inicializa(1, 1, 2001, "Jean Simao");
	Dorini.inicializa(1, 1, 2001, "Fabio Dorini");

	//associaçao professor - universidade
	Einstein.set_univ_filiada(&Princeton);
	Newton.set_univ_filiada(&Cambridge);
	Simao.set_univ_filiada(&UTFPR);
	Dorini.set_univ_filiada(&UTFPR);

	//associacao professor - departamento
	Einstein.set_dpto_filiado(&Princeton_Physics);
	Newton.set_dpto_filiado(&Cambridge_Math);
	Simao.set_dpto_filiado(&UTFPR_DAINF);
	Dorini.set_dpto_filiado(&UTFPR_DAMAT);

	L_Professores.inclue_professor(&Simao);
	L_Professores.inclue_professor(&Dorini);

}

void Principal::inicializaAlunos()
{
	Gabi.inicializa (23 , 2 , 2005, "Gabrielle Schultz");
	Michat.inicializa(17, 10, 2005, "Michele Otta");

	Gabi.set_univ_filiada(&UTFPR);
	Michat.set_univ_filiada(&UTFPR);

	Gabi.set_RA(2557983);
	Michat.set_RA(2123456);

	L_Alunos.inclue_aluno(&Gabi);
	L_Alunos.inclue_aluno(&Michat);
}

void Principal::inicializaUniversidades()
{
	Cambridge.set_univ_name("Universidade de Cambridge");
	Princeton.set_univ_name("Universidade de Princeton");
	UTFPR.set_univ_name("Universidade Tecnologica Federal do Parana");

	L_Universidades.inclue_universidade(&UTFPR);
	L_Universidades.inclue_universidade(&Cambridge);
	L_Universidades.inclue_universidade(&Princeton);

}

void Principal::inicializaDepartamentos()
{
	Princeton_Physics.set_dpto_name("Departamento de Fisica de Princeton");
	Cambridge_Math.set_dpto_name("Departamento de Matematica de Cambridge");
	UTFPR_DAINF.set_dpto_name("Departamento de Informatica - DAINF");
	UTFPR_DAMAT.set_dpto_name("Departamento de Matematica - DAMAT");

	//associaçao departamento - universidade 
	Princeton.set_departamento(&Princeton_Physics);
	Cambridge.set_departamento(&Cambridge_Math);
	UTFPR.set_departamento(&UTFPR_DAINF);
	UTFPR.set_departamento(&UTFPR_DAMAT);

	L_Departamentos.inclue_departamento(&UTFPR_DAMAT);
	L_Departamentos.inclue_departamento(&UTFPR_DAINF);
	L_Departamentos.inclue_departamento(&Princeton_Physics);
	L_Departamentos.inclue_departamento(&Cambridge_Math);

}

void Principal::inicializaDisciplinas()
{
	Quantum_Physics_PRIN2023.set_subj_name("Fisica Quantica");
	Algebra_CAM2023.set_subj_name("Algebra");
	TecProg_UTF2023.set_subj_name("Tecnicas de Programacao");
	Topicos_UTF2023.set_subj_name("Topicos Matematicos");

	Quantum_Physics_PRIN2023.set_dpto_associado(&Princeton_Physics);
	Algebra_CAM2023.set_dpto_associado(&Cambridge_Math);
	TecProg_UTF2023.set_dpto_associado(&UTFPR_DAINF);
	Topicos_UTF2023.set_dpto_associado(&UTFPR_DAMAT);

	TecProg_UTF2023.inclue_aluno(&Michat);
	TecProg_UTF2023.inclue_aluno(&Gabi);

	L_Disciplinas.set_subject(&Topicos_UTF2023);
	L_Disciplinas.set_subject(&TecProg_UTF2023);
	L_Disciplinas.set_subject(&Quantum_Physics_PRIN2023);
	L_Disciplinas.set_subject(&Algebra_CAM2023);

}

void Principal::Executar()
{
	Menu();
}

void Principal::calculaIdadeProf()
{
	Einstein.calcula_idade(dia_atual, mes_atual, ano_atual);
	Newton.calcula_idade(dia_atual, mes_atual, ano_atual);
}

void Principal::calculaIdadeAluno()
{
	Michat.calcula_idade(dia_atual, mes_atual, ano_atual);
	Gabi.calcula_idade(dia_atual, mes_atual, ano_atual);
}

void Principal::imprimeIdadeProf()
{
	Einstein.imprime_idade();
	Newton.imprime_idade();
	printf("\n");
}

void Principal::imprimeIdadeAluno()
{
	Michat.imprime_idade();
	Gabi.imprime_idade();
	printf("\n");
}

void Principal::univOndeProfsTrabalham()
{
	Einstein.onde_trabalha();
	Newton.onde_trabalha();
	Simao.onde_trabalha();
	Dorini.onde_trabalha();
	printf("\n");
}

void Principal::depOndeProfsTrabalham()
{
	Einstein.onde_trabalha_dpto();
	Newton.onde_trabalha_dpto();
	Simao.onde_trabalha_dpto();
	Dorini.onde_trabalha_dpto();
	printf("\n");

}

void Principal::lista_DptosUniversidades()
{
	Cambridge.imprimeDptos();
	Princeton.imprimeDptos();
	UTFPR.imprimeDptos();
	printf("\n");
}

void Principal::lista_DisclinasDeptos()
{
	Cambridge_Math.imprime_disciplinas_first_to_last();
	UTFPR_DAINF.imprime_disciplinas_first_to_last();
	UTFPR_DAMAT.imprime_disciplinas_first_to_last();
	printf("\n");
}

void Principal::univOndeAlunosEstudam() {

	Michat.onde_estuda();
	Gabi.onde_estuda();
	printf("\n");
}

void Principal::listaAlunosDisciplinas() {

	TecProg_UTF2023.lista_alunos();
}


//implementação do menu:

void Principal::Menu()
{
	int option = -1;

	while (option != 5)
	{
		system("cls");
		system("color 0E");

		cout << "----------       Menu      -----------\n" << endl;
		cout << "Informe sua opcao: \n \n" << endl;

		cout << "1 - Cadastro " << endl;
		cout << "2 - Executar" << endl;
		cout << "3 - Gravar" << endl;
		cout << "4 - Recuperar" << endl;
		cout << "5 - Fechar Menu\n" << endl;

		cout.width(40);
		cout.fill('-');
		cout << " \n" << endl;


		cin >> option;

		switch (option)
		{
			case 1: 
			{
				MenuCad();
			}
			break;

			case 2: 
			{
				MenuExe();
			} 
			break;

			case 3:
			{
				MenuGravar();
			}
			break;

			case 4:
			{
				MenuRecuperar();
			}
			break;

			case 5: 
			{
				system("cls");
				cout << "\nMenu Fechado.\n" << endl;
				system("Pause");

			} break;

			default: 
			{
				SetConsoleTextAttribute(error_message, 4);
				cout << error << endl;
				system("Pause");
			}
			break;
		}
	}
}

void Principal::MenuCad()
{
	int option = -1;

	while (option != 7)
	{
		system("cls");
		system("color 0E");

		cout.width(40);
		cout.fill('-');
		cout << "\n" << endl;

		cout << "-- Cadastro\n" << endl;
		cout << "Escolha o elemento que deseja cadastrar: \n \n" << endl;

		cout << "1 - Cadastrar Aluno " << endl;
		cout << "2 - Cadastrar Professor " << endl;
		cout << "3 - Cadastrar Disciplina" << endl;
		cout << "4 - Cadastrar Departamento" << endl;
		cout << "5 - Cadastrar Universidade" << endl;
		cout << "6 - Cadastrar Nota" << endl;
		cout << "7 - Voltar \n" << endl;

		cout.width(40);
		cout.fill('-');
		cout << "\n" << endl;

		cin >> option;

		switch (option)
		{
		case 1:
		{
			CadAluno();
		}
		break;

		case 2:
		{
			CadProfessor();
		}
		break;

		case 3:
		{
			CadDisciplina();
		}
		break;

		case 4:
		{
			CadDepartamento();

		} break;

		case 5:
		{
			CadUniversidade();

		} break;

		case 6:
		{
			//CadNotas();

		} break;

		case 7:
		{
			system("cls");
			getchar();
		} break;

		default:
		{
			SetConsoleTextAttribute(error_message, 4);
			cout << error << endl;
			system("Pause");
		}
		break;
		}
	}
}

void Principal::MenuExe()
{
	int option = -1;

	while (option != 6)
	{
		system("cls");
		system("color 0E");

		cout.width(40);
		cout.fill('-');
		cout << "\n" << endl;

		cout << "Informe uma opcao: \n \n" << endl;

		cout << "0 - Listar tudo" << endl;
		cout << "1 - Listar Alunos " << endl;
		cout << "2 - Listar Professores " << endl;
		cout << "3 - Listar Disciplinas" << endl;
		cout << "4 - Listar Departamentos" << endl;
		cout << "5 - Listar Universidades" << endl;
		cout << "6 - Voltar\n" << endl;

		cout.width(40);
		cout.fill('-');
		cout << "\n" << endl;

		cin >> option;

		switch (option)
		{
			case 0:
			{
				system("cls");
				cout << "--Elementos registrados no sistema: \n" << endl;
				cout << L_Alunos.get_num_alunos() << " alunos registrados." << endl;
				cout << L_Professores.get_num_professores() << " professores registrados" << endl;
				cout << L_Disciplinas.get_num_disciplinas() << " disciplinas registradas." << endl;
				cout << L_Departamentos.get_num_dptos() << " departamentos registrados" << endl;
				cout << L_Universidades.get_num_univs() << " universidades registradas." << endl;
				cout.width(50);
				cout.fill('-');
				
				cout << "\nAlunos cadastrados: " << endl;
				L_Alunos.lista_alunos();
				cout << "\nProfessores cadastrados: " << endl;
				L_Professores.imprime_professores();
				cout << "\nDisciplinas cadastradas: " << endl;
				L_Disciplinas.imprime_disciplinas_first_to_last();
				cout << "\nDepartamentos cadastrados: " << endl;
				L_Departamentos.imprime_departamentos();
				cout << "\nUniversidades cadastradas: " << endl;
				L_Universidades.imprime_universidades();

				cout << "\nPressione qualquer tecla para voltar" << endl;
				cin >> ws;
				getchar();	
			}
			break;

			case 1:
			{
				system("cls");
				cout << " -- Alunos:\n" << endl;
				cout << L_Alunos.get_num_alunos() << " alunos cadastrados no sistema.\n" << endl;
				cout << "-- Lista de Alunos cadastrados: " << endl;
				L_Alunos.lista_alunos();
				cout << "\nPressione qualquer tecla para voltar" << endl;
				cin >> ws;
				getchar();
			}
			break;

			case 2:
			{
				system("cls");
				cout << " -- Professores:\n" << endl;
				cout << L_Professores.get_num_professores() << " professores cadastrados no sistema.\n" << endl;
				cout << "-- Lista de Professores cadastrados: " << endl;
				L_Professores.imprime_professores();
				cout << "\nPressione qualquer tecla para voltar" << endl;
				cin >> ws;
				getchar();
			}
			break;

			case 3:
			{
				system("cls");
				cout << " -- Disciplinas:\n" << endl;
				cout << L_Disciplinas.get_num_disciplinas() << " disciplinas cadastradas no sistema.\n" << endl;
				cout << "Lista de Disciplinas cadastradas: " << endl;
				L_Disciplinas.imprime_disciplinas_first_to_last();
				cout << "\nPressione qualquer tecla para voltar" << endl;
				cin >> ws;
				getchar();
			}
			break;

			case 4:
			{
				system("cls");
				cout << " -- Departamentos:\n" << endl;
				cout << L_Departamentos.get_num_dptos() << " departamentos cadastrados no sistema.\n" << endl;
				cout << "Lista de Departamentos cadastrados: " << endl;
				L_Departamentos.imprime_departamentos();
				cout << "\nPressione qualquer tecla para voltar" << endl;
				cin >> ws;
				getchar();

			} break;

			case 5:
			{
				system("cls");
				cout << " -- Universidades:\n" << endl;
				cout << L_Universidades.get_num_univs() << " universidades cadastradas no sistema.\n" << endl;
				cout << "--Lista de Universidades cadastradas : " << endl;
				L_Universidades.imprime_universidades();
				cout << "\nPressione qualquer tecla para voltar" << endl;
				cin >> ws;
				getchar();

			} break;

			case 6:
			{
				system("cls");
				getchar();
			} break;

			default:
			{
				SetConsoleTextAttribute(error_message, 4);
				cout << error << endl;
				system("Pause");
			}
			break;
		}
	}
}

void Principal::MenuGravar()
{
	int option = -1;

	while (option != 6)
	{
		system("cls");
		system("color 0E");

		cout.width(40);
		cout.fill('-');
		cout << "\n" << endl;

		cout << "-- Gravar:" << endl;
		cout << "Informe sua opcao\n" << endl;

		cout << "0 - Gravar Tudo" << endl;
		cout << "1 - Gravar Alunos " << endl;
		cout << "2 - Gravar Professores " << endl;
		cout << "3 - Gravar Disciplinas" << endl;
		cout << "4 - Gravar Departamentos" << endl;
		cout << "5 - Gravar Universidades" << endl;
		cout << "6 - Voltar" << endl;

		cout.width(40);
		cout.fill('-');
		cout << "\n" << endl;

		cin >> option;

		switch (option)
		{
		case 0:
		{
			GravarTudo();
			cout << "\nTodos os cadastros foram gravados.\n" << endl;
			cout << "Pressione qualquer tecla para voltar" << endl;
			cin >> ws;
			getchar();
		}
		break;

		case 1:
		{				
			GravarAlunos();
			cout << "\nOs alunos cadastrados foram gravados.\n" << endl;
			cout << "Pressione qualquer tecla para voltar" << endl;
			cin >> ws;
			getchar();
		}
		break;

		case 2:
		{
			GravarProfessores();
			cout << "\nOs professores cadastrados foram gravados.\n" << endl;
			cout << "Pressione qualquer tecla para voltar" << endl;
			cin >> ws;
			getchar();
		}
		break;

		case 3:
		{
			GravarDisciplinas();
			cout << "\nAs disciplinas cadastradas foram gravadas.\n" << endl;
			cout << "Pressione qualquer tecla para voltar" << endl;
			cin >> ws;
			getchar();
		}
		break;

		case 4:
		{
			GravarDepartamentos();
			cout << "\nOs departamentos cadastrados foram gravados.\n" << endl;
			cout << "Pressione qualquer tecla para voltar" << endl;
			cin >> ws;
			getchar();
		}
		break;

		case 5:
		{
			GravarUniversidades();
			cout << "\nAs universidades cadastradas foram gravadas.\n" << endl;
			cout << "Pressione qualquer tecla para voltar" << endl;
			cin >> ws;
			getchar();
		}
		break;

		case 6:
		{
			system("cls");
			getchar();
		}
		break;

		default:
		{
			SetConsoleTextAttribute(error_message, 4);
			cout << error << endl;
			system("Pause");
		}
		break;
		}
	}
}

void Principal::MenuRecuperar()
{
	int option = -1;

	while (option != 6)
	{
		system("cls");
		system("color 0E");

		cout.width(40);
		cout.fill('-');
		cout << "\n" << endl;

		cout << "-- Recuperar:" << endl;
		cout << "Informe sua opcao\n" << endl;

		cout << "0 - Recuperar Tudo" << endl;
		cout << "1 - Recuperar Alunos " << endl;
		cout << "2 - Recuperar Professores " << endl;
		cout << "3 - Recuperar Disciplinas" << endl;
		cout << "4 - Recuperar Departamentos" << endl;
		cout << "5 - Recuperar Universidades" << endl;
		cout << "6 - Voltar" << endl;

		cout.width(40);
		cout.fill('-');
		cout << "\n" << endl;

		cin >> option;

		switch (option)
		{
		case 0:
		{
			RecuperarTudo();
			cout << "Pressione qualquer tecla para voltar" << endl;
			cin >> ws;
			getchar();
		}
		break;

		case 1:
		{
			RecuperarAlunos();
			cout << "Pressione qualquer tecla para voltar" << endl;
			cin >> ws;
			getchar();
		}
		break;

		case 2:
		{
			RecuperarProfessores();
			cout << "Pressione qualquer tecla para voltar" << endl;
			cin >> ws;
			getchar();
		}
		break;

		case 3:
		{
			RecuperarDisciplinas();
			cout << "Pressione qualquer tecla para voltar" << endl;
			cin >> ws;
			getchar();
		}
		break;

		case 4:
		{
			RecuperarDepartamentos();
			cout << "Pressione qualquer tecla para voltar" << endl;
			cin >> ws;
			getchar();
		}
		break;

		case 5:
		{
			RecuperarUniversidades();
			cout << "Pressione qualquer tecla para voltar" << endl;
			cin >> ws;
			getchar();
		}
		break;

		case 6:
		{
			system("cls");
			getchar();
		}
		break;

		default:
		{
			SetConsoleTextAttribute(error_message, 4);
			cout << error << endl;
			system("Pause");
		}
		break;
		}
	}
}
	

void Principal::CadDisciplina()
{
	Disciplina* p_disciplina = NULL;
	string nome_disciplina;

	Departamento* p_dpto = NULL;
	string nome_dpto;

	cout << "\nEm qual departamento deseja cadastra-la?" << endl;
	fflush(stdin);

	while (getline(cin, nome_dpto))
		if (nome_dpto != "")
			break;

	p_dpto = L_Departamentos.localizar(nome_dpto);

	if (p_dpto != NULL)
	{
		cout << "- Nome da Disciplina: " << endl;
		fflush(stdin);
		
		while (getline(cin, nome_disciplina))
			if (nome_disciplina != "")
				break;

		p_disciplina = new Disciplina();
		p_disciplina->set_subj_name(nome_disciplina);
		p_disciplina->set_dpto_associado(p_dpto);

		p_disciplina->set_static_value(0);
		L_Disciplinas.set_subject(p_disciplina);
	}
	else
	{
		cerr << "Erro: Departamento nao encontrado" << endl;
		system("Pause");
	}
}

void Principal::CadAluno()
{
	Aluno* p_aluno = NULL;

	string nome_aluno;
	int ra_aluno = 0;
	int dia_nasc = 0;
	int mes_nasc = 0;
	int ano_nasc = 0;

	Universidade* p_univ = NULL;
	string nome_univ;

	cout << "Em qual universidade deseja cadastra-lo(a)?" << endl;
	fflush(stdin);

	while (getline(cin, nome_univ))
		if (nome_univ != "")
			break;

	p_univ = L_Universidades.localizar(nome_univ);

	if (p_univ != NULL)
	{
		cout << "- Nome do(a) Aluno(a): " << endl;
		fflush(stdin);

		while (getline(cin, nome_aluno))
			if (nome_aluno != "")
				break;

		cout << "- RA (registro academico) do(a) Aluno(a): " << endl;
		fflush(stdin);
		cin >> ra_aluno;

		if (ra_aluno == 0)
			system("Pause");

		cout << "Data de Nascimento : (dia / mes / ano)" << endl;

		char caractere;

		cin >> dia_nasc;
		cin.get(caractere);
		cin >> mes_nasc;
		cin.get(caractere);
		cin >> ano_nasc;

		p_aluno = new Aluno(contID_Alunos++);
		p_aluno->inicializa(dia_nasc, mes_nasc, ano_nasc, nome_aluno);
		p_aluno->set_univ_filiada(p_univ);
		p_aluno->set_RA(ra_aluno);

		p_aluno->set_static_value(0);
		L_Alunos.inclue_aluno(p_aluno);

		cout << "\nAluno cadastrado com sucesso.\n" << endl;
		system("Pause");
	}
	else
	{
		cerr << "Erro: Universidade nao encontrada" << endl;
		system("Pause");
	}
}


void Principal::CadProfessor()
{
	Professor* p_prof = NULL;

	string nome_prof;
	int dia_nasc = 0;
	int mes_nasc = 0;
	int ano_nasc = 0;

	Universidade* p_univ = NULL;
	string nome_univ;

	cout << "Em qual universidade deseja cadastra-lo(a)?" << endl;
	fflush(stdin);

	while (getline(cin, nome_univ))
		if (nome_univ != "")
			break;

	p_univ = L_Universidades.localizar(nome_univ);

	if (p_univ != NULL)
	{
		Disciplina* p_subj = NULL;
		string nome_subj;

		cout << "Em qual disciplina deseja cadastra-lo(a)?" << endl;
		fflush(stdin);

		while (getline(cin, nome_subj))
			if (nome_subj != "")
				break;

		p_subj = L_Disciplinas.localizar(nome_subj);

		if (p_subj != NULL)
		{

			cout << "- Nome do(a) Professor(a): " << endl;
			fflush(stdin);

			while (getline(cin, nome_prof))
				if (nome_prof != "")
					break;

			cout << "Data de Nascimento : (dia / mes / ano)" << endl;

			char caractere;

			cin >> dia_nasc;
			cin.get(caractere);
			cin >> mes_nasc;
			cin.get(caractere);
			cin >> ano_nasc;

			p_prof = new Professor();
			p_prof->inicializa(dia_nasc, mes_nasc, ano_nasc, nome_prof);
			p_prof->set_univ_filiada(p_univ);
			p_prof->set_disciplina_associada(p_subj);

			p_prof->set_static_value(0);
			L_Professores.inclue_professor(p_prof);

			cout << "\nProfessor cadastrado com sucesso.\n" << endl;
			system("Pause");
		}
		else
		{
			cout << "Erro: Disciplina nao encontrada" << endl;
			system("Pause");
		}
	}
	else
	{
		cerr << "Erro: Universidade nao encontrada" << endl;
		system("Pause");
	}
}


void Principal::CadUniversidade()
{
	string nome_universidade;

	cout << "- Qual o nome da Universidade? " << endl;
	fflush(stdin);
	
	while (getline(cin, nome_universidade))
		if (nome_universidade != "")
			break;

	Universidade* p_universidade = new Universidade();
	p_universidade->set_univ_name(nome_universidade);

	p_universidade->set_static_value(0);
	L_Universidades.inclue_universidade(p_universidade);

	cout << "\nUniversidade cadastrada com sucesso.\n" << endl;
	system("Pause");
}

void Principal::CadDepartamento()
{
	Departamento* p_dpto = NULL;
	string nome_dpto;

	Universidade* p_univ = NULL;
	string nome_univ;

	cout << "\n Em qual universidade deseja cadastra-lo?" << endl;
	fflush(stdin);

	while (getline(cin, nome_univ))
		if (nome_univ != "")
			break;

	p_univ = L_Universidades.localizar(nome_univ);

	if (p_univ != NULL)
	{
		cout << "- Nome do Departamento: " << endl;
		fflush(stdin);

		while (getline(cin, nome_dpto))
			if (nome_dpto != "")
				break;

		p_dpto = new Departamento();
		p_dpto->set_dpto_name(nome_dpto);
		p_dpto->set_univ(p_univ);

		p_dpto->set_static_value(0);
		L_Departamentos.inclue_departamento(p_dpto);

		cout << "Departamento cadastrado com sucesso." << endl;
		system("Pause");
	}
	else
	{
		cerr << "Erro: Departamento nao encontrado" << endl;
		system("Pause");
	}
}

void Principal::GravarTudo()
{
	L_Alunos.gravar_alunos();
	L_Professores.gravar_professores();
	L_Disciplinas.gravar_disciplinas();
	L_Departamentos.gravar_dptos();
	L_Universidades.gravar_universidades();
}

void Principal::GravarAlunos()
{
	L_Alunos.gravar_alunos();
}

void Principal::GravarProfessores()
{
	L_Professores.gravar_professores();
}

void Principal::GravarUniversidades()
{
	L_Universidades.gravar_universidades();
}

void Principal::GravarDepartamentos()
{
	L_Departamentos.gravar_dptos();
}

void Principal::GravarDisciplinas()
{
	L_Disciplinas.gravar_disciplinas();
}

/*
void Principal::CadNotas()
{
}
*/

void Principal::RecuperarTudo()
{
	L_Alunos.recuperar_alunos();
	L_Professores.recuperar_professores();
	L_Universidades.recuperar_universidades();
	L_Departamentos.recuperar_dptos();
	L_Disciplinas.recuperar_disciplinas();

	cout << "Todos os arquivos foram recuperados" << endl;
}

void Principal::RecuperarAlunos()
{
	L_Alunos.recuperar_alunos();
	cout << "\nAlunos recuperados.\n" << endl;
}

void Principal::RecuperarProfessores()
{
	L_Professores.recuperar_professores();
	cout << "Professores recuperados." << endl;
}

void Principal::RecuperarUniversidades()
{
	L_Universidades.recuperar_universidades();
	cout << "Universidades recuperadas." << endl;
}

void Principal::RecuperarDepartamentos()
{
	L_Departamentos.recuperar_dptos();
	cout << "Departamentos recuperados." << endl;
}

void Principal::RecuperarDisciplinas()
{
	L_Disciplinas.recuperar_disciplinas();
	cout << "Disciplinas recuperadas." << endl;
}

//seria mais apropriado um retorno booleano no caso da gravação e recuperação
//assim, se nao fosse possível gravar/recuperar, a mensagem correta apareceria

