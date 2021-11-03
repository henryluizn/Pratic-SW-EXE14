#include <iostream>
#include "Pessoa.hpp"
#include "Disciplina.hpp"
#include "ConteudoMinistrado.hpp"
#include "Console.hpp"
#include "SalaAula.hpp"

int main()
{
	std::cout << "\nOlhe o codigo do arquivo 'main.cpp'\n" << std::endl;
	Disciplina dis1{"C++", nullptr};
	Disciplina dis2{"Java", nullptr};
	Disciplina dis3{"Python", nullptr};
	SalaAula sala{"Lab Info 1", 40};
	Pessoa prof{"Joao"};

	dis1.setProfessor(&prof);

	dis1.setSalaAula(&sala);
	dis2.setSalaAula(&sala);
	
	// coletando a lista de disciplinas da sala1 e atribuindo em uma variável
	std::list<Disciplina *> disSala{sala.getDisciplinas()};
	// adicionando uma nova disciplina nessa lista
	disSala.push_back(&dis3);
	
	
	// imprimindo as disciplinas vinculadas ao objeto correspondente à sala de aula
	// podemos observar que mesmo adicionando a disciplina 3 na lista manualmente, 
	// ela não foi vinculada no objeto "sala" porque retorno da funcao "getDisciplinas()" é do tipo const
	std::list<Disciplina *>::const_iterator it;
	std::cout << "\nImprimindo as disciplinas da sala " << sala.getNome() << " : " << std::endl;
		for (it = sala.getDisciplinas().begin(); it != sala.getDisciplinas().end(); it++)
		std::cout << "\t - " << (*it)->getNome() << std::endl;
	
	std::cout << "\nFim do Programa" << std::endl;
	
	return 0;
}