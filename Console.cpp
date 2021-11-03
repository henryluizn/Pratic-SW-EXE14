#include "Console.hpp"
#include "ConteudoMinistrado.hpp"
#include <iostream>

Console::~Console()
{
	std::cerr << "\nDestruindo a classe Console" << std::endl;
}


void Console::imprimirDadosDisciplina(const Disciplina& disciplina){
	std::cout << "Disicplina: "<< disciplina.getNome() << std::endl;
	if(disciplina.getProfessor() != nullptr)
		std::cout << "Professor: " << disciplina.getProfessor()->getNome() << std::endl;
	else
		std::cout << "Sem professor" << std::endl;

	std::cout << "Conteudos Ministrados\n" << std::endl;

        disciplina.imprimirConteudosMinistrados();

}

