//
// Created by nig on 28/05/18.
//

#ifndef URI_PROBLEM_1689_H
#define URI_PROBLEM_1689_H
#include <vector>

class problem_1689 {

    typedef struct Combinacoes{
        int linha;
        int coluna;
        int beneficio;
        int distancia;
    } Comb;

    std::vector<Comb> comb{};

public:
    void about();
    int distancia(int a, int b);
    int mochila_radares(int W, int wt[], int b[], int n);
    void ver_combinacoes();

    bool validar_entradas(int linha, int coluna);
};




#endif //URI_PROBLEM_1689_H
