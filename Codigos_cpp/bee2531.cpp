#include <iostream>
#include <bits/stdc++.h>

// ! deu time limit exceded
 
using namespace std;
 
int main() {
    int N,i,j,aux;
    vector <int> vetor;
    cin >> N;
    for (i = 0; i < N; i++){
        aux;
        cin >> aux;
        vetor.push_back(aux);
    }
    cin >> aux;
    for (i = 0; i<aux; i++){
        int n,a,b;
        cin >> n >> a >> b;
        if (n == 1) vetor[a] = b;
        else if (n == 2){
            int min = vetor[0], max = vetor[0];
            for (j = a-1; j < b; j++){
                if (vetor[j] < min) min = vetor[j];
                if (vetor[j]> max) max = vetor[j];
                
            }
            cout << (max-min) << endl;
        }
    }
    return 0;
}
/**
 * * 1 i p (1 ≤ i ≤ N, 1 ≤ p ≤ 105), indicando que o preço do celular foi alterado para p na loja i.
 * * 2 i j (1 ≤ i ≤ j ≤ N), indicando uma consulta.
 */