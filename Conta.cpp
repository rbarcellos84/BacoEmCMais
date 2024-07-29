#include "Conta.hpp"
#include <iostream>

int Conta::numeroContas = 0;
int Conta::numeroSequencial = 0;

Conta::Conta()
{
    this->saldo = 0.0;
    this->numeroContas++;
    this->numeroSequencial++;
    this->nomeTitular = "";
    this->cpfTitular = "";
    this->numero = obterCodigoConta(numeroSequencial);
}

Conta::~Conta()
{
    this->numeroContas--;
}

void Conta::abrirConta(Titular titular)
{
    this->cpfTitular = titular.retornarCpfTitular();
    this->nomeTitular = titular.retornarNomeTitular();
}

std::string Conta::alterarNomeConta(std::string nome)
{
    if (!nome.empty() && !nome.size() == 0)
        this->nomeTitular = nome;
    else
        return "Informe o nome do titular";
}

void Conta::sacar(float valorASacar)
{
    if (valorASacar < 0) 
    {
        std::cout << "Não pode sacar valor negativo" << std::endl;
        return;
    }
        
    if (valorASacar > saldo) 
    {
        std::cout << "Saldo insuficiente" << std::endl;
        return;
    }
        
    this->saldo -= valorASacar;
}

void Conta::depositar(float valorADepositar)
{
    if (valorADepositar < 0) 
    {
        std::cout << "Não pode sacar valor negativo" << std::endl;
        return;
    }

    this->saldo += valorADepositar;
}

float Conta::retornarSaldo()
{
    return this->saldo;
}

int Conta::retornarQuatidadesContas()
{
    return numeroContas;
}

std::string Conta::retornarNomeConta()
{
    return this->nomeTitular;
}

std::string Conta::retornarNumeroConta()
{
    return this->numero;
}

//por boas praticas quando temos um metodo que não altera o valor de uma variavel utilizamos como const
//neste metodo não se faz necessario, pois só estou retornando o valor da minha variavel
//mas ja fica de comentario para o entendimento
std::string Conta::retornarCpfConta() //const
{
    return this->cpfTitular;
}

void Conta::imprimirDadosConta(char opcao)
{
    std::cout << "Dados da conta: " << obterNumeroConta() << std::endl;
    std::cout << "Nome: " << retornarNomeConta() << std::endl;
    std::cout << "Numero da conta: " << retornarNumeroConta() << std::endl;
    std::cout << "CPF da conta: " << retornarCpfConta() << std::endl;

    if (opcao == 'S')
        std::cout << "Saldo: " << retornarSaldo() << std::endl;
}

std::string Conta::obterCodigoConta(int numeroContas)
{
    std::stringstream ss;
    ss << std::setw(7) << std::setfill('0') << numeroContas;
    return ss.str();
}

int Conta::obterNumeroConta()
{
    return stoi(retornarNumeroConta());
}
