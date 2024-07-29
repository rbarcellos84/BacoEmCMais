#include "Nome.hpp"
#include <iostream>

Nome::Nome(std::string nome)
{
    if (!nome.empty() && !nome.size() == 0)
        this->nome = nome;
    else
        this->nome = "";
}

//por boas praticas quando temos um metodo que não altera o valor de uma variavel utilizamos como const
//neste metodo não se faz necessario, pois só estou retornando o valor da minha variavel
//mas ja fica de comentario para o entendimento
std::string Nome::retornarNome() //const
{
    return this->nome;
}

bool Nome::validacao(std::string nome)
{
    if (nome.size() <= 5)
        return false;
    else
        return true;
}

std::string Nome::validarNome()
{
    if (!this->nome.empty() && !this->nome.size() == 0)
    {
        if (validacao(this->nome) == false)
            return "O nome deve ter mais de 5 carateres.";    
    }
    else
        return "Informe o nome do titular.";

    return "OK";
}