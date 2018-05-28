#include <iostream>
using namespace std;

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

int modulo(int a, int b){
    if(a > b)
        return a - b;
    return b - a;
}

int mochila_pt_br(int W, int wt[], int b[], int n)
{

        int soma = 0;
        int maior = 0;


        for(int i = 0; i < n; i++)
        {
            cout << wt[i] << " & " <<  wt[i-1] << "=" << modulo(wt[i], wt[i-1]) << endl;

            // preparar melhor as combinacoes

            if (modulo(wt[i], wt[i-1]) >= W){
                cout << "pontos validos" << wt[i] << " - " <<  wt[i-1] << "=" << modulo(wt[i], wt[i-1]) << " >= " << b[i] + b[i-1]  << endl;
                soma += b[i] + b[i-1];
            }

    }
    // retorna o valor máximo colocado na mochila - V[n][W]
    return soma;
}

int mochila_br_combinations(int W, int wt[], int b[], int n)
{

    int soma = 0;
    int maior = 0;


    for(int i = 0; i < n; i++)
    {
        cout << wt[i] << " & " <<  wt[i-1] << "=" << modulo(wt[i], wt[i-1]) << endl;

        // preparar melhor as combinacoes

        if (modulo(wt[i], wt[i-1]) >= W){
            cout << "pontos validos" << wt[i] << " - " <<  wt[i-1] << "=" << modulo(wt[i], wt[i-1]) << " >= " << b[i] + b[i-1]  << endl;
            soma += b[i] + b[i-1];
        }

    }
    // retorna o valor máximo colocado na mochila - V[n][W]
    return soma;
}

void entrada(){

    //    // capacidade máxima da mochila: W
//    int W = 5;
//    // número de elementos
//    int n = 5;
//    // vetor com os valores (benefício) de cada elemento
//    int b[] = {5,20,10,15,25};
//    // vetor com os pesos de cada elemento
//    int wt[] = {1,5,10,15,17};

    // capacidade máxima da mochila: W
    int W = 2;
    // número de elementos
    int n = 3;
    // vetor com os valores (benefício) de cada elemento
    int b[] = {2,5,3};
    // vetor com os pesos de cada elemento
    int wt[] = {1,2,3};

    // obtém o máximo valor que pode ser colocado na mochila
    int max_valor = mochila_pt_br(W, wt, b, n);
    cout << "Valor maximo: " << max_valor << endl;
}

int main(int argc, char *argv[])
{


    entrada();

    return 0;
}