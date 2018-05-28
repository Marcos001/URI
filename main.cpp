#include <iostream>
using namespace std;
#include "problem_1689.h"


int knapsack(int W, int wt[], int b[], int n)
{
// tabela que será preenchida
    int V[n + 1][W + 1];
// inicializando a primeira linha e primeira coluna com 0
    for(int w = 0; w <= W; w++)
        V[0][w] = 0;
    for(int i = 1; i <= n; i++)
        V[i][0] = 0;

    for(int i = n; i >= 1; i--)
    {
        for(int w = W; w >=1; w--)
        {
            // elemento pode fazer parte da solução
            if(wt[i - 1] <= w)
            {
                //cout << " b[i-1] " << b[i-1] << " + V[i-1][w-wt[i-1]] " << V[i-1][w-wt[i-1]] << " > " <<  V[i-1][w] << endl;
                if(( b[i-1] + V[i-1][w-wt[i-1]] ) >  V[i-1][w]){
                    V[i][w] = b[i - 1] + V[i - 1][w - wt[i - 1]];
                    cout << "V[i][w] " << V[i][w] << " = b[i - 1]" <<  b[i - 1] << " + V[i - 1][w - wt[i - 1]] " << V[i - 1][w - wt[i - 1]] << endl;
                }
                else{
                    V[i][w] = V[i - 1][w];
                }


            }
            else
                V[i][w] = V[i - 1][w]; // wi > w

        }
    }
// retorna o valor máximo colocado na mochila
    return V[n][W];
}

// ENTRADA
// 3
// 2 1
// 1 1
// 3 2
// 3 2
// 1 2 3
// 2 5 3
// 5 5
// 1 5 10 15 17
// 5 20 10 15 25


//  SAIDA
//  3
//  5
//  55

// W    - tamanho da minha capacidade
// n    - numero de elementos
// wt[] - vetor de pontos
// b[]  - vetor de beneficios




void entrada(){


//    int W = 5; // capacidade máxima da mochila: W
//
//    int n = 5; // número de elementos
//
//    int b[] = {5,20,10,15,25}; // vetor com os valores (benefício) de cada elemento
//
//    int wt[] = {1,5,10,15,17}; // vetor com os pesos de cada elemento


    int W = 2; // capacidade máxima da mochila: W

    int n = 3; // número de elementos

    int b[] = {2,5,3};  // vetor com os valores (benefício) de cada elemento

    int wt[] = {1,2,3}; // vetor com os pesos de cada elemento

    int max_valor = knapsack(W, wt, b, n); // obtém o máximo valor que pode ser colocado na mochila
    cout << "Valor maximo: " << max_valor << endl;
}

void entrada_de_classe(){

    problem_1689 *mochila;
    mochila = new problem_1689;
    mochila->about();


//    int W = 2; // capacidade máxima da mochila: W
//
//    int n = 3; // número de elementos
//
//    int b[] = {2,5,3};  // vetor com os valores (benefício) de cada elemento
//
//    int pontos[] = {1,2,3}; // vetor com os pesos de cada elemento


    int W = 5; // limite de distancia

    int n = 5; // número de elementos

    int b[] = {5,20,10,15,25}; // vetor com os valores (benefício) de cada elemento

    int pontos[] = {1,5,10,15,17}; // vetor com os pesos de cada elemento


    mochila->mochila_radares(W, pontos, b, n);
}

int main(int argc, char *argv[])
{

    //entrada();
    entrada_de_classe();

    return 0;
}