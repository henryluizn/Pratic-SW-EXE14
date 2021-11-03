#include "Disciplina.hpp"
#include "SalaAula.hpp"
#include "ConteudoMinistrado.hpp"

#include <iostream>

Disciplina::Disciplina(std::string nome, SalaAula *sala)
	: nome{nome}, sala{sala}
{
}

Disciplina::~Disciplina()
{
	std::cerr << "\nDestruindo disciplina " << this->nome << std::endl;
	this->setSalaAula(nullptr);
	std::list<ConteudoMinistrado *>::iterator it;
	for (it = conteudos.begin(); it != conteudos.end(); it++)
		delete *it; //liberando a memória de cada conteúdo
}

void Disciplina::adicionarAluno(Pessoa* const aluno)
{
	this->alunos.push_back(aluno);
}

void Disciplina::removerAluno(Pessoa* const aluno)
{
	this->alunos.remove(aluno);
}

void Disciplina::removerAluno(unsigned long const cpf)
{
	std::list<Pessoa *>::const_iterator it;

	for (it = this->alunos.begin(); it != this->alunos.end(); it++)
		if ((*it)->getCpf() == cpf)
			break;
	if (it != this->alunos.end())
		this->alunos.erase(it);
}

const std::list<Pessoa *>& Disciplina::getAlunos() const
{ //retornamos uma referência para a lista, o que custa mais barato
	return this->alunos;
}

std::string Disciplina::getNome() const
{
	return this->nome;
}

void Disciplina::setNome(const std::string nome)
{
	this->nome = nome;
}

int Disciplina::getCargaHoraria() const
{
	return this->cargaHoraria;
}

void Disciplina::setCargaHoraria(const unsigned int cargaHoraria)
{
	this->cargaHoraria = cargaHoraria;
}

const Pessoa *Disciplina::getProfessor() const
{
	return this->professor;
}

void Disciplina::setProfessor(Pessoa* const professor)
{
	this->professor = professor;
}

void Disciplina::setSalaAula(SalaAula* const sala)
{
	if (this->sala != nullptr)
	{
		this->sala->disciplinasMinistradas.remove(this);
	}
	this->sala = sala;
	if (this->sala != nullptr)
	{
		sala->disciplinasMinistradas.push_back(this);
	}
}

const SalaAula *Disciplina::getSalaAula() const
{
	return this->sala;
}

void Disciplina::imprimeDados(const std::string &cabecalho, const unsigned int &cargaTotalCurso) const
{
	double pctCurso = (double)cargaHoraria / cargaTotalCurso;
	pctCurso = pctCurso * 100;
	std::cout << cabecalho << std::endl;
	std::cout << "Disciplina: " << this->nome << std::endl;
	std::cout << "Carga: " << this->cargaHoraria << std::endl;
	std::cout << "Percentagem do curso: " << pctCurso << "%" << std::endl;
	std::cout << "Professor: " << this->professor->getNome() << std::endl;
}

// novas implementacoes

void Disciplina::adicionarConteudoMinistrado(const std::string conteudo, const unsigned short cargaHorariaConteudo)
{
	this->conteudos.push_back(new ConteudoMinistrado{conteudo, cargaHorariaConteudo});
}

void Disciplina::imprimirConteudosMinistrados() const
{
	std::list<ConteudoMinistrado *>::const_iterator it;
	for (it = this->conteudos.begin(); it != this->conteudos.end(); it++)
	{
		std::cout << "Id: " << (*it)->getId() << std::endl
				  << "Conteudo: " << (*it)->getDescricao() << std::endl
				  << "Carga: " << (*it)->getCargaHorariaConteudo() << std::endl
				  << std::endl;
	}
}

const std::list<ConteudoMinistrado *> Disciplina::getConteudos() const
{
	return this->conteudos;
}

void Disciplina::limparConteudos()
{
	std::list<ConteudoMinistrado *>::iterator it{this->conteudos.begin()};
	while (it != this->conteudos.end())
	{
		if ((*it) != nullptr)
		{
			delete *it;
			it = this->conteudos.erase(it);
			std::cout << "\nConteudo removido com sucesso" << std::endl;
		}
		else
		{
			it++;
		}
	}
	this->conteudos.clear();
}

void Disciplina::removerConteudoMinistrado(const unsigned long id)
{
	std::list<ConteudoMinistrado *>::iterator it;
	for (it = this->conteudos.begin(); it != this->conteudos.end(); it++)
	{
		if ((*it)->getId() == id)
		{
			std::cout << "\nRemovendo conteúdo " << (*it)->getDescricao() << "\n"
					  << std::endl;
			this->conteudos.remove((*it));
			break;
		}
	}
}