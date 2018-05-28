//
// Created by nig on 28/05/18.
//

#include "util.h"


void util::inicializa(string n, float s)
{
    nome = n;
    saldo = s;
    if (saldo < 0)
        cout << "Erro na Criação da Conta!!!" << endl;
}

void util::deposita(float valor)
{
    saldo = saldo + valor;
}

void util::consulta()
{
    cout << "Cliente: " << nome << endl;
    cout << "Saldo Atual: " << saldo << endl;
    cout << "Numero da Conta: " << numero << endl;
}

int util::saque(float valor)
{
    if (saldo < valor)
        return 0;
    else
    {
        saldo = saldo - valor;
        return 1;
    }
}
