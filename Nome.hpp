#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class Nome
{
    private:
    std::string nome;

    public:
    explicit Nome(std::string nome);
    std::string retornarNome(); //const;
    std::string validarNome();

    private:
    bool validacao(std::string nome);
};