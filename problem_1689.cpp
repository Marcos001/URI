//
// Created by nig on 28/05/18.
//

#include <iostream>
#include <vector>
#include "problem_1689.h"

using namespace std;


int problem_1689::distancia(int a, int b){
    if(a > b)
        return a - b;
    return b - a;
}

bool problem_1689::validar_entradas(int linha, int coluna){

    for(int i=0; i<comb.size(); i++){
        if((linha == comb[i].linha and coluna == comb[i].coluna) or (coluna == comb[i].linha and linha == comb[i].coluna)){
            //cout << " Valores ja possuem ";
            //cout << linha << ":" << coluna <<" => linha = " << comb[i].linha << " coluna = " << comb[i].coluna << endl;
            return false;
        }
    }

    return true;
}

void problem_1689::ver_combinacoes(){
    cout << "\n Vendo as Combinacoes \n";
    for(int i=0; i<comb.size(); i++){
        cout << i <<" :[" << comb[i].linha << "] [" << comb[i].coluna << "] = beneficio[" << comb[i].beneficio << "] distancia[" <<comb[i].distancia << "]" << endl;
    }
}


int problem_1689::mochila_radares(int W, int pontos[], int b[], int n)
{

     int soma = 0;

     int indice = 0;

     ver_combinacoes();

    for(int i=0;i<n;i++){
        for(int j =0;j<W;j++){

            if(i!=j){
                int x = pontos[i];
                int y = pontos[j];
                if(distancia(x,y) >=  W){
                    //cout << "Candidato com distncia "<< a <<"  " << b << " " << distancia(pontos[i], pontos[j]) << endl;
                    // empilhar as combinacoes de distancia
                    if(validar_entradas(i,j)){
                        comb.emplace_back();
                        comb[indice].linha = i;
                        comb[indice].coluna = j;
                        comb[indice].beneficio = b[i] + b[j];
                        comb[indice].distancia = distancia(x,y);
                        indice += 1;
                    }
                }
            }
        }
    }

    ver_combinacoes();

    return soma;
}

void problem_1689::about() {
    cout << " Calsse para resolver o problema da questão 1689" << endl;
}
