#include "funcoes_zorzal.h"

/* 
Para realizar as comparacoes usa-se a funcao strcmp da biblioteca <string.h>. Se ela retornar:
Um valor menor que zero: a primeira string é menor que a segunda
Um valor maior que zero: a primeira string é maior que a segunda
Retorna 0: as duas strings sao iguais
*/

int selecao(Tlista lista, int tam){
    
    int i, j, Min,k;
    TADPalavra aux;
    
    for (i = 0; i < (tam-1); i++ ){
        Min = i;
        for (j = i + 1; j < tam; j++)
            if (strcmp(lista.palavra[j].string_aloc, lista.palavra[Min].string_aloc) < 0){
            Min = j;
            } 
        aux = lista.palavra[Min];
        lista.palavra[Min] = lista.palavra[i];
        lista.palavra[i] = aux;
        
        /* Opcao usando strcpy:

        strcpy(aux.string_aloc,lista.palavra[Min].string_aloc);
        strcpy(lista.palavra[Min].string_aloc, lista.palavra[i].string_aloc);
        strcpy(lista.palavra[i].string_aloc,aux.string_aloc);
        */
    }
    
    //Parte que printa resultado da ordenacao na tela:
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n Lista ordenada por selecao \n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    for (k = 0; k< tam; k++){
        printf("%s\n",lista.palavra[k].string_aloc);
    }
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");
    return 0;

}

int insercao(Tlista lista, int tam){
  
    int i, j,k;
    TADPalavra aux;
    
    for (i = 1; i < tam; i++){
        aux = lista.palavra[i];
        j = i - 1;
        while((j >= 0) && ((strcmp(aux.string_aloc,lista.palavra[j].string_aloc)) < 0 )){
            lista.palavra[j + 1] = lista.palavra[j];
            j--;
        }
        lista.palavra[j+1] = aux;
    }

    //Parte que printa resultado da ordenacao na tela:
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n Lista ordenada por insercao \n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    for (k = 0; k< tam; k++){
        printf("%s\n",lista.palavra[k].string_aloc);
    }
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");
    return 0;
}

void Particao(int Esq, int Dir, int *i, int *j, Tlista *A){
    TADPalavra pivo, aux;
    *i = Esq; *j = Dir;
    pivo = A->palavra[(*i + *j)/2]; // obtem o pivo x 
    do{
        while (strcmp(pivo.string_aloc, A->palavra[*i].string_aloc) > 0) (*i)++;
        while (strcmp(pivo.string_aloc, A->palavra[*j].string_aloc) < 0) (*j)--;
        if (*i <= *j){
            aux = A->palavra[*i]; A->palavra[*i] = A->palavra[*j]; A->palavra[*j] = aux;
            (*i)++; (*j)--;
        }
    } while (*i <= *j);
}

void Ordena(int Esq, int Dir, Tlista *A){
    int i,j;
    Particao(Esq, Dir, &i, &j, A);
    if (Esq < j) Ordena(Esq, j, A);
    if (i < Dir) Ordena(i, Dir, A);
}

void Quick(Tlista* A, int n){
    Ordena(0, n-1, A);
}

int QuickSort(Tlista lista, int tam){
    
    int k;
    Quick(&lista,tam);
    
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n Lista ordenada por quicksort \n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    for (k = 0; k< tam; k++){
        printf("%s\n",lista.palavra[k].string_aloc);
    }
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");
    return 0;
}

void Refaz(int Esq, int Dir, Tlista *lista){
    int j = Esq * 2;
    TADPalavra aux = lista->palavra[Esq];
    while (j <= Dir){
        if ((j < Dir)&&(strcmp(lista->palavra[j].string_aloc,lista->palavra[j+1].string_aloc) < 0)) j++;
        if (strcmp(aux.string_aloc, lista->palavra[j].string_aloc) >= 0) break;
        lista->palavra[Esq] = lista->palavra[j];
        Esq = j; 
        j = Esq * 2 ;
        }
    lista->palavra[Esq] = aux;
}

void Constroi(Tlista *lista, int *n){
    int Esq;
    Esq = *n / 2 + 1;
    while (Esq > 1){
        Esq--;
        Refaz(Esq, *n, lista);
    }
}

void Heapsort(Tlista *lista, int *n){ 
    int Esq, Dir;
    TADPalavra aux;
    Constroi(lista, n); //constroi o heap 
    Esq = 1; Dir = *(n);
    while (Dir > 1)
    { //ordena o vetor 
        aux = lista->palavra[1];
        lista->palavra[1] = lista->palavra[Dir];
        lista->palavra[Dir] = aux;
        Dir--;
        Refaz(Esq, Dir, lista);
    }
}

int Chama_heapsort(Tlista lista_aux, int n){
    Tlista lista;
    int i= 0,k;
    for (i = 1; i <= n; i++){
        strcpy(lista.palavra[i].string_aloc, lista_aux.palavra[i-1].string_aloc);
    }
    Heapsort(&lista,&n);
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n Lista ordenada por heapsort \n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    for (k = 1; k <= n; k++){
        printf("%s\n",lista.palavra[k].string_aloc);
    }
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");
    return 0;
}
