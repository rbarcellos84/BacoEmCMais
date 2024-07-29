#include "Titular.hpp"
#include <iostream>

Titular::Titular(){
    this->nomeTitular = "";
    this->cpfTitular = "";
}

std::string Titular::cadastrarTitular(std::string cpf, std::string nome)
{
    std::string validacao = "";
    Cpf documento(cpf);
    validacao = documento.validarCpf();
    if (validacao != "OK")
        return validacao;
    else
        this->cpfTitular = documento.retornarCpf();
    
    Nome nomeTitular(nome);
    validacao = nomeTitular.validarNome();
    if (validacao != "OK")
        return validacao;
    else
        this->nomeTitular = nomeTitular.retornarNome();
    
    return "";
}

std::string Titular::retornarNomeTitular()
{
    return this->nomeTitular;
}

//por boas praticas quando temos um metodo que não altera o valor de uma variavel utilizamos como const
//neste metodo não se faz necessario, pois só estou retornando o valor da minha variavel
//mas ja fica de comentario para o entendimento
std::string Titular::retornarCpfTitular() //const
{
    return this->cpfTitular;
}
