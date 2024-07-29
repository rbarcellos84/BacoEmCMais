#include "Cpf.hpp"
#include <iostream>

Cpf::Cpf(std::string numero)
{
    if (!numero.empty() && !numero.size() == 0)
        this->cpf = numero;
    else
        this->cpf = "";
}

//por boas praticas quando temos um metodo que não altera o valor de uma variavel utilizamos como const
//neste metodo não se faz necessario, pois só estou retornando o valor da minha variavel
//mas ja fica de comentario para o entendimento
std::string Cpf::retornarCpf() //const
{
    return this->cpf;
}

bool Cpf::validacao(std::string cpf)
{
    std::string novaString;
    for (char c : cpf)
    {
        if (std::isdigit(c))
        {
            novaString += c;
        }
    }

    if (novaString.size() != 11)
        return false;

    std::vector<int> digitos;
    for (char c : novaString)
    {
        digitos.push_back(c - '0');
    }

    int somaPrimeiroDV = 0;
    for (int i = 0; i < 9; ++i)
    {
        somaPrimeiroDV += digitos[i] * (10 - i);
    }

    int primeiroDV = 11 - (somaPrimeiroDV % 11);
    if (primeiroDV >= 10)
        primeiroDV = 0;

    int somaSegundoDV = 0;
    for (int i = 0; i < 10; ++i)
    {
        somaSegundoDV += digitos[i] * (11 - i);
    }

    int segundoDV = 11 - (somaSegundoDV % 11);
    if (segundoDV >= 10)
        segundoDV = 0;

    if (digitos[9] != primeiroDV || digitos[10] != segundoDV)
    {
        return false;
    }

    return true;
}

std::string Cpf::validarCpf()
{
    if (!this->cpf.empty() && !this->cpf.size() == 0)
    {
        if (validacao(this->cpf) == false)
            return "O CPF e invalido.";    
    }
    else
        return "Informe o CPF da conta.";

    return "OK";
}