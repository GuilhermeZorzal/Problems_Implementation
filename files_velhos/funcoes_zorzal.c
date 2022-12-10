#include <stdio.h>

void f(int * vet[], int n){
    int vet2[n+3];
       for (int i = 0; i < n; i++) vet2[i] = vet[i];
}

int main(){
    int vet[3];
    for (int i = 0; i< 3; i++){
        vet[i] = i+3;
    }
    f(&vet[0],3);
    return 0;
}
