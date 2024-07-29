#pragma once
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include "Titular.hpp"

//arquivo de cabeçalho

//tudo dentro de uma struct é public
//tudo dentro de uma class é privado

class Conta
{
    //atributos
    private:
    std::string numero;
    std::string cpfTitular;
    std::string nomeTitular;
    float saldo;

    //atributo que compartilha com todos objetos criados pela classe conta
    public:
    static int numeroContas;
    static int numeroSequencial;

    public:
    //metodo contrutor
    Conta();
    //metodo destrutor
    ~Conta();

    //metodos de cadastro e atualizacao
    std::string alterarNomeConta(std::string nome);
    void abrirConta(Titular titular);
    void sacar(float valorASacar);
    void depositar(float valorADepositar);

    //metodos de impressão e retorno de valores
    std::string retornarNomeConta();
    std::string retornarNumeroConta();
    std::string retornarCpfConta(); //const;
    static int retornarQuatidadesContas();
    void imprimirDadosConta(char opcao);
    float retornarSaldo();

    //melhorias do programa
    private:
    std::string obterCodigoConta(int numeroContas);
    int obterNumeroConta();
};
