#pragma once
#include <string>
#include "Cpf.hpp"
#include "Nome.hpp"

class Titular
{
    private:
    std::string cpfTitular;
    std::string nomeTitular;

    public:
    Titular();
    std::string cadastrarTitular(std::string cpf, std::string nome);
    std::string retornarNomeTitular();
    std::string retornarCpfTitular(); //const;
};