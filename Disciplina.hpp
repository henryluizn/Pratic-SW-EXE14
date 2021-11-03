#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include <string>
#include <list>

#include "Pessoa.hpp"
class SalaAula;//forward declaration
class ConteudoMinistrado;

class Disciplina{
	friend class SalaAula;
	public:
		Disciplina(std::string nome, SalaAula* sala);
		~Disciplina();

		std::string getNome() const;
		void setNome(const std::string nome);
		
		int getCargaHoraria() const;
		void setCargaHoraria(const unsigned int cargaHoraria);
		
		const Pessoa* getProfessor() const;
		void setProfessor(Pessoa* const professor);

		void adicionarAluno(Pessoa* const aluno);
		void removerAluno(Pessoa* const aluno);
		void removerAluno(unsigned long const cpf);
		const std::list<Pessoa*>& getAlunos() const;

		void setSalaAula(SalaAula* const sala);
		const SalaAula* getSalaAula() const;

		void imprimeDados(const std::string& cabecalho, const unsigned int& cargaTotalCurso) const;

		// novas implementacoes

		void adicionarConteudoMinistrado(const std::string conteudo, const unsigned short cargaHorariaConteudo);
		void imprimirConteudosMinistrados() const;
		const std::list<ConteudoMinistrado*> getConteudos() const;
		void limparConteudos();
		void removerConteudoMinistrado(unsigned long const id);

	private:
		std::string nome;
		unsigned short int cargaHoraria;

		const Pessoa* professor;
		SalaAula* sala;
		std::list<Pessoa*> alunos;
		// novas implementacoes
		std::list<ConteudoMinistrado*> conteudos;

};
#endif
