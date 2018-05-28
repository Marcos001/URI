//
// Created by nig on 28/05/18.
//

#ifndef URI_PROBLEM_1689_H
#define URI_PROBLEM_1689_H


class problem_1689 {

    struct combinacoes{
        int linha;
        int coluna;
        int beneficio;
    };


    std::vector <combinacoes> comb {};
public:
    void about();
    int distancia(int a, int b);
    int mochila_radares(int W, int wt[], int b[], int n);
};


#endif //URI_PROBLEM_1689_H
