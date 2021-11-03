#include "ConteudoMinistrado.hpp"
#include <iostream>
// inicialização do dado static
unsigned int ConteudoMinistrado::proxId{0};

ConteudoMinistrado::~ConteudoMinistrado()
{
	std::cerr << "\nDestruindo o conteudo ministrado " << this->descricao << std::endl;
}

ConteudoMinistrado::ConteudoMinistrado(std::string descricao, unsigned short cargaHorariaConteudo):
	descricao(descricao), cargaHorariaConteudo(cargaHorariaConteudo), id{ConteudoMinistrado::proxId}
{
	ConteudoMinistrado::proxId++;
}

const std::string& ConteudoMinistrado::getDescricao(){
	return this->descricao;
}

const unsigned short ConteudoMinistrado::getCargaHorariaConteudo(){
	return cargaHorariaConteudo;
}

const unsigned int ConteudoMinistrado::getId(){
	return id;
}
