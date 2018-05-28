//
// Created by nig on 28/05/18.
//

#ifndef URI_UTIL_H
#define URI_UTIL_H
#include <iostream>
using namespace std;

class util {

    int numero;     // São atributos
    string nome;    // privados por
    float saldo;    // default

public:
    void inicializa(string n, float s);
    void deposita(float valor);
    void consulta();
    int saque(float valor);
protected:
private:

};


#endif //URI_UTIL_H
