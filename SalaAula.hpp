#ifndef SALA_AULA_H
#define SALA_AULA_H

#include <string>
#include <list>
#include "Disciplina.hpp"

class SalaAula{
	friend class Disciplina;
	public:
		SalaAula(std::string nome, unsigned int capacidade);
		~SalaAula();
		
		std::string getNome() const;
		void setNome(const std::string nome);

		unsigned int getCapacidade() const;
		void setCapcidade(const unsigned int capacidade);

		void adicionarDisciplina(Disciplina* const disciplina);
		const std::list<Disciplina*>& getDisciplinas() const;

		SalaAula* getSalaAtual();
	private:
		std::string nome;
		unsigned int capacidade;
		std::list<Disciplina*> disciplinasMinistradas;
};
#endif
