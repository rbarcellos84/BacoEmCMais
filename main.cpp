#include <iostream>
#include <string>
#include "Titular.hpp"
#include "Conta.hpp"

//compilação
//g++ main.cpp -o main.out
//g++ *.cpp -o main.out
//executando
//./main.out

using namespace std;

int main()
{
    //tratar erros de cadastro
    string erro = "";
    Titular dados;

    //metodo pare capturar os dados do titular da conta (metodo generico)
    erro = dados.cadastrarTitular("928.132.530-65","Manuel");
    if (!erro.empty() && !erro.size() == 0)
    {
        cout << "Falha ao cadastrar o detalhe do titular da conta: " << erro << endl;
        exit(1);
    }

    Conta primeira;
    primeira.abrirConta(dados);
    primeira.depositar(100);

    erro = dados.cadastrarTitular("140.417.620-90","Joaquim");
    if (!erro.empty() && !erro.size() == 0)
    {
        cout << "Falha ao cadastrar o detalhe do titular da conta: " << erro << endl;
        exit(1);
    }

    Conta segunda;
    segunda.abrirConta(dados);
    segunda.depositar(200);

    erro = dados.cadastrarTitular("576.054.740-24","Matilde");
    if (!erro.empty() && !erro.size() == 0)
    {
        cout << "Falha ao cadastrar o detalhe do titular da conta: " << erro << endl;
        exit(1);
    }

    Conta terceira;
    terceira.abrirConta(dados);
    terceira.depositar(150);

    //movimentar valores da conta
    primeira.depositar(900);
    segunda.depositar(500);
    segunda.sacar(300);
    terceira.depositar(475);
    
    cout << endl << "Total de contas cadastradas " << Conta::retornarQuatidadesContas() << endl << endl;

    cout << "*************************** " << endl;
    primeira.imprimirDadosConta('S');
    cout << "*************************** " << endl << endl;

    cout << "*************************** " << endl;
    segunda.imprimirDadosConta('S');
    cout << "*************************** " << endl << endl;

    cout << "*************************** " << endl;
    terceira.imprimirDadosConta('S');
    cout << "*************************** " << endl << endl;

    return 0;
}


/*
    <<curiosidades>>
    alocação de memoria na Heap
    int* ponteiro = new int;
    é um pouco mais custudo, mas é recomendado para os casos que iremos trabalhar com mais de 2 megas de informação

    alocação de memoria na Stack
    Titular dados;
    é um pouco menos custudo, mas é recomendado para os casos que iremos trabalhar com menos de 2 megas de informação
*/