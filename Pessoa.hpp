#ifndef PESSOA_H
#define PESSOA_H

#include<string>

class Pessoa{
	public:
		Pessoa();
		Pessoa(std::string nome);
		Pessoa(std::string nome, unsigned short int idade);
		Pessoa(std::string nome, unsigned long cpf, unsigned short int idade);
		~Pessoa();

		unsigned long getCpf() const;
		bool setCpf(const unsigned long cpf);

		std::string getNome() const ;
		void setNome(const std::string nome);

		unsigned short int getIdade() const;
		void setIdade(const unsigned short int idade);

		void imprimirEnderecoMemoria() const ;
	private:
		bool validarCPF(const unsigned long cpf);

		std::string nome;
		unsigned long cpf;
		unsigned char idade;
};
#endif
