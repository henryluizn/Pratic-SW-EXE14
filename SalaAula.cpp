#include "SalaAula.hpp"
#include <iostream>

SalaAula::SalaAula(std::string nome, unsigned int capacidade)
	:nome{nome}, capacidade{capacidade}{
}



SalaAula::~SalaAula()
{
	std::cerr << "\nDestruindo a sala " << this->nome << std::endl;

	std::list<Disciplina *>::iterator it{this->disciplinasMinistradas.begin()};
	for ( ; it != this->disciplinasMinistradas.end(); it++)
	{
		if ((*it)->sala != nullptr)
		{
			// setando a sala da disciplina como nullptr
			(*it)->sala = nullptr;
		}
	}
	this->disciplinasMinistradas.clear();
}


std::string SalaAula::getNome() const {
	return this->nome;
}

void SalaAula::setNome(const std::string nome){
	this->nome = nome;
}

unsigned int SalaAula::getCapacidade() const {
	return capacidade;
}

void SalaAula::setCapcidade(const unsigned int capacidade){
	this->capacidade = capacidade;
}

void SalaAula::adicionarDisciplina(Disciplina* const disciplina){
	if (disciplina->sala != nullptr)
	{
		disciplina->sala->disciplinasMinistradas.remove(disciplina);
		this->disciplinasMinistradas.push_back(disciplina);
		disciplina->sala = this;
	}
	else
	{
		this->disciplinasMinistradas.push_back(disciplina);
		disciplina->sala = this;
	}
}


const std::list<Disciplina*>& SalaAula::getDisciplinas() const {
	return this->disciplinasMinistradas;
}


SalaAula* SalaAula::getSalaAtual()
{
	return this;
}