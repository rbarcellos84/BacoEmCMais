#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class Cpf
{
    private:
    std::string cpf;

    public:
    explicit Cpf(std::string numero);
    std::string retornarCpf(); //const;
    std::string validarCpf();

    private:
    bool validacao(std::string cpf);
};