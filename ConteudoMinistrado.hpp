#ifndef CONTEUDO_MINISTRADO_HPP
#define CONTEUDO_MINISTRADO_HPP

#include<string>

class ConteudoMinistrado{
	public:
		ConteudoMinistrado(std::string descricao, unsigned short cargaHorariaConteudo);
		~ConteudoMinistrado();

		const std::string& getDescricao();
		const unsigned short getCargaHorariaConteudo();
		const unsigned int getId();
	private:
		const std::string descricao;
		const unsigned short cargaHorariaConteudo;
		const unsigned int id;
		static unsigned int proxId;
};
#endif
